/********************************************************************************
** Form generated from reading UI file 'init2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INIT2_H
#define UI_INIT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_init2
{
public:
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *init2)
    {
        if (init2->objectName().isEmpty())
            init2->setObjectName(QString::fromUtf8("init2"));
        init2->resize(1030, 640);
        label = new QLabel(init2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 50, 341, 141));
        label->setStyleSheet(QString::fromUtf8("image: url();\n"
"font: 9pt \"Agency FB\";\n"
"color: rgb(255, 0, 0);\n"
"font: 9pt \"Agency FB\";\n"
"font: 30pt \"\351\273\221\344\275\223\";\n"
"color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));"));
        widget = new QWidget(init2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(350, 220, 241, 181));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: rgb(255, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";"));
        pushButton->setFlat(true);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: rgb(255, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";"));
        pushButton_2->setFlat(true);

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(init2);

        QMetaObject::connectSlotsByName(init2);
    } // setupUi

    void retranslateUi(QWidget *init2)
    {
        init2->setWindowTitle(QCoreApplication::translate("init2", "Form", nullptr));
        label->setText(QCoreApplication::translate("init2", "\350\257\267\351\200\211\346\213\251\345\205\210\345\220\216\346\211\213", nullptr));
        pushButton->setText(QCoreApplication::translate("init2", "\345\205\210\346\211\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("init2", "\345\220\216\346\211\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class init2: public Ui_init2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INIT2_H
