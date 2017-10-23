/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *files1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *files;
    QHBoxLayout *horizontalLayout;
    QPushButton *del;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *back;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(430, 393);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/delete.jpg"), QSize(), QIcon::Normal, QIcon::On);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLabel{\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLineEdit{\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QCheckBox{\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        scrollArea = new QScrollArea(Dialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        files1 = new QWidget();
        files1->setObjectName(QString::fromUtf8("files1"));
        files1->setGeometry(QRect(0, 0, 406, 319));
        verticalLayout_3 = new QVBoxLayout(files1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        files = new QVBoxLayout();
        files->setObjectName(QString::fromUtf8("files"));

        verticalLayout_3->addLayout(files);

        scrollArea->setWidget(files1);

        verticalLayout_2->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        del = new QPushButton(Dialog);
        del->setObjectName(QString::fromUtf8("del"));
        del->setMaximumSize(QSize(150, 50));

        horizontalLayout->addWidget(del);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel = new QPushButton(Dialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        back = new QPushButton(Dialog);
        back->setObjectName(QString::fromUtf8("back"));
        back->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(back);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\345\210\240\351\231\244\347\254\224\350\256\260", 0, QApplication::UnicodeUTF8));
        del->setText(QApplication::translate("Dialog", "\345\210\240\351\231\244\351\200\211\344\270\255", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
