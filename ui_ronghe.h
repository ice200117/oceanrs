/********************************************************************************
** Form generated from reading UI file 'ronghe.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RONGHE_H
#define UI_RONGHE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RongHe
{
public:
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;

    void setupUi(QDialog *RongHe)
    {
        if (RongHe->objectName().isEmpty())
            RongHe->setObjectName(QStringLiteral("RongHe"));
        RongHe->resize(1000, 560);
        pushButton_6 = new QPushButton(RongHe);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(925, 482, 79, 80));
        pushButton = new QPushButton(RongHe);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 140, 216, 282));
        pushButton_9 = new QPushButton(RongHe);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(740, 470, 160, 43));
        pushButton_8 = new QPushButton(RongHe);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(700, 175, 170, 94));
        pushButton_5 = new QPushButton(RongHe);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(380, 140, 216, 282));
        pushButton_10 = new QPushButton(RongHe);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(700, 293, 170, 94));

        retranslateUi(RongHe);

        QMetaObject::connectSlotsByName(RongHe);
    } // setupUi

    void retranslateUi(QDialog *RongHe)
    {
        RongHe->setWindowTitle(QApplication::translate("RongHe", "\350\236\215\345\220\210", 0));
        pushButton_6->setText(QString());
        pushButton->setText(QString());
        pushButton_9->setText(QString());
        pushButton_8->setText(QString());
        pushButton_5->setText(QString());
        pushButton_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RongHe: public Ui_RongHe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RONGHE_H
