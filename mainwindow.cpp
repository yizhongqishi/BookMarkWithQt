#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <time.h>
#include <QTime>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QFileInfoList>
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include "categorymange.h"
#include <QDialog>
#include <QAxWidget>
#include <QAxObject>
#include <QRegExp>
#include "dialog.h"
#include <QObject>
#include "JlCompress.h"
#include <windows.h>
#include <QMenu>
#include <QWidget>
#include <QTreeWidget>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    this->setWindowFlags(Qt::FramelessWindowHint);
//    this->setWindowFlags(this->windowFlags() & ~Qt::WindowTitleHint);

    ui->setupUi(this);
    this->cli = false;
    ui->hh->hide();
    ui->widget_workspace->setAutoFillBackground(true);
    //默认最大化
    this->showMaximized();
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush());
    this->findPath = "./data/his/";
    QDir dd(this->findPath);
    if (!dd.exists()){
        dd.mkpath("./");
    }
    this->filePath = "";
    this->thespace = "&&&";
    this->catagoryPath = "./data/file/category.ini";
    QFileInfo file(this->catagoryPath);
    if (!file.exists()){
        file.dir().mkpath("./");
        QFile f(this->catagoryPath);
        f.open( QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
        f.close();
    }
    this->categoryTree = new QTreeWidgetItem();
    this->categoryTree->setText(0, QString::fromUtf8("全部类别"));
    QVariant var(0);
    this->categoryTree->setData(0, 32, var);
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel("");
    this->checkCate="";
    ui->treeWidget->addTopLevelItem(this->categoryTree);
    ui->createtime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    ui->updatetime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));

    QObject::connect(ui->searchword,SIGNAL(returnPressed()),this,SLOT(search()));

    this->getCategody();
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(checkFile(QTreeWidgetItem*)));
//    connect(ui->treeWidget,SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(treeWidget_customContextMenuRequested(const QPoint&)));

    QObject::connect(ui->searchresults, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(open(QTreeWidgetItem*)));

    QAction *action = new QAction(this);
    action->setShortcut(QKeySequence(tr("Ctrl+S")));
    //会导致按钮上有小三角
    ui->savefile->addAction(action);
    ui->savefile->setStyleSheet("QToolButton::menu-indicator{image:None;}");
    connect(action, SIGNAL(triggered()), this, SLOT(on_savefile_clicked()));

    ui->note->setAcceptRichText(false);
    this->noteChange = false;
    this->feelingChange = false;
    this->categoryChange = false;
    ui->searchresults->setColumnCount(2);
    QStringList list;
    list.append(QString::fromUtf8("笔记名称"));
    list.append(QString::fromUtf8("更新时间"));
    ui->searchresults->setHeaderLabels(list);
    this->item1 = NULL;
    this->hisca = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){

    /*QWidget::resizeEvent(event);
    QPalette pal(palette());
    QImage _image;
    _image.load(":/icon/2Max.png");
    pal.setBrush(QPalette::Window, QBrush(_image.scaled(event->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    ui->widget_workspace->setPalette(pal);
    */

    //设置工具栏按钮位置
    int w = event->size().width();
    QWidget* arrToolButtons[] = {ui->newfile,ui->savefile,ui->delfile,ui->importfile,ui->restorefile,ui->categorys,ui->toword};
    int ww = 0;
    int count = sizeof(arrToolButtons) / sizeof(arrToolButtons[0]);
    for(int i = 0; i < count; i++) {
        ww = ww + arrToolButtons[i]->width();
    }

    arrToolButtons[0]->move(w - ww, 0);
    for(int i = 1; i < count; i++) {
        arrToolButtons[i]->move(arrToolButtons[i-1]->x()+arrToolButtons[i-1]->width(), 0);
    }
}

void MainWindow::search(){
    QString text = ui->searchword->text();
    if (QString::compare(text, "") == 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("搜索内容不能为空"));
        return ;
    }
    QRegExp re;
    re.setPattern("^.*" + text + ".*$");
    re.setMinimal(true);
    if (ui->searchresults->topLevelItemCount() == 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("没有可供搜索的项"));
    }else{
        if (!this->cli){
            ui->searchresults->clear();
            int i = 0;
            foreach (QString temp, this->listtemp){
                QTreeWidgetItem* item = new QTreeWidgetItem();
                item->setText(0, temp);
                QFileInfo fileInfo(this->pathtemp.at(i));
                QVariant value = fileInfo.absolutePath() + "/";
                item->setText(1, fileInfo.lastModified().toString("yyyy/MM/dd"));
                //保存文件路径用于访问
                item->setData(0, 32, value);
                ui->searchresults->addTopLevelItem(item);
                i++;
            }
        }
        this->listtemp.clear();
        this->pathtemp.clear();
        QStringList li;
        QStringList pa;
        for (int i = 0; i < ui->searchresults->topLevelItemCount(); i++){
            this->listtemp.append(ui->searchresults->topLevelItem(i)->text(0));
            this->pathtemp.append(ui->searchresults->topLevelItem(i)->data(0, 32).toString() + ui->searchresults->topLevelItem(i)->text(0) + ".io");
            if (re.indexIn(ui->searchresults->topLevelItem(i)->text(0)) != -1){
                li.append(ui->searchresults->topLevelItem(i)->text(0));
                pa.append(ui->searchresults->topLevelItem(i)->data(0, 32).toString());
            }else{
                qDebug()<<ui->searchresults->topLevelItem(i)->data(0, 32).toString();
                QFile file(ui->searchresults->topLevelItem(i)->data(0, 32).toString() + ui->searchresults->topLevelItem(i)->text(0) + ".io");
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
                    //异常处理
                    QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("文件访问错误"));
                    return ;
                }
                while(!file.atEnd()){
                    QTextCodec* code = QTextCodec::codecForName("GB2312");
                    QString str = code->toUnicode(file.readLine());
                    if (re.indexIn(str) != -1){
                        li.append(ui->searchresults->topLevelItem(i)->text(0));
                        pa.append(ui->searchresults->topLevelItem(i)->data(0, 32).toString());
                    }
                    break;
                }
                file.close();
            }
        }
        ui->searchresults->clear();
        this->cli = false;
        int i = 0;
        foreach (QString l, li){
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0, l.split(".").at(0));
            QFileInfo fileInfo(this->pathtemp.at(i));
            QVariant value = pa.at(i);
            item->setText(1, fileInfo.lastModified().toString("yyyy/MM/dd"));
            //保存文件路径用于访问
            item->setData(0, 32, value);
            ui->searchresults->addTopLevelItem(item);
            i++;
        }
        if (i == 0){
            QMessageBox::warning(this, QString::fromUtf8("提示"), QString::fromUtf8("没有找到相关结果"));
        }
    }
}

void MainWindow::getCategody(){
    ui->categoryBox->clear();
    ui->categoryBox->update();
    this->scanCategory();
    foreach (QString k, this->categoryList) {
       ui->categoryBox->addItem(k);
    }
    this->categoryChange = false;

}
void MainWindow::scanCategory()
{
    QFile file(this->catagoryPath);
    this->numList.clear();
    this->categoryList.clear();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //异常处理
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("标签文件访问错误"));
        return ;
    }
    while(!file.atEnd()){
        QTextCodec* code = QTextCodec::codecForName("GB2312");
        QString str = code->toUnicode(file.readLine());
        //每行格式：category&&num
        QStringList list = str.split("&&");
        this->numList.append(list.at(1).trimmed());
        this->categoryList.append(list.at(0));
    }
    file.close();
    this->delCategory();
    int i = 0;
    foreach (QString num, this->categoryList){
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        item->setText(0, num);
        this->categoryTree->addChild(item);
        //针对编码进行目录的扫描，对于没有实体目录的编码创建目录
        QString ttz = this->findPath + this->numList.at(i) + "/";
        QDir dir(ttz);
        if (!dir.exists()){
            dir.mkpath("./");
        }
        i++;
    }
    QDir dir(this->findPath);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (QFileInfo info, folder_list){
        if (this->numList.indexOf(info.fileName()) == -1){
            this->removefile(info.absoluteFilePath());
        }
    }
    ui->treeWidget->expandAll();
}

void MainWindow::removefile(const QString &_Filename){
    QDir dir(_Filename);
    if (!dir.exists()){
        return ;
    }
    QFileInfoList file_list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    foreach (QFileInfo info, file_list) {
        info.dir().remove(info.fileName());
    }
    dir.rmpath(dir.absolutePath());
}
void MainWindow::delCategory(){
    int j = ui->treeWidget->topLevelItemCount();
    for (int i = j - 1; i >= 0; i--){
        ui->treeWidget->takeTopLevelItem(i);
    }
    delete(this->categoryTree);
    this->categoryTree = new QTreeWidgetItem();
    this->categoryTree->setText(0, QString::fromUtf8("全部类别"));
    QVariant var0(0);
    this->categoryTree->setData(0, 32, var0);
    ui->treeWidget->addTopLevelItem(this->categoryTree);
}

void MainWindow::checkFile(QTreeWidgetItem* item){
    //接下来需要恢复删除笔记后的记录
    //屏蔽右键
    this->checkDir = item;
    this->delFile = NULL;

//    ui->searchword->setText("");
    if (ui->hh->isHidden()){
        ui->searchword->setText("");
        ui->hh->show();
    }
    this->cli = true;
    int i = this->categoryList.indexOf(item->text(0));
    QString name;
    QString cate;
    //    判断是不是点击的全部类别
    if (i != -1){
        cate = this->categoryList.at(i);
        name = this->numList.at(i);
    }else{
        cate = "";
        name = "";
    }
    this->checkCate = cate;
    QDir dir(this->findPath + name);
    if (!dir.exists()){
        dir.mkpath("./");
    }
    ui->searchresults->clear();
    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0, QString::fromUtf8("笔记名称"));
    item1->setText(1, QString::fromUtf8("更改时间"));
    ui->searchresults->setHeaderItem(item1);
    ui->searchresults->setColumnWidth(0, 200);
    QFileInfoList file_list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    //将所有展示出来的文件保存用于打开
    foreach (QFileInfo info , file_list){
        //点击的为全部类别，需要对于文件夹进行迭代遍历
        if (info.isDir()){
            QDir kk(info.absoluteFilePath());
            QFileInfoList _file_list = kk.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
            foreach (QFileInfo ii, _file_list) {
                this->updatelist(ii);
            }
        }else{
            this->updatelist(info);
        }
    }
}

void MainWindow::updatelist(QFileInfo info){
    //将所有展示出来的文件保存用于打开


    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, info.fileName().split(".").at(0));
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    info.lastModified().toString("yyyy/MM/dd");
    QVariant value = info.absolutePath() + '/';
    item->setText(1, info.lastModified().toString("yyyy/MM/dd"));
    //保存文件路径用于访问
    item->setData(0, 32, value);
    ui->searchresults->addTopLevelItem(item);
    ui->searchresults->sortByColumn(1, Qt::AscendingOrder);
    ui->searchresults->setSortingEnabled(true);
}



void MainWindow::on_savefile_clicked()
{
    int k  = this->save();
    if (k == 0) {
        this->checktt();
    }
}

void MainWindow::checktt(){
    QString path = this->findPath;
    if (this->categoryList.indexOf(this->checkCate) == -1){
        this->checkCate = "";
    }
    if (QString::compare(this->checkCate, "") != 0){
        path += this->numList.at(this->categoryList.indexOf(this->checkCate)) + "/";
    }
    QDir dir(path);
    if (!dir.exists()){
        dir.mkpath("./");
    }
    ui->searchresults->clear();
    QFileInfoList file_list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    //将所有展示出来的文件保存用于打开
    foreach (QFileInfo info , file_list){
        //点击的为全部类别，需要对于文件夹进行迭代遍历
        if (info.isDir()){
            QDir kk(info.absoluteFilePath());
            QFileInfoList _file_list = kk.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
            foreach (QFileInfo ii, _file_list) {
                this->updatelist(ii);
            }
        }else{
            this->updatelist(info);
        }
    }
}
int MainWindow::save(){
    QString nn = ui->nameEd->text().remove(QRegExp("\\s"));
    if (QString::compare(nn,"") == 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("书名不能为空或只包含空格！"));
        return 1;
    }else{
        if (nn.length() > 16){
            QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称长度不能超过16！"));
            return 1;
        }
        QString pattern("[\\\\/:*?\"<>]");
        QRegExp rx(pattern);
        int match = nn.indexOf(rx);
        if(match >= 0){
            QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称包含非法字符！"));
            return 1;
        }
        if (!(ui->nameEd->isModified() || ui->author->isModified() || this->noteChange || ui->madetime->isModified() || ui->place->isModified() || this->feelingChange || this->categoryChange)){
            QMessageBox::warning(this, QString::fromUtf8("提示"), QString::fromUtf8("并没有产生修改"));
            return 1;
        }
        //note发生修改
//        if (this->noteChange){
//            QStringList temp = ui->note->toPlainText().split("------");
//            QString note;
//            if (temp.length() > 2) {
//                note = temp.at(2);
//            }else{
//                note = temp.at(0);
//            }
//            if (note.at(0) == '\n'){
//                note = note.mid(1, note.length());
//            }
//            ui->note->clear();
//            ui->note->append(QString::fromUtf8("------修改于:") + QDateTime::currentDateTime().toString("yyyy/MM/dd") + "------\n" + note);
//            this->noteChange = false;
//        }
        if (this->noteChange){
            this->noteChange = false;
        }
//        if (this->feelingChange){
//        //feeling发生修改
//            QStringList temp = ui->feeling->toPlainText().split("------");
//            QString feeling;
//            if (temp.length() > 2) {
//                feeling = temp.at(2);
//            }else{
//                feeling = temp.at(0);
//            }
//            if (feeling.at(0) == '\n'){
//                feeling = feeling.mid(1, feeling.length());
//            }
//            ui->feeling->clear();
//            ui->feeling->append(QString::fromUtf8("------修改于:")+ QDateTime::currentDateTime().toString("yyyy/MM/dd") + "------\n" + feeling);
//            this->feelingChange = false;
//        }
        if (this->feelingChange){
            this->feelingChange = false;
        }
        QString cate = ui->categoryBox->currentText();
        this->checkCate = cate;
        //新建文件路径
        if(QString::compare(this->filePath, "") == 0){
            this->filePath = this->findPath + this->numList.at(this->categoryList.indexOf(cate)) + "/" + nn + ".io";
            QFile file(this->filePath);
            if (file.exists()){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("存在同名笔记，继续保存会覆盖原笔记内容，是否继续？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                if (reply == QMessageBox::No){
                    this->filePath = "";
                    return 1;
                }
            }
        }else{
            if(QString::compare(this->category, this->checkCate) != 0){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("类别发生改变，将在新选择的类别下保存文件,否则停止保存"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                if (reply == QMessageBox::No){
                    return 1;
                }else{
                    this->removefile1(this->filePath);
                    this->filePath = this->findPath + this->numList.at(this->categoryList.indexOf(cate)) + "/" + nn + ".io";
                }
            }
            if (QString::compare(nn, this->bookname) != 0){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("书名发生改变，将以新的书名保存文件,否则停止保存"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                if (reply == QMessageBox::No){
                    return 1;
                }else{
                    this->filePath = this->findPath + this->numList.at(this->categoryList.indexOf(cate)) + "/" + nn + ".io";
                }
            }
            }
        QFileInfo fileinfo(this->filePath);
        if (!fileinfo.exists()){
            fileinfo.dir().mkpath("./");
            }
        QFile f(this->filePath);
        if(f.open( QIODevice::ReadWrite |QIODevice::Truncate| QIODevice::Text )){
            ui->updatetime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
            QString thesave =  ui->createtime->text() + this->thespace + ui->updatetime->text() + this->thespace  +
                    nn + this->thespace + ui->categoryBox->currentText() + this->thespace + ui->note->toPlainText() +
                    this->thespace + ui->feeling->toPlainText() + this->thespace + ui->author->text() + this->thespace +
                    ui->place->text() + this->thespace + ui->madetime->text();
            QTextStream txtOutput(&f);
            txtOutput<<thesave;
            f.close();
            this->category = cate;
            this->bookname = nn;
            this->noteChange = false;
            this->feelingChange = false;
            ui->nameEd->setModified(false);
            ui->author->setModified(false);
            ui->place->setModified(false);
            ui->madetime->setModified(false);
            this->categoryChange = false;
            QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("保存成功"));
            return 0;
        }else{
            QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("保存失败"));
            return 1;
        }
    }
}

void MainWindow::open(QTreeWidgetItem* item){
    if (ui->nameEd->isModified() || ui->author->isModified() || this->noteChange || ui->madetime->isModified() || ui->place->isModified() || this->feelingChange || this->categoryChange){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(NULL, QString::fromUtf8("警告"), QString::fromUtf8("是否保存现有操作？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (reply == QMessageBox::Yes){
            int k = this->save();
            if (k == 1){
                return ;
            }
        }
    }
    this->delFile = item;
    QString file_name = item->text(0);
    QString path = item->data(0, 32).toString();
    this->filePath = path + file_name + ".io";
    QFile file(this->filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("没有找到笔记！"));
        //异常处理
    }
    while(!file.atEnd()){
        QTextCodec* code = QTextCodec::codecForName("GB2312");
        QString str = code->toUnicode(file.readAll());
        //每行格式：category&&num
        QStringList list = str.split(this->thespace);
        this->updatezzz(list);
        break;
    }
    file.close();
}

void MainWindow::updatezzz(QStringList kk){
    ui->createtime->setText(kk.at(0));
    ui->updatetime->setText(kk.at(1));
    this->bookname = kk.at(2);
    this->category = kk.at(3);
    ui->nameEd->setText(this->bookname);
    ui->categoryBox->setCurrentIndex(ui->categoryBox->findText(this->category));
    ui->note->setText(kk.at(4));
    ui->feeling->setText(kk.at(5));
    ui->author->setText(kk.at(6));
    ui->place->setText(kk.at(7));
    ui->madetime->setText(kk.at(8));
    ui->nameEd->setModified(false);
    ui->author->setModified(false);
    this->noteChange = false;
    ui->madetime->setModified(false);
    ui->place->setModified(false);
    this->feelingChange = false;
    this->categoryChange = false;
    this->noteChange = false;
}

void MainWindow::on_delfile_clicked()
{
    if (this->delFile == NULL){
        QMessageBox::warning(this, QString::fromUtf8("错误"),QString::fromUtf8("没有选中要删除的笔记！"));
        return ;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(NULL, QString::fromUtf8("警告"), QString::fromUtf8("是否删除选中笔记？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::No){
        return ;
    }
    //删除选中笔记
    this->removefile1(this->delFile->data(0, 32).toString());
    this->checkfff();
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("删除笔记成功！"));
    ui->createtime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    ui->updatetime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    ui->nameEd->clear();
//    ui->categoryBox->setCurrentIndex(0);
    ui->categoryBox->setCurrentIndex(this->categoryList.indexOf(this->checkCate));
    ui->note->clear();
    ui->feeling->clear();
    ui->author->clear();
    ui->place->clear();
    ui->madetime->clear();
    ui->nameEd->setModified(false);
    ui->author->setModified(false);
    this->noteChange = false;
    ui->madetime->setModified(false);
    ui->place->setModified(false);
    this->feelingChange = false;
    this->categoryChange = false;
    this->noteChange = false;
    this->filePath = "";
    this->bookname = "";
    this->delFile = NULL;
}

void MainWindow::checkfff(){
    QTreeWidgetItem* item = this->checkDir;
    this->delFile = NULL;
    ui->searchword->setText("");
    if (ui->hh->isHidden()){
        ui->hh->show();
    }
    this->cli = true;
    int i = this->categoryList.indexOf(item->text(0));
    QString name;
    QString cate;
    //    判断是不是点击的全部类别
    if (i != -1){
        name = this->numList.at(i);
        cate = this->categoryList.at(i);
    }else{
        name = "";
        cate = "";
    }
    this->checkCate = cate;
    ui->treeWidget->setCurrentItem(item);
    QDir dir(this->findPath + name);
    if (!dir.exists()){
        dir.mkpath("./");
    }
    ui->searchresults->clear();
    QFileInfoList file_list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    //将所有展示出来的文件保存用于打开s
    foreach (QFileInfo info , file_list){
        //点击的为全部类别，需要对于文件夹进行迭代遍历
        if (info.isDir()){
            QDir kk(info.absoluteFilePath());
            QFileInfoList _file_list = kk.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
            foreach (QFileInfo ii, _file_list) {
                this->updatelist(ii);
            }
        }else{
            this->updatelist(info);
        }
    }
}

void MainWindow::removefile1(const QString &_Filename){
    QFileInfo info(_Filename);
    if (!info.exists()){
        QMessageBox::warning(this, "错误", "找不到该文件");
        return ;
    }
    QFile::remove(_Filename);
}


void MainWindow::on_importfile_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(NULL, QString::fromUtf8("警告"), QString::fromUtf8("该操作将覆盖原有数据，是否继续？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::Yes){
            QString file_name = QFileDialog::getOpenFileName(this, QString::fromUtf8("导入数据"), ".", "ZIP files(*.zip)");
            if (QString::compare(file_name, "") == 0) return;
            QDir dir("./data/");
            if (!dir.exists()){
                dir.mkpath("./");
            }
            JlCompress::extractDir(file_name, "./data/");
            this->getCategody();
            ui->createtime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
            ui->updatetime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
            ui->nameEd->clear();
            ui->categoryBox->setCurrentIndex(0);
            ui->note->clear();
            ui->feeling->clear();
            ui->author->clear();
            ui->place->clear();
            ui->madetime->clear();
            ui->nameEd->setModified(false);
            ui->author->setModified(false);
            this->noteChange = false;
            ui->madetime->setModified(false);
            ui->place->setModified(false);
            this->feelingChange = false;
            this->categoryChange = false;
            this->filePath = "";
            this->bookname = "";
            this->delFile = NULL;
            QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("文件导入成功"));
    }
}

void MainWindow::on_categorys_clicked()
{
    categorymange mange;
    if(mange.exec()==QDialog::Accepted){
        this->getCategody();
        this->checktt();
    }
}

void MainWindow::on_restorefile_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(NULL, QString::fromUtf8("提示"), QString::fromUtf8("该操作将导出所有有数据，是否继续？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::Yes){
            QString file_name = QFileDialog::getSaveFileName(this, QString::fromUtf8("导出数据"), ".", "ZIP files(*.zip)");
            if (QString::compare(file_name, "") == 0) return;
            JlCompress::compressDir(file_name, "./data/", true);
            QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("文件导出成功"));
    }
}

void MainWindow::on_toword_clicked()
{
    QList<WordItem> lsWordItem;
    lsWordItem.append(WordItem("BM_shuming", ui->nameEd->text()));
    lsWordItem.append(WordItem("BM_leixing", ui->categoryBox->currentText()));
    lsWordItem.append(WordItem("BM_zuozhe", ui->author->text()));
    lsWordItem.append(WordItem("BM_chubanshijian", ui->madetime->text()));
    lsWordItem.append(WordItem("BM_chubanshe", ui->place->text()));
    lsWordItem.append(WordItem("BM_chuangjianshijian", ui->createtime->text()));
    lsWordItem.append(WordItem("BM_gengxinshijian", ui->updatetime->text()));
    lsWordItem.append(WordItem("BM_zhaiji", ui->note->toPlainText()));
    lsWordItem.append(WordItem("BM_pingzhu", ui->feeling->toPlainText()));
    lsWordItem.append(WordItem("BM_name", ui->nameEd->text()));


    QString strWordTemplete = qApp->applicationDirPath()+"/bijimuban.doc";
    if(!QFile::exists(strWordTemplete)) {
        QMessageBox::information(0,"",QString::fromLocal8Bit("模板文件不存在！"));
        return;
    }
    exportToWord(lsWordItem,strWordTemplete);
}

void MainWindow::on_newfile_clicked()
{
    if (ui->hh->isHidden())
        ui->hh->show();
    if (ui->nameEd->isModified() || ui->author->isModified() || this->noteChange || ui->madetime->isModified() || ui->place->isModified() || this->feelingChange || this->categoryChange){

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("是否保存现有修改？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (reply == QMessageBox::Yes){
            this->save();
        }
    }
    ui->createtime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    ui->updatetime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    ui->nameEd->clear();
    if (this->checkCate == ""){
        ui->categoryBox->setCurrentIndex(0);
    }else{
        qDebug()<<this->checkCate;
        ui->categoryBox->setCurrentIndex(this->categoryList.indexOf(this->checkCate));
    }
    ui->note->clear();
    ui->feeling->clear();
    ui->author->clear();
    ui->place->clear();
    ui->madetime->clear();
    ui->nameEd->setModified(false);
    ui->author->setModified(false);
    this->noteChange = false;
    ui->madetime->setModified(false);
    ui->place->setModified(false);
    this->feelingChange = false;
    this->categoryChange = false;
    this->filePath = "";
    this->bookname = "";
    this->delFile = NULL;
}

void MainWindow::exportToWord(QList<WordItem> lsWordItem,QString strWordTemplete)
{

    QAxWidget* word = new QAxWidget("Word.Application",0,Qt::MSWindowsOwnDC);
    word->setProperty("Visible",true);

    QAxObject* documents = word->querySubObject("Documents");
    documents->dynamicCall("Add(QString)",QString(strWordTemplete));
    QAxObject* document = word->querySubObject("ActiveDocument");
    if(document == NULL || document->isNull()) {
        QMessageBox::information(0,"",QString::fromLocal8Bit("打开模板失败！"));
        return;
    }

    for(int i = 0;i < lsWordItem.size();i++) {
        QString strBookmark = "Bookmarks("+lsWordItem.at(i).key+")";
        QAxObject* bookmark = document->querySubObject(strBookmark.toAscii().data());
        if(bookmark == NULL || bookmark->isNull()) {
            continue;
        }

        bookmark->dynamicCall("Select(void)");
        bookmark->querySubObject("Range")->setProperty("Text",lsWordItem.at(i).value);
    }

    //也可以保存到默认位置后再打开
    //...
}

void MainWindow::on_note_textChanged()
{
    this->noteChange = true;
}

void MainWindow::on_feeling_textChanged()
{
    this->feelingChange = true;
}

//对话框问号按钮去掉

void MainWindow::on_ss_clicked()
{
    this->search();
}

void MainWindow::on_categoryBox_currentIndexChanged()
{
    this->categoryChange = true;
}



//文本框拖动
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        mouse_press = true;

    }else{
        mouse_press = false;
    }
    move_point =event->globalPos()-this->pos();

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(mouse_press)
    {
       QPoint move_pos = event->globalPos();
       move(move_pos-move_point);
       setWindowOpacity(1);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
    {
       QPoint move_pos = event->globalPos();
       move(move_pos-move_point);
       setWindowOpacity(0.7);
    }
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    QMainWindow::paintEvent(e);
    QPainter painter(this);
    QLinearGradient knbGradient(0,0,0,this->rect().height());
    knbGradient.setColorAt(0.0,QColor(255,0,0));
    painter.setPen(QPen(QColor(37,60,104),5,Qt::SolidLine,Qt::RoundCap));
    painter.drawRect(rect());
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (ui->nameEd->isModified() || ui->author->isModified() || this->noteChange || ui->madetime->isModified() || ui->place->isModified() || this->feelingChange || this->categoryChange){

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("是否保存现有修改？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (reply == QMessageBox::Yes){
            this->save();
        }
    }
    this->close();
}

//void MainWindow::treeWidget_customContextMenuRequested(const QPoint &pos)
//{
//    QTreeWidgetItem* curItem=ui->treeWidget->itemAt(pos);  //获取当前被点击的节点
//    if(curItem==NULL)return;           //这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
//    QVariant var = curItem->data(0, 32);
//    if(0 == var)      //data(...)返回的data已经在之前建立节点时用setdata()设置好
//    {
//        return ;
//    }else{
//        this->item1 = curItem;
//        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
//        QAction* changeText = popMenu->addAction(QString::fromUtf8("重命名"));
//        connect(changeText, SIGNAL(triggered()), this, SLOT(changetext()));
//        QAction* delCate = popMenu->addAction(QString::fromUtf8("删除"));
//        connect(delCate, SIGNAL(triggered()), this, SLOT(delcate()));
//        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置

//    }
//}

void MainWindow::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    if (QString::compare(this->hisca, item->text(0)) == 0) return ;
    if (item->text(0) == ""){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称不能为空！"));
        item->setText(0, this->hisca);
        return ;
    }else{
        if (item->text(0).length() > 16){
            QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称长度不能超过16！"));
            item->setText(0, this->hisca);
            return ;
        }
    }

    int index = this->categoryList.indexOf(this->hisca);
    qDebug()<<index;
    this->categoryList.removeAt(index);
    this->ss(this->numList.at(index), item->text(0));
    this->categoryList.insert(index, item->text(0));
    qDebug()<<this->categoryList;
    QString stri = "";
    int i = 0;
    foreach (QString category, this->categoryList) {
       stri = stri + category + "&&" + this->numList.at(i) + "\n";
       i++;
    }
    stri = stri.mid(0, stri.length() - 1);
    qDebug()<<stri;
    QFile file("./data/file/category.ini");

    //写入类型文件
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)){

        QTextStream txtOutput(&file);
        txtOutput << stri;
        txtOutput.flush();
        file.close();
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("名称更改成功"));
    }else{
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称更改失败"));
    }
    i = ui->categoryBox->currentIndex();
    bool t = this->categoryChange;
    ui->categoryBox->clear();
    ui->categoryBox->update();
    foreach (QString k, this->categoryList) {
       ui->categoryBox->addItem(k);
    }
    ui->categoryBox->setCurrentIndex(i);
    this->categoryChange = t;
}

void MainWindow::ss(QString pa, QString ca){
    QDir dir(this->findPath + pa);
    QFileInfoList file_list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    //将所有展示出来的文件保存用于打开
    foreach (QFileInfo info , file_list){
        //点击的为全部类别，需要对于文件夹进行迭代遍历
        QFile file(info.absoluteFilePath());
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("没有找到笔记！"));
            //异常处理
        }
        QString str;
        while(!file.atEnd()){
            QTextCodec* code = QTextCodec::codecForName("GB2312");
            str = code->toUnicode(file.readAll());
            break;
        }
        file.close();

        QStringList list = str.split(this->thespace);
        list.removeAt(3);
        list.insert(3, ca);
        list.removeAt(1);
        list.insert(1, QDateTime::currentDateTime().toString("yyyy/MM/dd"));
        QString thesave = list.at(0);
        int i = 1;
        while (i < list.length()){
            thesave += this->thespace;
            thesave += list.at(i);
            i++;
        }
        QFile f(info.absoluteFilePath());
        if(f.open(QIODevice::ReadWrite | QIODevice::Truncate| QIODevice::Text)){
            QTextStream txtOutput(&f);
            txtOutput<<thesave;
            f.close();
          }
    }
}
void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    this->hisca = item->text(0);
}

void MainWindow::on_searchresults_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    this->hisfi = item->text(0);
}

void MainWindow::on_searchresults_itemChanged(QTreeWidgetItem *item, int column)
{
    if (QString::compare(this->hisfi, item->text(0)) == 0) return ;
    QString kk = item->text(0).remove(QRegExp("\\s"));
    if (kk == ""){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称不能为空！"));
        item->setText(0, this->hisfi);
        return ;
    }else{
        if (kk.length() > 16){
            QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称长度不能超过16！"));
            item->setText(0, this->hisfi);
            return ;
        }
    }
    QString pattern("[\\\\/:*?\"<>]");
    QRegExp rx(pattern);
    int match = kk.indexOf(rx);
    if(match >= 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("名称包含非法字符！"));
        item->setText(0, this->hisfi);
        return ;
    }
    //重命名笔记文件
    QString prePath = item->data(0, 32).toString();
    qDebug()<<prePath;
    bool t = QFile::rename(prePath + this->hisfi + ".io", prePath + kk + ".io");
    if (t){
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("笔记改名成功"));
        this->filePath = prePath + kk + ".io";

    }else{
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("笔记改名失败"));
        item->setText(0, this->hisfi);
    }
}
