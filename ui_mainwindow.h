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
    QToolButton *delfile;
    QToolButton *importfile;
    QToolButton *newfile;
    QToolButton *categorys;
    QToolButton *savefile;
    QToolButton *restorefile;
    QLabel *label_7;
    QToolButton *toolButton;
    QToolButton *toword;
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
    QPushButton *ss;
    QLineEdit *searchword;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *searchresults;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_8;
    QLabel *bookname;
    QLabel *category;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *nameEd;
    QComboBox *categoryBox;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *author;
    QLineEdit *madetime;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_6;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_14;
    QLineEdit *place;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_5;
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
        MainWindow->resize(1540, 773);
        MainWindow->setMinimumSize(QSize(1200, 600));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/logo.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("\n"
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
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border: 0px;\n"
"	\n"
"}\n"
"QToolButton\n"
"{\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border: 0px;\n"
"}\n"
"\n"
"\n"
"\n"
"QTreeWidget#treeWidget\n"
"{\n"
"background-color: rgb(255, 255, 255,0);\n"
"	border: 0px;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#widget_workspace\n"
"{\n"
"	\n"
"	border-image: url(:/icon/l_bj.jpg);\n"
"}\n"
"\n"
"\n"
"QWidget#widget_3\n"
"{\n"
"	background-color:#eeeeee;\n"
"	border: 1px solid #97d2ff;\n"
"     border-radius: 5px;\n"
"}\n"
"QWidget#widget_6\n"
"{\n"
"	border-image: url(:/icon/42424.jpg);\n"
"}\n"
"QTreeView::branch:has-children{\n"
"	\n"
"	\n"
"}"
                        "\n"
"\n"
"\n"
"QScrollArea#three_scrollArea\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit \n"
"{\n"
"     border: 1px solid #97d2ff;\n"
"     border-radius: 0px;\n"
"	 font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"     border: 1px solid #97d2ff;\n"
"     padding: 1px 2px 1px 2px;\n"
"	 font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	border: 1px solid #97d2ff;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QListWidget\n"
"{\n"
"	b"
                        "order: 1px solid #97d2ff;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QWidget#widget_toolbar\n"
"{\n"
"background-image: url(:/icon/top_bj.jpg);\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"	background-color: rgb(51, 51, 51,97);\n"
"}"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_toolbar = new QWidget(widget);
        widget_toolbar->setObjectName(QString::fromUtf8("widget_toolbar"));
        widget_toolbar->setMinimumSize(QSize(1500, 57));
        widget_toolbar->setMaximumSize(QSize(16777215, 57));
        widget_toolbar->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"QToolButton::menu-indicator{\n"
"	image:None;\n"
"}"));
        delfile = new QToolButton(widget_toolbar);
        delfile->setObjectName(QString::fromUtf8("delfile"));
        delfile->setGeometry(QRect(668, 0, 110, 57));
        delfile->setMinimumSize(QSize(110, 57));
        delfile->setMaximumSize(QSize(110, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/5.png"), QSize(), QIcon::Normal, QIcon::On);
        delfile->setIcon(icon1);
        delfile->setIconSize(QSize(48, 48));
        delfile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        delfile->setAutoRaise(true);
        importfile = new QToolButton(widget_toolbar);
        importfile->setObjectName(QString::fromUtf8("importfile"));
        importfile->setGeometry(QRect(892, 0, 110, 57));
        importfile->setMinimumSize(QSize(110, 57));
        importfile->setMaximumSize(QSize(110, 16777215));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/8.png"), QSize(), QIcon::Normal, QIcon::On);
        importfile->setIcon(icon2);
        importfile->setIconSize(QSize(48, 48));
        importfile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        newfile = new QToolButton(widget_toolbar);
        newfile->setObjectName(QString::fromUtf8("newfile"));
        newfile->setGeometry(QRect(556, 0, 110, 57));
        newfile->setMinimumSize(QSize(110, 57));
        newfile->setMaximumSize(QSize(110, 16777215));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/1.png"), QSize(), QIcon::Normal, QIcon::On);
        newfile->setIcon(icon3);
        newfile->setIconSize(QSize(48, 48));
        newfile->setCheckable(false);
        newfile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        newfile->setAutoRaise(true);
        categorys = new QToolButton(widget_toolbar);
        categorys->setObjectName(QString::fromUtf8("categorys"));
        categorys->setGeometry(QRect(1116, 0, 110, 57));
        categorys->setMinimumSize(QSize(110, 57));
        categorys->setMaximumSize(QSize(110, 16777215));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/4.png"), QSize(), QIcon::Normal, QIcon::On);
        categorys->setIcon(icon4);
        categorys->setIconSize(QSize(48, 48));
        categorys->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        savefile = new QToolButton(widget_toolbar);
        savefile->setObjectName(QString::fromUtf8("savefile"));
        savefile->setGeometry(QRect(780, 0, 110, 57));
        savefile->setMinimumSize(QSize(110, 57));
        savefile->setMaximumSize(QSize(110, 16777215));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/6.png"), QSize(), QIcon::Normal, QIcon::On);
        savefile->setIcon(icon5);
        savefile->setIconSize(QSize(48, 48));
        savefile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        restorefile = new QToolButton(widget_toolbar);
        restorefile->setObjectName(QString::fromUtf8("restorefile"));
        restorefile->setGeometry(QRect(1004, 0, 110, 57));
        restorefile->setMinimumSize(QSize(110, 57));
        restorefile->setMaximumSize(QSize(110, 16777215));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/3.png"), QSize(), QIcon::Normal, QIcon::On);
        restorefile->setIcon(icon6);
        restorefile->setIconSize(QSize(48, 48));
        restorefile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label_7 = new QLabel(widget_toolbar);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(5, 9, 259, 39));
        label_7->setMinimumSize(QSize(259, 39));
        label_7->setMaximumSize(QSize(259, 39));
        label_7->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/title.png);"));
        toolButton = new QToolButton(widget_toolbar);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(1410, 0, 110, 57));
        toolButton->setMinimumSize(QSize(110, 57));
        toolButton->setMaximumSize(QSize(110, 16777215));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/7.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton->setIcon(icon7);
        toolButton->setIconSize(QSize(48, 48));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toword = new QToolButton(widget_toolbar);
        toword->setObjectName(QString::fromUtf8("toword"));
        toword->setGeometry(QRect(1228, 0, 170, 57));
        toword->setMinimumSize(QSize(170, 57));
        toword->setMaximumSize(QSize(180, 16777215));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/2.png"), QSize(), QIcon::Normal, QIcon::On);
        toword->setIcon(icon8);
        toword->setIconSize(QSize(48, 48));
        toword->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toword->setAutoRaise(true);

        verticalLayout->addWidget(widget_toolbar);

        widget_workspace = new QWidget(widget);
        widget_workspace->setObjectName(QString::fromUtf8("widget_workspace"));
        widget_workspace->setMinimumSize(QSize(0, 631));
        horizontalLayout = new QHBoxLayout(widget_workspace);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(widget_workspace);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        treeWidget->setFont(font);
        treeWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-image: url(:/icon/\345\267\246\350\276\271\346\240\221\350\203\214\346\231\257top.png);"));
        treeWidget->setFrameShadow(QFrame::Plain);
        treeWidget->header()->setVisible(false);

        horizontalLayout->addWidget(treeWidget);

        widget_6 = new QWidget(widget_workspace);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 500));
        widget_6->setMaximumSize(QSize(16777215, 16777215));
        widget_6->setAutoFillBackground(false);
        widget_6->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_11 = new QHBoxLayout(widget_6);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        hh = new QWidget(widget_6);
        hh->setObjectName(QString::fromUtf8("hh"));
        hh->setAutoFillBackground(false);
        hh->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 241, 255);"));
        horizontalLayout_10 = new QHBoxLayout(hh);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(10, 10, 10, 10);
        widget_2 = new QWidget(hh);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(250, 0));
        widget_2->setMaximumSize(QSize(400, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 241, 255);"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 10, 0);
        frame_4 = new QFrame(widget_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMaximumSize(QSize(1677215, 35));
        frame_4->setCursor(QCursor(Qt::ArrowCursor));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 1px solid #97d2ff;\n"
""));
        frame_4->setFrameShape(QFrame::Box);
        horizontalLayout_9 = new QHBoxLayout(frame_4);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        ss = new QPushButton(frame_4);
        ss->setObjectName(QString::fromUtf8("ss"));
        ss->setMaximumSize(QSize(38, 38));
        ss->setCursor(QCursor(Qt::ArrowCursor));
        ss->setStyleSheet(QString::fromUtf8("border:0px"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/ss.png"), QSize(), QIcon::Normal, QIcon::On);
        ss->setIcon(icon9);
        ss->setIconSize(QSize(50, 50));

        horizontalLayout_9->addWidget(ss);

        searchword = new QLineEdit(frame_4);
        searchword->setObjectName(QString::fromUtf8("searchword"));
        searchword->setStyleSheet(QString::fromUtf8("border:0px"));

        horizontalLayout_9->addWidget(searchword);


        verticalLayout_3->addWidget(frame_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        searchresults = new QListWidget(widget_2);
        searchresults->setObjectName(QString::fromUtf8("searchresults"));
        searchresults->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        searchresults->setSpacing(0);

        verticalLayout_2->addWidget(searchresults);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_10->addWidget(widget_2);

        widget_3 = new QWidget(hh);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(1400, 16777215));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout_6 = new QVBoxLayout(widget_3);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 15, -1, 9);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(20);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        bookname = new QLabel(widget_3);
        bookname->setObjectName(QString::fromUtf8("bookname"));
        bookname->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_8->addWidget(bookname);

        category = new QLabel(widget_3);
        category->setObjectName(QString::fromUtf8("category"));

        verticalLayout_8->addWidget(category);


        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        nameEd = new QLineEdit(widget_3);
        nameEd->setObjectName(QString::fromUtf8("nameEd"));
        nameEd->setMinimumSize(QSize(200, 35));
        nameEd->setMaximumSize(QSize(500, 16777215));
        nameEd->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_10->addWidget(nameEd);

        categoryBox = new QComboBox(widget_3);
        categoryBox->setObjectName(QString::fromUtf8("categoryBox"));
        categoryBox->setMinimumSize(QSize(200, 35));
        categoryBox->setMaximumSize(QSize(500, 16777215));

        verticalLayout_10->addWidget(categoryBox);


        horizontalLayout_5->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_11->addWidget(label_2);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_11->addWidget(label_3);


        horizontalLayout_5->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        author = new QLineEdit(widget_3);
        author->setObjectName(QString::fromUtf8("author"));
        author->setMinimumSize(QSize(0, 35));
        author->setMaximumSize(QSize(300, 16777215));

        verticalLayout_12->addWidget(author);

        madetime = new QLineEdit(widget_3);
        madetime->setObjectName(QString::fromUtf8("madetime"));
        madetime->setMinimumSize(QSize(100, 35));
        madetime->setMaximumSize(QSize(300, 16777215));

        verticalLayout_12->addWidget(madetime);


        horizontalLayout_5->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_13->addWidget(label_6);

        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 40));

        verticalLayout_13->addWidget(label_8);


        horizontalLayout_5->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        place = new QLineEdit(widget_3);
        place->setObjectName(QString::fromUtf8("place"));
        place->setMinimumSize(QSize(0, 35));
        place->setMaximumSize(QSize(600, 16777215));

        verticalLayout_14->addWidget(place);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 40));

        verticalLayout_14->addWidget(label_9);


        horizontalLayout_5->addLayout(verticalLayout_14);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(20);
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
        horizontalLayout_7->setSpacing(20);
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
        QWidget::setTabOrder(nameEd, author);
        QWidget::setTabOrder(author, place);
        QWidget::setTabOrder(place, categoryBox);
        QWidget::setTabOrder(categoryBox, madetime);
        QWidget::setTabOrder(madetime, note);
        QWidget::setTabOrder(note, newfile);
        QWidget::setTabOrder(newfile, delfile);
        QWidget::setTabOrder(delfile, savefile);
        QWidget::setTabOrder(savefile, importfile);
        QWidget::setTabOrder(importfile, restorefile);
        QWidget::setTabOrder(restorefile, categorys);
        QWidget::setTabOrder(categorys, toolButton);
        QWidget::setTabOrder(toolButton, searchword);
        QWidget::setTabOrder(searchword, ss);
        QWidget::setTabOrder(ss, searchresults);
        QWidget::setTabOrder(searchresults, treeWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\257\273\344\271\246\347\254\224\350\256\260", 0, QApplication::UnicodeUTF8));
        delfile->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        importfile->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        newfile->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", 0, QApplication::UnicodeUTF8));
        categorys->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        savefile->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        restorefile->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        toolButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        toword->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\344\270\272word", 0, QApplication::UnicodeUTF8));
        ss->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\347\254\224\350\256\260\345\210\227\350\241\250:", 0, QApplication::UnicodeUTF8));
        bookname->setText(QApplication::translate("MainWindow", "\344\271\246\345\220\215", 0, QApplication::UnicodeUTF8));
        category->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\345\207\272\347\211\210\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\345\207\272\347\211\210\347\244\276", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QString());
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
