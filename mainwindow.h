#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QTreeWidgetItem>
#include <QBool>
#include <QFileInfo>
#include <QListWidgetItem>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class WordItem {
public:
    WordItem (QString key,QString value) {
        this->key = key;
        this->value = value;
    }
public:
    QString key;
    QString value;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

//     void keyPressEvent(QKeyEvent *);

    ~MainWindow();


//-----------------窗口移动-----------------变量
private:
       QPoint move_point;
       bool mouse_press;
protected:
       void mousePressEvent(QMouseEvent *event);
       void mouseReleaseEvent(QMouseEvent *event);
       void mouseMoveEvent(QMouseEvent *event);
       void paintEvent(QPaintEvent *);
       void getCategody();
       void scanCategory();
       void delCategory();
       void removefile(const QString &path);
       void updatelist(QFileInfo info);
       void updatezzz(QStringList kk);
       int save();
       void exportToWord(QList<WordItem> lsWordItem,QString strWordTemplete);
       void removefile1(const QString &_Filename);
       void checkfff();
       void checktt();


       void resizeEvent(QResizeEvent *);




private slots:
    void checkFile(QTreeWidgetItem* item);
    void open(QListWidgetItem* item);
    void on_savefile_clicked();

    void on_delfile_clicked();

    void on_importfile_clicked();

    void on_categorys_clicked();

    void on_restorefile_clicked();

    void on_toword_clicked();

    void on_newfile_clicked();
    void search();

    void on_note_textChanged();

    void on_feeling_textChanged();

    void on_ss_clicked();

    void on_categoryBox_currentIndexChanged();

    void on_toolButton_clicked();


private:
    Ui::MainWindow *ui;
    QString findPath;
    QString thespace;
    QString catagoryPath;
    QStringList numList;
    QTreeWidgetItem* categoryTree;
    QString filePath;
    bool cli;
    QStringList categoryList;
    QString bookname;
    QString category;
    QPushButton *m_push_scan;
    QStringList listtemp;
    QStringList pathtemp;
    bool noteChange;
    bool feelingChange;
    bool categoryChange;
    QListWidgetItem* delFile;
    QTreeWidgetItem* checkDir;
    QString checkCate;

};

#endif // MAINWINDOW_H
