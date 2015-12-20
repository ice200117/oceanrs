/********************************************************************************
** Form generated from reading UI file 'demo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Demo
{
public:
    QPushButton *pushButton_5;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QLabel *label_5;

    void setupUi(QDialog *Demo)
    {
        if (Demo->objectName().isEmpty())
            Demo->setObjectName(QStringLiteral("Demo"));
        Demo->resize(763, 429);
        pushButton_5 = new QPushButton(Demo);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(720, 5, 40, 40));
        label_2 = new QLabel(Demo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 200, 151, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        label_2->setFont(font);
        label_3 = new QLabel(Demo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 260, 141, 31));
        label_3->setFont(font);
        pushButton = new QPushButton(Demo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(670, 156, 31, 23));
        lineEdit_2 = new QLineEdit(Demo);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(182, 212, 481, 20));
        lineEdit_3 = new QLineEdit(Demo);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(182, 269, 481, 20));
        label = new QLabel(Demo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 150, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        lineEdit = new QLineEdit(Demo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(182, 158, 481, 20));
        pushButton_3 = new QPushButton(Demo);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(670, 268, 31, 23));
        label_4 = new QLabel(Demo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 10, 411, 41));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush1);
        label_4->setPalette(palette);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setMouseTracking(false);
        label_4->setContextMenuPolicy(Qt::ActionsContextMenu);
        label_4->setAcceptDrops(false);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(Demo);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 210, 31, 23));
        pushButton_4 = new QPushButton(Demo);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 380, 156, 43));
        label_5 = new QLabel(Demo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 174, 147, 98));

        retranslateUi(Demo);

        QMetaObject::connectSlotsByName(Demo);
    } // setupUi

    void retranslateUi(QDialog *Demo)
    {
        Demo->setWindowTitle(QApplication::translate("Demo", "Dialog", 0));
        pushButton_5->setText(QString());
        label_2->setText(QApplication::translate("Demo", "\350\276\223\345\205\245\346\267\261\345\272\246\346\225\260\346\215\256\357\274\232", 0));
        label_3->setText(QApplication::translate("Demo", "\350\276\223\345\207\272\346\225\260\346\215\256\350\267\257\345\276\204\357\274\232", 0));
        pushButton->setText(QApplication::translate("Demo", "...", 0));
        label->setText(QApplication::translate("Demo", "\350\276\223 \345\205\245 \346\225\260 \346\215\256 \357\274\232", 0));
        pushButton_3->setText(QApplication::translate("Demo", "...", 0));
        label_4->setText(QApplication::translate("Demo", "label_4", 0));
        pushButton_2->setText(QApplication::translate("Demo", "...", 0));
        pushButton_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Demo: public Ui_Demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
