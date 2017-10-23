#include "dialog.h"
#include "ui_dialog.h"
#include <QCheckBox>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->filePre = "./data/his/";
    QDir dir(this->filePre);
    QFileInfoList file_list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    //将所有展示出来的文件保存用于打开
    int ll = 0;
    foreach (QFileInfo info , file_list){
        if (info.isDir()){
            QDir kk(info.absoluteFilePath());
            QFileInfoList _file_list = kk.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
            foreach (QFileInfo ii, _file_list) {
                ll++;
                this->pathList.append(ii);
                QCheckBox* checkbox = new QCheckBox();
                checkbox->setText(ii.fileName().split(".").at(0));
                this->list.append(checkbox);
                ui->files->addWidget(checkbox);
            }
        }
    }
    if (ll <= 4){
        this->resize(QSize(400, 160 + ll * 20));
    }else{
        this->resize(QSize(400, 240));
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_del_clicked()
{
    QFileInfoList temp;
    foreach (QCheckBox* checkbox, this->list) {
        if (checkbox->isChecked()){
            foreach (QFileInfo info, this->pathList) {
                if (QString::compare(info.fileName(), checkbox->text() + ".io") == 0){
                    this->delfileList.append(info);
                    break;
                }
            }
        }
        checkbox->deleteLater();
    }
    this->list.clear();
    this->up();
}

void Dialog::up(){
    int ll = 0;
    foreach (QFileInfo info, this->pathList) {
       if (this->delfileList.indexOf(info) != -1) continue;
       QCheckBox* checkbox = new QCheckBox();
       checkbox->setText(info.fileName().split(".").at(0));
       this->list.append(checkbox);
       ui->files->addWidget(checkbox);
       ll++;
    }
    if (ll <= 4){
        this->resize(QSize(400, 160 + ll * 20));
    }else{
        this->resize(QSize(400, 240));
    }
}

void Dialog::on_cancel_clicked()
{
    return accept();
}

void Dialog::on_back_clicked()
{
    this->save();
    return accept();
}
void Dialog::save(){
    foreach (QFileInfo info, this->delfileList) {
        this->removefile(info.absoluteFilePath());
    }
}

void Dialog::removefile(const QString &_Filename){
    QFileInfo info(_Filename);
    if (!info.exists()){
        QMessageBox::warning(this, "错误", "找不到该文件");
        return ;
    }
    QFile::remove(_Filename);
}
