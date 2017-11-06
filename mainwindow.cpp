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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
//    this->setWindowFlags(this->windowFlags() & ~Qt::WindowTitleHint);

    ui->setupUi(this);
    this->cli = false;
    ui->hh->hide();

//    this->resize(QSize(1500,631));
//    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("UTF8"));
    //设置窗口大小
    QDesktopWidget* dddd = QApplication::desktop();
    QRect rr = dddd->screenGeometry();
    this->setGeometry(0,0,rr.width(),rr.height()-40);
    ui->widget_workspace->setAutoFillBackground(true);
    //this->setFixedSize(QSize(this));
    //默认最大化
//    this->showMaximized();
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
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel("");
    this->checkCate="";
    ui->treeWidget->addTopLevelItem(this->categoryTree);
    ui->createtime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    ui->updatetime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));


    QObject::connect(ui->searchword,SIGNAL(returnPressed()),this,SLOT(search()));

    this->getCategody();

    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(checkFile(QTreeWidgetItem*)));
    QObject::connect(ui->searchresults, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(open(QListWidgetItem*)));
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
    QWidget* arrToolButtons[] = {ui->newfile,ui->savefile,ui->delfile,ui->importfile,ui->restorefile,ui->categorys,ui->toword,ui->toolButton};
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
    if (ui->searchresults->count() == 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("没有可供选择的项"));
    }else{
        if (!this->cli){
            ui->searchresults->clear();
            int i = 0;
            foreach (QString temp, this->listtemp){
                QListWidgetItem* item = new QListWidgetItem();
                item->setText(temp.split(".").at(0));
                QVariant value = this->pathtemp.at(i);
                //保存文件路径用于访问
                item->setData(32,value);
                ui->searchresults->addItem(item);
                i++;
            }
        }
        this->listtemp.clear();
        this->pathtemp.clear();
        QStringList li;
        QStringList pa;
        for (int i = 0; i < ui->searchresults->count(); i++){
            this->listtemp.append(ui->searchresults->item(i)->text()+".io");
            this->pathtemp.append(ui->searchresults->item(i)->data(32).toString());
            if (re.indexIn(ui->searchresults->item(i)->text()) != -1){
                li.append(ui->searchresults->item(i)->text());
                pa.append(ui->searchresults->item(i)->data(32).toString());
            }
        }
        ui->searchresults->clear();
        this->cli = false;
        int i = 0;
        foreach (QString l, li){
            QListWidgetItem* item = new QListWidgetItem();
            item->setText(l);
            QVariant value = pa.at(i);
            //保存文件路径用于访问
            item->setData(32,value);
            ui->searchresults->addItem(item);
            i++;
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
//    ui->treeWidget->clear();
    delete(this->categoryTree);
    this->categoryTree = new QTreeWidgetItem();
    this->categoryTree->setText(0, QString::fromUtf8("全部类别"));
    ui->treeWidget->addTopLevelItem(this->categoryTree);
}

void MainWindow::checkFile(QTreeWidgetItem* item){
    //接下来需要恢复删除笔记后的记录
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
    //    判断是不是点击的全部类别
    if (i != -1){
        name = this->numList.at(i);
    }else{
        name = "";
    }
    this->checkCate = name;
    QDir dir(this->findPath + name);
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

void MainWindow::updatelist(QFileInfo info){
    //将所有展示出来的文件保存用于打开
    QListWidgetItem* item = new QListWidgetItem();
    item->setText(info.fileName().split(".").at(0));
    QVariant value = info.absoluteFilePath();
    //保存文件路径用于访问
    item->setData(32,value);
    ui->searchresults->addItem(item);
}



void MainWindow::on_savefile_clicked()
{
    int k  = this->save();
    if (k == 0) {
        this->checktt();
    }
}

void MainWindow::checktt(){
    qDebug()<<this->checkCate;
    QString path = this->findPath;
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
    QString nn = ui->nameEd->text();
    if (QString::compare(nn,"") == 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("书名不能为空"));
        return 1;
    }else{
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

void MainWindow::open(QListWidgetItem* item){
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
    QString file_name = item->text();
    QString path = item->data(32).toString();
    qDebug()<<path;
    this->filePath = path;
    QFile file(this->filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
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
    this->filePath = "";
    //删除选中笔记
    this->removefile1(this->delFile->data(32).toString());
    this->checkfff();
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("删除笔记成功！"));
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
    //    判断是不是点击的全部类别
    if (i != -1){
        name = this->numList.at(i);
    }else{
        name = "";
    }
    this->checkCate = name;
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
            this->filePath = "";
            this->bookname = "";
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

void MainWindow::on_toolButton_clicked()
{
    if (ui->nameEd->isModified() || ui->author->isModified() || this->noteChange || ui->madetime->isModified() || ui->place->isModified() || this->feelingChange || this->categoryChange){

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("是否保存现有修改？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (reply == QMessageBox::Yes){
            this->save();
        }
    }
    this->close();
}


//文本框拖动
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        mouse_press = true;

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
