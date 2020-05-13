/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *UsernameLineEdit;
    QLineEdit *PasswordLineEdit;
    QLabel *companyLabel;
    QLabel *developerLabel;
    QLabel *copyrightLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWindow->sizePolicy().hasHeightForWidth());
        mainWindow->setSizePolicy(sizePolicy);
        mainWindow->setAnimated(false);
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 270, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        pushButton->setFont(font);
        UsernameLineEdit = new QLineEdit(centralwidget);
        UsernameLineEdit->setObjectName(QString::fromUtf8("UsernameLineEdit"));
        UsernameLineEdit->setGeometry(QRect(200, 180, 241, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Sans"));
        font1.setPointSize(9);
        UsernameLineEdit->setFont(font1);
        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setEnabled(true);
        PasswordLineEdit->setGeometry(QRect(200, 220, 241, 31));
        PasswordLineEdit->setFont(font1);
        PasswordLineEdit->setInputMask(QString::fromUtf8(""));
        PasswordLineEdit->setText(QString::fromUtf8(""));
        PasswordLineEdit->setEchoMode(QLineEdit::Password);
        companyLabel = new QLabel(centralwidget);
        companyLabel->setObjectName(QString::fromUtf8("companyLabel"));
        companyLabel->setGeometry(QRect(200, 120, 241, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lucida Sans"));
        font2.setPointSize(14);
        companyLabel->setFont(font2);
        developerLabel = new QLabel(centralwidget);
        developerLabel->setObjectName(QString::fromUtf8("developerLabel"));
        developerLabel->setGeometry(QRect(260, 390, 131, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Lucida Sans Unicode"));
        font3.setPointSize(6);
        developerLabel->setFont(font3);
        copyrightLabel = new QLabel(centralwidget);
        copyrightLabel->setObjectName(QString::fromUtf8("copyrightLabel"));
        copyrightLabel->setGeometry(QRect(170, 410, 311, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(7);
        copyrightLabel->setFont(font4);
        mainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(mainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainWindow->setStatusBar(statusbar);

        retranslateUi(mainWindow);
        QObject::connect(PasswordLineEdit, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "Bulk Club Inc. \360\237\222\252 Powered by The Simps", nullptr));
        pushButton->setText(QCoreApplication::translate("mainWindow", "Login", nullptr));
        UsernameLineEdit->setInputMask(QString());
        UsernameLineEdit->setPlaceholderText(QCoreApplication::translate("mainWindow", "Enter username here...", nullptr));
        PasswordLineEdit->setPlaceholderText(QCoreApplication::translate("mainWindow", "Enter password here...", nullptr));
        companyLabel->setText(QCoreApplication::translate("mainWindow", "\360\237\222\252 Bulk Club Inc. \360\237\222\252", nullptr));
        developerLabel->setText(QCoreApplication::translate("mainWindow", "Developed by The Simps.", nullptr));
        copyrightLabel->setText(QCoreApplication::translate("mainWindow", "\302\251 COPYRIGHT 2020 Bulk Club Inc. All Rights Reserved.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
