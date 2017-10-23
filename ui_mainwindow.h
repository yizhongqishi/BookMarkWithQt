/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_toolbar;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *newfile;
    QToolButton *importfile;
    QToolButton *delfile;
    QToolButton *toword;
    QToolButton *restorefile;
    QToolButton *categorys;
    QToolButton *savefile;
    QWidget *widget_workspace;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_11;
    QWidget *hh;
    QHBoxLayout *horizontalLayout_10;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *searchword;
    QPushButton *ss;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *searchresults;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *bookname;
    QLineEdit *nameEd;
    QLabel *label_2;
    QLineEdit *author;
    QLabel *label_6;
    QLineEdit *place;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *category;
    QComboBox *categoryBox;
    QLabel *label_3;
    QLineEdit *madetime;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QTextEdit *note;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *feeling;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_cretetime;
    QLabel *createtime;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_updatetime;
    QLabel *updatetime;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1040, 561);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/42424.jpg"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget#widget\n"
"{\n"
"	background-color:#4f535e;\n"
"}\n"
"\n"
"QWidget#widget_toolbar\n"
"{\n"
"	background-color:#cccccc;\n"
"}\n"
"QTreeWidget:treeWidget\n"
"{\n"
"   color:rgb(255, 255, 255);\n"
"}\n"
"QLabel\n"
"{\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border: 0px;\n"
"	\n"
"}\n"
"QToolButton\n"
"{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border: 0px;\n"
"}\n"
"\n"
"\n"
"QTreeWidget#treeWidget\n"
"{\n"
"	background-color:#4f535e;\n"
"	border: 0px;\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	image: url(:/icon/search.jpg);\n"
"}\n"
"\n"
"QWidget#widget_workspace\n"
"{\n"
"	background-color:#4f535e;\n"
"}\n"
"\n"
"QWidget#widget_2\n"
"{\n"
"	background-color:#eeeeee;\n"
"}\n"
"\n"
"QWidget#widget_3\n"
"{\n"
"	background-color:#eeeeee;\n"
"}\n"
"QTreeView::branch:has-children{\n"
"	\n"
"	image: url(:/icon/s"
                        "earch.jpg);\n"
"}\n"
"\n"
"\n"
"QScrollArea#three_scrollArea\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit \n"
"{\n"
"     border: 1px solid #cccccc;\n"
"     border-radius: 0px;\n"
"	 font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"     border: 1px solid rgba(161, 161, 161);\n"
"     padding: 1px 2px 1px 2px;\n"
"	 font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"	subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"	width: 20px;\n"
"    border-left-width:1px;\n"
"     border-left-color:  rgba(161, 161, 161);\n"
" 	 border-left-style: solid;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	image: url(:/icon/combox.gif);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	border: 1px solid rgba(161, 161, 161);\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"	border: 1px solid #cccccc;\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
""
                        "\n"
"QListWidget\n"
"{\n"
"	border: 1px solid #cccccc;\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(7);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_toolbar = new QWidget(widget);
        widget_toolbar->setObjectName(QString::fromUtf8("widget_toolbar"));
        widget_toolbar->setMinimumSize(QSize(0, 60));
        widget_toolbar->setMaximumSize(QSize(16777215, 60));
        gridLayout_2 = new QGridLayout(widget_toolbar);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setContentsMargins(5, 0, -1, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 10, 1, 1);

        newfile = new QToolButton(widget_toolbar);
        newfile->setObjectName(QString::fromUtf8("newfile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/newfile.png"), QSize(), QIcon::Normal, QIcon::On);
        newfile->setIcon(icon1);
        newfile->setCheckable(false);
        newfile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        newfile->setAutoRaise(true);

        gridLayout_2->addWidget(newfile, 0, 1, 1, 1);

        importfile = new QToolButton(widget_toolbar);
        importfile->setObjectName(QString::fromUtf8("importfile"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/import.png"), QSize(), QIcon::Normal, QIcon::On);
        importfile->setIcon(icon2);
        importfile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(importfile, 0, 6, 1, 1);

        delfile = new QToolButton(widget_toolbar);
        delfile->setObjectName(QString::fromUtf8("delfile"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/delete.jpg"), QSize(), QIcon::Normal, QIcon::On);
        delfile->setIcon(icon3);
        delfile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        delfile->setAutoRaise(true);

        gridLayout_2->addWidget(delfile, 0, 2, 1, 1);

        toword = new QToolButton(widget_toolbar);
        toword->setObjectName(QString::fromUtf8("toword"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/output.jpg"), QSize(), QIcon::Normal, QIcon::On);
        toword->setIcon(icon4);
        toword->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toword->setAutoRaise(true);

        gridLayout_2->addWidget(toword, 0, 5, 1, 1);

        restorefile = new QToolButton(widget_toolbar);
        restorefile->setObjectName(QString::fromUtf8("restorefile"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/save.jpg"), QSize(), QIcon::Normal, QIcon::On);
        restorefile->setIcon(icon5);
        restorefile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(restorefile, 0, 7, 1, 1);

        categorys = new QToolButton(widget_toolbar);
        categorys->setObjectName(QString::fromUtf8("categorys"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/manager.jpg"), QSize(), QIcon::Normal, QIcon::On);
        categorys->setIcon(icon6);
        categorys->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(categorys, 0, 8, 1, 1);

        savefile = new QToolButton(widget_toolbar);
        savefile->setObjectName(QString::fromUtf8("savefile"));
        savefile->setIcon(icon5);
        savefile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_2->addWidget(savefile, 0, 3, 1, 1);


        verticalLayout->addWidget(widget_toolbar);

        widget_workspace = new QWidget(widget);
        widget_workspace->setObjectName(QString::fromUtf8("widget_workspace"));
        horizontalLayout = new QHBoxLayout(widget_workspace);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(widget_workspace);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        treeWidget->setFont(font);
        treeWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        treeWidget->setFrameShadow(QFrame::Plain);
        treeWidget->header()->setVisible(false);

        horizontalLayout->addWidget(treeWidget);

        widget_6 = new QWidget(widget_workspace);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setAutoFillBackground(false);
        widget_6->setStyleSheet(QString::fromUtf8("background-image: url(:/icon/oo.png);"));
        horizontalLayout_11 = new QHBoxLayout(widget_6);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        hh = new QWidget(widget_6);
        hh->setObjectName(QString::fromUtf8("hh"));
        hh->setAutoFillBackground(false);
        hh->setStyleSheet(QString::fromUtf8("background-image: url(:/icon/bk.png);"));
        horizontalLayout_10 = new QHBoxLayout(hh);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(hh);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(250, 0));
        widget_2->setMaximumSize(QSize(400, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_4 = new QFrame(widget_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setCursor(QCursor(Qt::ArrowCursor));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        frame_4->setFrameShape(QFrame::Box);
        horizontalLayout_9 = new QHBoxLayout(frame_4);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        searchword = new QLineEdit(frame_4);
        searchword->setObjectName(QString::fromUtf8("searchword"));
        searchword->setStyleSheet(QString::fromUtf8("border:0px"));

        horizontalLayout_9->addWidget(searchword);

        ss = new QPushButton(frame_4);
        ss->setObjectName(QString::fromUtf8("ss"));
        ss->setMaximumSize(QSize(38, 38));
        ss->setCursor(QCursor(Qt::ArrowCursor));
        ss->setStyleSheet(QString::fromUtf8("border:0px"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/search.png"), QSize(), QIcon::Normal, QIcon::On);
        ss->setIcon(icon7);
        ss->setIconSize(QSize(38, 38));

        horizontalLayout_9->addWidget(ss);


        verticalLayout_3->addWidget(frame_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        searchresults = new QListWidget(widget_2);
        searchresults->setObjectName(QString::fromUtf8("searchresults"));
        searchresults->setSpacing(0);

        verticalLayout_2->addWidget(searchresults);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_10->addWidget(widget_2);

        widget_3 = new QWidget(hh);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_6 = new QVBoxLayout(widget_3);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, -1, 9);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        bookname = new QLabel(widget_3);
        bookname->setObjectName(QString::fromUtf8("bookname"));

        horizontalLayout_5->addWidget(bookname);

        nameEd = new QLineEdit(widget_3);
        nameEd->setObjectName(QString::fromUtf8("nameEd"));
        nameEd->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_5->addWidget(nameEd);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        author = new QLineEdit(widget_3);
        author->setObjectName(QString::fromUtf8("author"));

        horizontalLayout_5->addWidget(author);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        place = new QLineEdit(widget_3);
        place->setObjectName(QString::fromUtf8("place"));

        horizontalLayout_5->addWidget(place);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        category = new QLabel(widget_3);
        category->setObjectName(QString::fromUtf8("category"));

        horizontalLayout_8->addWidget(category);

        categoryBox = new QComboBox(widget_3);
        categoryBox->setObjectName(QString::fromUtf8("categoryBox"));
        categoryBox->setMinimumSize(QSize(200, 0));

        horizontalLayout_8->addWidget(categoryBox);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        madetime = new QLineEdit(widget_3);
        madetime->setObjectName(QString::fromUtf8("madetime"));

        horizontalLayout_8->addWidget(madetime);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_4);

        note = new QTextEdit(widget_3);
        note->setObjectName(QString::fromUtf8("note"));
        note->setFrameShadow(QFrame::Plain);

        horizontalLayout_6->addWidget(note);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_7->addLayout(verticalLayout_5);

        feeling = new QTextEdit(widget_3);
        feeling->setObjectName(QString::fromUtf8("feeling"));
        feeling->setFrameShadow(QFrame::Plain);

        horizontalLayout_7->addWidget(feeling);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_cretetime = new QLabel(widget_3);
        label_cretetime->setObjectName(QString::fromUtf8("label_cretetime"));

        horizontalLayout_2->addWidget(label_cretetime);

        createtime = new QLabel(widget_3);
        createtime->setObjectName(QString::fromUtf8("createtime"));
        createtime->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(createtime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_updatetime = new QLabel(widget_3);
        label_updatetime->setObjectName(QString::fromUtf8("label_updatetime"));

        horizontalLayout_3->addWidget(label_updatetime);

        updatetime = new QLabel(widget_3);
        updatetime->setObjectName(QString::fromUtf8("updatetime"));
        updatetime->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(updatetime);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout_10->addWidget(widget_3);


        horizontalLayout_11->addWidget(hh);


        horizontalLayout->addWidget(widget_6);


        verticalLayout->addWidget(widget_workspace);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\257\273\344\271\246\347\254\224\350\256\260", 0, QApplication::UnicodeUTF8));
        newfile->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\254\224\350\256\260", 0, QApplication::UnicodeUTF8));
        importfile->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        delfile->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\254\224\350\256\260", 0, QApplication::UnicodeUTF8));
        toword->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\344\270\272word", 0, QApplication::UnicodeUTF8));
        restorefile->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        categorys->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\253\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        savefile->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\254\224\350\256\260", 0, QApplication::UnicodeUTF8));
        ss->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\347\254\224\350\256\260\345\210\227\350\241\250:", 0, QApplication::UnicodeUTF8));
        bookname->setText(QApplication::translate("MainWindow", "\344\271\246\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\345\207\272\347\211\210\347\244\276", 0, QApplication::UnicodeUTF8));
        category->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\345\207\272\347\211\210\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\346\221\230\350\256\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\350\257\204\346\263\250", 0, QApplication::UnicodeUTF8));
        label_cretetime->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        createtime->setText(QString());
        label_updatetime->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        updatetime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
