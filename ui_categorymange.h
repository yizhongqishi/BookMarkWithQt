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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_categorymange
{
public:
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *checkboxes;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *addvalue;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *add;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *del;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *back;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *categorymange)
    {
        if (categorymange->objectName().isEmpty())
            categorymange->setObjectName(QString::fromUtf8("categorymange"));
        categorymange->resize(662, 445);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/manager.jpg"), QSize(), QIcon::Normal, QIcon::On);
        categorymange->setWindowIcon(icon);
        categorymange->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLabel{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLineEdit{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QCheckBox{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(categorymange);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea = new QScrollArea(categorymange);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("border:0px;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 640, 325));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkboxes = new QVBoxLayout();
        checkboxes->setObjectName(QString::fromUtf8("checkboxes"));

        verticalLayout_3->addLayout(checkboxes);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(categorymange);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        addvalue = new QLineEdit(categorymange);
        addvalue->setObjectName(QString::fromUtf8("addvalue"));
        addvalue->setMinimumSize(QSize(100, 0));
        addvalue->setMaximumSize(QSize(190, 50));

        horizontalLayout->addWidget(addvalue);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        add = new QPushButton(categorymange);
        add->setObjectName(QString::fromUtf8("add"));
        add->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(add);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        del = new QPushButton(categorymange);
        del->setObjectName(QString::fromUtf8("del"));
        del->setMaximumSize(QSize(140, 50));

        horizontalLayout_3->addWidget(del);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        back = new QPushButton(categorymange);
        back->setObjectName(QString::fromUtf8("back"));
        back->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(back);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        cancel = new QPushButton(categorymange);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setMaximumSize(QSize(100, 50));

        horizontalLayout_3->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 2);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout);


        retranslateUi(categorymange);

        QMetaObject::connectSlotsByName(categorymange);
    } // setupUi

    void retranslateUi(QDialog *categorymange)
    {
        categorymange->setWindowTitle(QApplication::translate("categorymange", "\346\240\207\347\255\276\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("categorymange", "\346\240\207\347\255\276\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("categorymange", "\345\242\236\345\212\240", 0, QApplication::UnicodeUTF8));
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
