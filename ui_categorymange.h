/********************************************************************************
** Form generated from reading UI file 'categorymange.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYMANGE_H
#define UI_CATEGORYMANGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_categorymange
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *back_2;
    QScrollArea *scrollArea;
    QWidget *lll;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *checkboxes;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *addvalue;
    QToolButton *add;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *del;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *back;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *cancel;

    void setupUi(QDialog *categorymange)
    {
        if (categorymange->objectName().isEmpty())
            categorymange->setObjectName(QString::fromUtf8("categorymange"));
        categorymange->resize(600, 345);
        categorymange->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"QLabel{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLineEdit{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QCheckBox{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QToolButton\n"
"{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border:0px;\n"
"	background-color: rgb(62, 194, 255);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QDialog\n"
"{\n"
"	\n"
"	background-color: rgb(221, 221 221);\n"
"	background-color: rgb(230, 230, 230);\n"
"	border:2px;\n"
"	border-color: rgb(255, 221, 85);\n"
"}\n"
"QWidget#widget{\n"
"	\n"
"	border-image: url(:/icon/top_bj.jpg);\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"	background-color: rgb(51, 51, 51,97);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(categorymange);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 20);
        widget = new QWidget(categorymange);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        widget->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: rgb(255, 255, 255, 0);\n"
"}\n"
"QToolButton::hover\n"
"{\n"
"	background-color: rgb(51, 51, 51,97);\n"
"}\n"
""));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(30, 30));
        label_3->setMaximumSize(QSize(30, 30));

        horizontalLayout_5->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        back_2 = new QToolButton(widget);
        back_2->setObjectName(QString::fromUtf8("back_2"));
        back_2->setMinimumSize(QSize(40, 40));
        back_2->setMaximumSize(QSize(40, 40));
        back_2->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/2X.png"), QSize(), QIcon::Normal, QIcon::On);
        back_2->setIcon(icon);

        horizontalLayout_5->addWidget(back_2);


        verticalLayout_2->addWidget(widget);

        scrollArea = new QScrollArea(categorymange);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        lll = new QWidget();
        lll->setObjectName(QString::fromUtf8("lll"));
        lll->setGeometry(QRect(0, 0, 598, 143));
        lll->setMaximumSize(QSize(16777215, 325));
        verticalLayout = new QVBoxLayout(lll);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(40, 0, 0, 0);
        checkboxes = new QVBoxLayout();
        checkboxes->setObjectName(QString::fromUtf8("checkboxes"));

        verticalLayout->addLayout(checkboxes);

        scrollArea->setWidget(lll);

        verticalLayout_2->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(40, -1, 40, -1);
        label = new QLabel(categorymange);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        frame = new QFrame(categorymange);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(400, 36));
        frame->setMaximumSize(QSize(400, 36));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 1px solid #97d2ff;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        addvalue = new QLineEdit(frame);
        addvalue->setObjectName(QString::fromUtf8("addvalue"));
        addvalue->setMinimumSize(QSize(100, 34));
        addvalue->setMaximumSize(QSize(16777215, 34));
        addvalue->setStyleSheet(QString::fromUtf8("border:0px;"));

        horizontalLayout_4->addWidget(addvalue);

        add = new QToolButton(frame);
        add->setObjectName(QString::fromUtf8("add"));
        add->setMinimumSize(QSize(0, 35));
        add->setMaximumSize(QSize(100, 35));
        add->setStyleSheet(QString::fromUtf8("border:0px;\n"
"background-color: rgb(62, 194, 255);"));

        horizontalLayout_4->addWidget(add);


        horizontalLayout->addWidget(frame);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(40, -1, 40, -1);
        del = new QToolButton(categorymange);
        del->setObjectName(QString::fromUtf8("del"));
        del->setMaximumSize(QSize(140, 50));
        del->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(del);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        back = new QToolButton(categorymange);
        back->setObjectName(QString::fromUtf8("back"));
        back->setMinimumSize(QSize(0, 40));
        back->setMaximumSize(QSize(150, 50));
        back->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(back);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        cancel = new QToolButton(categorymange);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setMinimumSize(QSize(100, 40));
        cancel->setMaximumSize(QSize(100, 50));
        cancel->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(cancel);

        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(3, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(categorymange);

        QMetaObject::connectSlotsByName(categorymange);
    } // setupUi

    void retranslateUi(QDialog *categorymange)
    {
        categorymange->setWindowTitle(QApplication::translate("categorymange", "\346\240\207\347\255\276\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("categorymange", "\347\261\273\345\210\253\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        back_2->setText(QApplication::translate("categorymange", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("categorymange", "\347\261\273\345\210\253\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("categorymange", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        del->setText(QApplication::translate("categorymange", "\345\210\240\351\231\244\351\200\211\344\270\255", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("categorymange", "\347\241\256\350\256\244\345\271\266\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("categorymange", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class categorymange: public Ui_categorymange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYMANGE_H
