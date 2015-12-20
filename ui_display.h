/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <ActiveQt/QAxWidget>
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

class Ui_Display
{
public:
    QLabel *label_14;
    QPushButton *pushButton;
    QLabel *label_7;
    QLabel *label_13;
    QLabel *label_5;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QLabel *label_17;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_15;
    QLabel *label_11;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_4;
    QLabel *label_22;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_18;
    QAxWidget *axWidget;
    QPushButton *pushButton_jias;
    QPushButton *pushButton_zt;
    QPushButton *pushButton_bf;
    QPushButton *pushButton_jians;

    void setupUi(QDialog *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName(QStringLiteral("Display"));
        Display->resize(1270, 700);
        Display->setStyleSheet(QStringLiteral(""));
        label_14 = new QLabel(Display);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(290, 30, 981, 671));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Images/images/three_dim.jpg")));
        pushButton = new QPushButton(Display);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1220, -9, 50, 50));
        label_7 = new QLabel(Display);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 240, 121, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_13 = new QLabel(Display);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 321, 81, 16));
        label_13->setFont(font);
        label_13->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_5 = new QLabel(Display);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 200, 121, 16));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_10 = new QLabel(Display);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 280, 91, 16));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        lineEdit = new QLineEdit(Display);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 356, 61, 20));
        label_17 = new QLabel(Display);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(240, 360, 31, 16));
        label_17->setFont(font);
        label_17->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label = new QLabel(Display);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 80, 61, 21));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_3 = new QLabel(Display);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 120, 51, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_9 = new QLabel(Display);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 240, 81, 16));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(Display);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 160, 111, 16));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_15 = new QLabel(Display);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(50, 160, 51, 21));
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_11 = new QLabel(Display);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 280, 81, 16));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Display);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 80, 121, 21));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(Display);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 200, 81, 16));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_12 = new QLabel(Display);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(180, 320, 81, 16));
        label_12->setFont(font);
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_16 = new QLabel(Display);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(50, 360, 81, 16));
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_4 = new QLabel(Display);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 120, 111, 16));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_22 = new QLabel(Display);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(35, 45, 28, 16));
        label_22->setStyleSheet(QStringLiteral("border-image: url(:/Images/images/pic_infor.png);"));
        label_19 = new QLabel(Display);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(70, 43, 81, 21));
        label_19->setFont(font);
        label_19->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_20 = new QLabel(Display);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 460, 161, 16));
        label_20->setFont(font);
        label_20->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        label_18 = new QLabel(Display);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 510, 291, 151));
        label_18->setFont(font);
        label_18->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        axWidget = new QAxWidget(Display);
        axWidget->setObjectName(QStringLiteral("axWidget"));
        axWidget->setProperty("geometry", QVariant(QRect(290, 30, 981, 671)));
        pushButton_jias = new QPushButton(Display);
        pushButton_jias->setObjectName(QStringLiteral("pushButton_jias"));
        pushButton_jias->setGeometry(QRect(1130, 0, 31, 31));
        pushButton_zt = new QPushButton(Display);
        pushButton_zt->setObjectName(QStringLiteral("pushButton_zt"));
        pushButton_zt->setGeometry(QRect(1090, 0, 31, 31));
        pushButton_bf = new QPushButton(Display);
        pushButton_bf->setObjectName(QStringLiteral("pushButton_bf"));
        pushButton_bf->setGeometry(QRect(1050, 0, 31, 31));
        pushButton_jians = new QPushButton(Display);
        pushButton_jians->setObjectName(QStringLiteral("pushButton_jians"));
        pushButton_jians->setGeometry(QRect(1010, 0, 31, 31));
        label_14->raise();
        pushButton->raise();
        label_7->raise();
        label_13->raise();
        label_5->raise();
        label_10->raise();
        label_17->raise();
        label->raise();
        label_3->raise();
        label_9->raise();
        label_6->raise();
        label_15->raise();
        label_11->raise();
        label_2->raise();
        label_8->raise();
        label_12->raise();
        label_16->raise();
        label_4->raise();
        label_22->raise();
        label_19->raise();
        label_20->raise();
        label_18->raise();
        axWidget->raise();
        pushButton_jias->raise();
        pushButton_zt->raise();
        pushButton_bf->raise();
        pushButton_jians->raise();
        lineEdit->raise();
        QWidget::setTabOrder(pushButton_zt, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_jias);
        QWidget::setTabOrder(pushButton_jias, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_bf);
        QWidget::setTabOrder(pushButton_bf, pushButton_jians);

        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QDialog *Display)
    {
        Display->setWindowTitle(QApplication::translate("Display", "\344\272\247\345\223\201\344\277\241\346\201\257", 0));
        label_14->setText(QString());
        pushButton->setText(QString());
        label_7->setText(QApplication::translate("Display", "\346\234\200\345\260\217\346\265\267\350\241\250\346\270\251\345\272\246\357\274\232", 0));
        label_13->setText(QApplication::translate("Display", "\345\210\206\350\276\250\347\216\207\357\274\232", 0));
        label_5->setText(QApplication::translate("Display", "\346\234\200\345\244\247\346\265\267\350\241\250\346\270\251\345\272\246\357\274\232", 0));
        label_10->setText(QApplication::translate("Display", "\346\225\260\346\215\256\346\235\245\346\272\220\357\274\232", 0));
        label_17->setText(QApplication::translate("Display", "m", 0));
        label->setText(QApplication::translate("Display", "\346\227\245\346\234\237\357\274\232", 0));
        label_3->setText(QApplication::translate("Display", "\347\273\217\345\272\246\357\274\232", 0));
        label_9->setText(QApplication::translate("Display", "1\302\260", 0));
        label_6->setText(QApplication::translate("Display", "20\302\260-40\302\260", 0));
        label_15->setText(QApplication::translate("Display", "\347\272\254\345\272\246\357\274\232", 0));
        label_11->setText(QApplication::translate("Display", "HY-2", 0));
        label_2->setText(QApplication::translate("Display", "20151011", 0));
        label_8->setText(QApplication::translate("Display", "30\302\260", 0));
        label_12->setText(QApplication::translate("Display", "0.25\302\260", 0));
        label_16->setText(QApplication::translate("Display", "\346\230\276\347\244\272\346\267\261\345\272\246\357\274\232", 0));
        label_4->setText(QApplication::translate("Display", "110\302\260-120\302\260", 0));
        label_22->setText(QString());
        label_19->setText(QApplication::translate("Display", "\345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_20->setText(QApplication::translate("Display", "\346\225\260\346\215\256\350\246\206\347\233\226\350\214\203\345\233\264\347\244\272\346\204\217\345\233\276", 0));
        label_18->setText(QString());
        pushButton_jias->setText(QString());
        pushButton_zt->setText(QString());
        pushButton_bf->setText(QString());
        pushButton_jians->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
