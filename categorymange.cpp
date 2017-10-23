#include "categorymange.h"
#include "ui_categorymange.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>

categorymange::categorymange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categorymange)
{
    ui->setupUi(this);
    ui->cancel->setFocus();
    QFile file("./data/file/category.ini");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
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
    int ll = 0;
    foreach (QString category, this->categoryList) {
        QCheckBox* checkbox = new QCheckBox();
        checkbox->setText(category);
        this->list.append(checkbox);
        ui->checkboxes->addWidget(checkbox);
        ll++;
    }
    if (ll <= 6){
        this->resize(QSize(400, 200 + ll * 25));
    }else{
        this->resize(QSize(400, 350));
    }
    qDebug()<<this->size();
}

categorymange::~categorymange()
{
    delete ui;
}


void categorymange::on_add_clicked()
{
    QString value = ui->addvalue->text();
    if (QString::compare(value, "") == 0){
        QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("标签名称不能为空"));
    }else if (this->categoryList.contains(value)){
         QMessageBox::warning(this, QString::fromUtf8("错误"), QString::fromUtf8("标签名称不能重复"));
    }else{
        this->categoryList.append(value);
        this->numList.append(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
        QCheckBox* checkbox = new QCheckBox(this);
        checkbox->setText(value);
        this->list.append(checkbox);
        this->clear();
        this->up();
        ui->addvalue->setText("");
    }

}

void categorymange::clear(){
    foreach (QCheckBox* checkbox, this->list) {
        checkbox->deleteLater();
    }
}
void categorymange::on_del_clicked()
{
    QStringList temp1;
    QStringList temp2;
    foreach (QCheckBox* checkbox, this->list) {
        if (!checkbox->isChecked()){
            temp1.append(checkbox->text());
            temp2.append(this->numList.at(this->categoryList.indexOf(checkbox->text())));
        }
        checkbox->deleteLater();
    }
    this->categoryList = temp1;
    this->numList = temp2;
    this->list.clear();
    this->up();
}

void categorymange::up(){
    int ll = 0;
    this->list.clear();
    foreach (QString category, this->categoryList) {
       QCheckBox* checkbox = new QCheckBox();
       checkbox->setText(category);
       this->list.append(checkbox);
       ui->checkboxes->addWidget(checkbox);
       ll++;
    }
    if (ll <= 6){
        this->resize(QSize(400, 200 + ll * 25));
    }else{
        this->resize(QSize(400, 350));
    }
    qDebug()<<this->size();
}

void categorymange::on_back_clicked()
{
    this->ss();
    return accept();
    //返回主界面信号
}

void categorymange::on_apply_clicked()
{
    this->ss();
}

void categorymange::ss(){
    QString stri = "";
    int i = 0;
    foreach (QString category, this->categoryList) {
       stri = stri + category + "&&" + this->numList.at(i) + "\n";
       i++;
    }
    stri = stri.mid(0, stri.length() - 1);
    QFile file("./data/file/category.ini");

    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)){

        QTextStream txtOutput(&file);
        txtOutput << stri;
        txtOutput.flush();
        file.close();
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("类型更改成功"));
    }else{
        QMessageBox::warning(this, QString::fromUtf8("提示"), QString::fromUtf8("类型更改失败"));
    }
}

void categorymange::work(){
    if (!this->isVisible())
        this->show();
}

void categorymange::on_cancel_clicked()
{
    return accept();
}
