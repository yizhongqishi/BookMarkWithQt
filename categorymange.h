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
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void paintEvent(QPaintEvent *);

private slots:

    void on_add_clicked();

    void on_del_clicked();

    void on_back_clicked();

    void on_cancel_clicked();

    void on_back_2_clicked();

private:
    QPoint move_point;
    bool mouse_press;
    Ui::categorymange *ui;
    QStringList categoryList;
    QList<QCheckBox*> list;
    int ll;
    QStringList numList;
};

#endif // CATEGORYMANGE_H
