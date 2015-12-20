/********************************************************************************
** Form generated from reading UI file 'selectfile.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTFILE_H
#define UI_SELECTFILE_H

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

class Ui_SelectFile
{
public:
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QPushButton *pushButton_5;

    void setupUi(QDialog *SelectFile)
    {
        if (SelectFile->objectName().isEmpty())
            SelectFile->setObjectName(QStringLiteral("SelectFile"));
        SelectFile->resize(763, 429);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        SelectFile->setFont(font);
        SelectFile->setStyleSheet(QStringLiteral(""));
        pushButton_4 = new QPushButton(SelectFile);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 380, 156, 43));
        label_4 = new QLabel(SelectFile);
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
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setMouseTracking(false);
        label_4->setContextMenuPolicy(Qt::ActionsContextMenu);
        label_4->setAcceptDrops(false);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(SelectFile);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(182, 158, 481, 20));
        label_2 = new QLabel(SelectFile);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 200, 151, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label = new QLabel(SelectFile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 150, 121, 31));
        label->setFont(font2);
        pushButton = new QPushButton(SelectFile);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(670, 156, 31, 23));
        label_5 = new QLabel(SelectFile);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 174, 147, 98));
        lineEdit_2 = new QLineEdit(SelectFile);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(182, 212, 481, 20));
        pushButton_2 = new QPushButton(SelectFile);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 210, 31, 23));
        lineEdit_3 = new QLineEdit(SelectFile);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(182, 266, 481, 20));
        pushButton_3 = new QPushButton(SelectFile);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(670, 264, 31, 23));
        label_3 = new QLabel(SelectFile);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 260, 141, 31));
        label_3->setFont(font2);
        pushButton_5 = new QPushButton(SelectFile);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(720, 0, 40, 40));
        pushButton_4->raise();
        label_4->raise();
        lineEdit->raise();
        label_2->raise();
        label->raise();
        pushButton->raise();
        lineEdit_2->raise();
        pushButton_2->raise();
        lineEdit_3->raise();
        pushButton_3->raise();
        label_3->raise();
        label_5->raise();
        pushButton_5->raise();

        retranslateUi(SelectFile);

        QMetaObject::connectSlotsByName(SelectFile);
    } // setupUi

    void retranslateUi(QDialog *SelectFile)
    {
        SelectFile->setWindowTitle(QApplication::translate("SelectFile", "\350\257\267\351\200\211\346\213\251", 0));
        pushButton_4->setText(QString());
        label_4->setText(QApplication::translate("SelectFile", "label_4", 0));
        label_2->setText(QApplication::translate("SelectFile", "\350\276\223\345\205\245\346\267\261\345\272\246\346\225\260\346\215\256\357\274\232", 0));
        label->setText(QApplication::translate("SelectFile", "\350\276\223 \345\205\245 \346\225\260 \346\215\256 \357\274\232", 0));
        pushButton->setText(QApplication::translate("SelectFile", "...", 0));
        label_5->setText(QString());
        pushButton_2->setText(QApplication::translate("SelectFile", "...", 0));
        pushButton_3->setText(QApplication::translate("SelectFile", "...", 0));
        label_3->setText(QApplication::translate("SelectFile", "\350\276\223\345\207\272\346\225\260\346\215\256\350\267\257\345\276\204\357\274\232", 0));
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectFile: public Ui_SelectFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTFILE_H
