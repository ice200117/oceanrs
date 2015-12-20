/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->setEnabled(true);
        LoginDlg->resize(600, 430);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/images/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDlg->setWindowIcon(icon);
        pushButton = new QPushButton(LoginDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(430, 350, 150, 51));
        pushButton_2 = new QPushButton(LoginDlg);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(537, 40, 50, 50));
        label = new QLabel(LoginDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 214, 160, 129));

        retranslateUi(LoginDlg);
        QObject::connect(pushButton, SIGNAL(clicked()), LoginDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "\346\254\242\350\277\216", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
