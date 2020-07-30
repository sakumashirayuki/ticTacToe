/********************************************************************************
** Form generated from reading UI file 'init.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INIT_H
#define UI_INIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_init
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame_2;
    QLabel *label;

    void setupUi(QWidget *init)
    {
        if (init->objectName().isEmpty())
            init->setObjectName(QString::fromUtf8("init"));
        init->resize(1030, 640);
        init->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(init);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(370, 290, 221, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: rgb(255, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";"));
        pushButton->setFlat(true);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: rgb(255, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";"));
        pushButton_2->setFlat(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: rgb(255, 0, 0);\n"
"font: 20pt \"\346\245\267\344\275\223\";"));
        pushButton_3->setFlat(true);

        verticalLayout->addWidget(pushButton_3);

        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        frame_2 = new QFrame(init);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(-10, 0, 1041, 651));
        frame_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/p.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 80, 341, 141));
        label->setStyleSheet(QString::fromUtf8("image: url();\n"
"font: 9pt \"Agency FB\";\n"
"color: rgb(255, 0, 0);\n"
"font: 9pt \"Agency FB\";\n"
"font: 36pt \"\351\273\221\344\275\223\";\n"
"color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));"));
        frame_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        layoutWidget->raise();

        retranslateUi(init);

        QMetaObject::connectSlotsByName(init);
    } // setupUi

    void retranslateUi(QWidget *init)
    {
        init->setWindowTitle(QCoreApplication::translate("init", "Tic_Tac_Toe", nullptr));
        pushButton->setText(QCoreApplication::translate("init", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("init", "\345\217\214\344\272\272\345\257\271\346\210\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("init", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        label->setText(QCoreApplication::translate("init", "Tic-Tac-Toe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class init: public Ui_init {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INIT_H
