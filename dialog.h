#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileInfoList>
#include <QCheckBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void updatelist(QFileInfo info);
    void up();
    void save();
    void removefile(const QString &_Filename);

private slots:

    void on_del_clicked();

    void on_cancel_clicked();

    void on_back_clicked();

private:
    Ui::Dialog *ui;
    QString filePre;
    QFileInfoList pathList;
    QList<QCheckBox*> list;
    QFileInfoList delfileList;
};

#endif // DIALOG_H
