#ifndef CATEGORYMANGE_H
#define CATEGORYMANGE_H

#include <QDialog>
#include <QCheckBox>

namespace Ui {
class categorymange;
}

class categorymange : public QDialog
{
    Q_OBJECT

public:
    explicit categorymange(QWidget *parent = 0);
    ~categorymange();
    void ss();
    void work();
    void up();
    void clear();

private slots:

    void on_add_clicked();

    void on_del_clicked();

    void on_back_clicked();

    void on_apply_clicked();

    void on_cancel_clicked();

private:
    Ui::categorymange *ui;
    QStringList categoryList;
    QList<QCheckBox*> list;
    int ll;
    QStringList numList;
};

#endif // CATEGORYMANGE_H
