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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->cli = false;
    ui->hh->hide();


    this->resize(QSize(1280,720));
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName("GBK"));
    //设置窗口大小
    this->showMaximized();
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
    ui->treeWidget->addTopLevelItem(this->categoryTree);
    ui->createtime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    ui->updatetime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));


    QObject::connect(ui->searchword,SIGNAL(returnPressed()),this,SLOT(search()));

    this->getCategody();

    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(checkFile(QTreeWidgetItem*)));
    QObject::connect(ui->searchresults, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(open(QListWidgetItem*)));
    QAction *action = new QAction(this);
    action->setShortcut(QKeySequence(tr("Ctrl+S")));
    ui->savefile->addAction(action);
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

//void MainWindow::keyPressEvent(QKeyEvent *){
//    QMessageBox::warning(this,"info","info");
//}

void MainWindow::search(){
    QString text = ui->searchword->text();
    if (QString::compare(text, "")){
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
            foreach (QString temp, this->listtemp){
                QListWidgetItem* item = new QListWidgetItem();
                item->setText(temp.split(".").at(0));
                ui->searchresults->addItem(item);
            }
        }
        this->listtemp.clear();
        QStringList li;
        for (int i = 0; i < ui->searchresults->count(); i++){
            this->listtemp.append(ui->searchresults->item(i)->text()+".io");
            if (re.indexIn(ui->searchresults->item(i)->text()) != -1){
                li.append(ui->searchresults->item(i)->text());
            }
        }
        ui->searchresults->clear();
        this->cli = false;
        foreach (QString l, li){
            QListWidgetItem* item = new QListWidgetItem();
            item->setText(l);
            ui->searchresults->addItem(item);
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
        QByteArray line = file.readLine();
        QString str(line);
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
    ui->hh->show();
    this->cli = true;
    int i = this->categoryList.indexOf(item->text(0));
    QString name;
    //    判断是不是点击的全部类别
    if (i != -1){
        name = this->numList.at(i);
    }else{
        name = "";
    }
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
    this->save();
}
void MainWindow::save(){
    QString nn = ui->nameEd->text();
    if (QString::compare(nn,"") == 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("书名不能为空"));
    }else{
        //note发生修改
        if (this->noteChange){
            QStringList temp = ui->note->toPlainText().split("------");
            QString note;
            if (temp.length() > 2) {
                note = temp.at(2);
            }else{
                note = temp.at(0);
            }
            if (note.at(0) == '\n'){
                note = note.mid(1, note.length());
            }
            ui->note->clear();
            ui->note->append(QString::fromUtf8("------修改于:") + QDateTime::currentDateTime().toString("yyyy/MM/dd") + "------\n" + note);
            this->noteChange = false;
        }
        if (this->feelingChange){
        //feeling发生修改
            QStringList temp = ui->feeling->toPlainText().split("------");
            QString feeling;
            if (temp.length() > 2) {
                feeling = temp.at(2);
            }else{
                feeling = temp.at(0);
            }
            if (feeling.at(0) == '\n'){
                feeling = feeling.mid(1, feeling.length());
            }
            ui->feeling->clear();
            ui->feeling->append(QString::fromUtf8("------修改于:")+ QDateTime::currentDateTime().toString("yyyy/MM/dd") + "------\n" + feeling);
            this->feelingChange = false;
        }
        QString cate = ui->categoryBox->currentText();
        //新建文件路径
        if(QString::compare(this->filePath, "") == 0){
            this->filePath = this->findPath + this->numList.at(this->categoryList.indexOf(cate)) + "/" + nn + "____" + cate + ".io";
        }else{
            if(QString::compare(this->category, cate) != 0){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("类别发生改变，将在新选择的类别下保存文件,否则停止保存"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                if (reply == QMessageBox::No){
                    return;
                }else{
                    this->filePath = this->findPath + this->numList.at(this->categoryList.indexOf(cate)) + "/" + nn + "____" + cate + ".io";
                }
            }
            if (QString::compare(nn, this->bookname) != 0){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, QString::fromUtf8("警告"), QString::fromUtf8("书名发生改变，将以新的书名保存文件,否则停止保存"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                if (reply == QMessageBox::No){
                    return;
                }else{
                    this->filePath = this->findPath + this->numList.at(this->categoryList.indexOf(cate)) + "/" + nn + "____" + cate + ".io";
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
        }else{
            QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("保存失败"));
        }
    }
}

void MainWindow::open(QListWidgetItem* item){
    QString file_name = item->text();
    QString path = item->data(32).toString();
    this->filePath = path;
    QFile file(this->filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //异常处理
    }
    while(!file.atEnd()){
        QByteArray line = file.readAll();
        QString str(line);
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
    this->feelingChange = false;
    this->noteChange = false;
}

void MainWindow::on_delfile_clicked()
{
    Dialog dia;
    if(dia.exec()==QDialog::Accepted){
        ui->searchresults->clear();
    }
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
            QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("文件导入成功"));
    }
}

void MainWindow::on_categorys_clicked()
{
    categorymange mange;
    if(mange.exec()==QDialog::Accepted){
        this->getCategody();
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
    lsWordItem.append(WordItem("BM_shuming",ui->nameEd->text()));
    lsWordItem.append(WordItem("BM_leixing",ui->categoryBox->currentText()));
    lsWordItem.append(WordItem("BM_zuozhe",ui->author->text()));
    lsWordItem.append(WordItem("BM_chubanshijian",ui->madetime->text()));
    lsWordItem.append(WordItem("BM_chubanshe",ui->place->text()));
    lsWordItem.append(WordItem("BM_chuangjianshijian",ui->createtime->text()));
    lsWordItem.append(WordItem("BM_gengxinshijian",ui->updatetime->text()));
    lsWordItem.append(WordItem("BM_zhaiji",ui->note->toPlainText()));
    lsWordItem.append(WordItem("BM_pingzhu",ui->feeling->toPlainText()));


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
    this->filePath = "";
    this->bookname = "";
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

void MainWindow::on_categoryBox_currentIndexChanged(int index)
{
    this->categoryChange = true;
}
