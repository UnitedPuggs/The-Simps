/********************************************************************************
** Form generated from reading UI file 'SalesReport.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESREPORT_H
#define UI_SALESREPORT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SalesReport
{
public:
    QWidget *centralwidget;
    QGroupBox *salesPage_groupBox;
    QDateEdit *salesPage_startDate;
    QLabel *label;
    QDateEdit *salesPage_endDate;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *execButton;
    QRadioButton *regularButton;
    QPushButton *pushButton;
    QRadioButton *allButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SalesReport)
    {
        if (SalesReport->objectName().isEmpty())
            SalesReport->setObjectName(QString::fromUtf8("SalesReport"));
        SalesReport->resize(259, 341);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SalesReport->sizePolicy().hasHeightForWidth());
        SalesReport->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(SalesReport);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        salesPage_groupBox = new QGroupBox(centralwidget);
        salesPage_groupBox->setObjectName(QString::fromUtf8("salesPage_groupBox"));
        salesPage_groupBox->setGeometry(QRect(10, 10, 231, 111));
        salesPage_startDate = new QDateEdit(salesPage_groupBox);
        salesPage_startDate->setObjectName(QString::fromUtf8("salesPage_startDate"));
        salesPage_startDate->setGeometry(QRect(90, 40, 121, 25));
        salesPage_startDate->setMaximumDateTime(QDateTime(QDate(2020, 3, 18), QTime(23, 59, 59)));
        salesPage_startDate->setMinimumDateTime(QDateTime(QDate(2020, 3, 12), QTime(0, 0, 0)));
        salesPage_startDate->setMaximumDate(QDate(2020, 3, 18));
        salesPage_startDate->setMinimumDate(QDate(2020, 3, 12));
        salesPage_startDate->setCurrentSection(QDateTimeEdit::DaySection);
        salesPage_startDate->setCalendarPopup(true);
        salesPage_startDate->setCurrentSectionIndex(1);
        salesPage_startDate->setDate(QDate(2020, 3, 12));
        label = new QLabel(salesPage_groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 81, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font.setPointSize(8);
        label->setFont(font);
        salesPage_endDate = new QDateEdit(salesPage_groupBox);
        salesPage_endDate->setObjectName(QString::fromUtf8("salesPage_endDate"));
        salesPage_endDate->setGeometry(QRect(90, 70, 121, 25));
        salesPage_endDate->setMaximumDateTime(QDateTime(QDate(2020, 3, 18), QTime(23, 59, 59)));
        salesPage_endDate->setMinimumDateTime(QDateTime(QDate(2020, 3, 12), QTime(0, 0, 0)));
        salesPage_endDate->setMinimumDate(QDate(2020, 3, 12));
        salesPage_endDate->setCurrentSection(QDateTimeEdit::DaySection);
        salesPage_endDate->setCalendarPopup(true);
        salesPage_endDate->setDate(QDate(2020, 3, 18));
        label_2 = new QLabel(salesPage_groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 71, 21));
        label_2->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 130, 231, 171));
        execButton = new QRadioButton(groupBox);
        execButton->setObjectName(QString::fromUtf8("execButton"));
        execButton->setGeometry(QRect(30, 30, 171, 22));
        regularButton = new QRadioButton(groupBox);
        regularButton->setObjectName(QString::fromUtf8("regularButton"));
        regularButton->setGeometry(QRect(30, 60, 171, 22));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 120, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(8);
        pushButton->setFont(font1);
        allButton = new QRadioButton(groupBox);
        allButton->setObjectName(QString::fromUtf8("allButton"));
        allButton->setGeometry(QRect(30, 90, 171, 22));
        allButton->setChecked(true);
        SalesReport->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SalesReport);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SalesReport->setStatusBar(statusbar);

        retranslateUi(SalesReport);
        QObject::connect(pushButton, SIGNAL(clicked()), SalesReport, SLOT(generateReport()));

        QMetaObject::connectSlotsByName(SalesReport);
    } // setupUi

    void retranslateUi(QMainWindow *SalesReport)
    {
        SalesReport->setWindowTitle(QCoreApplication::translate("SalesReport", "MainWindow", nullptr));
        salesPage_groupBox->setTitle(QCoreApplication::translate("SalesReport", "Select Date/Time", nullptr));
        salesPage_startDate->setDisplayFormat(QCoreApplication::translate("SalesReport", "M/d/yyyy", nullptr));
        label->setText(QCoreApplication::translate("SalesReport", "Start Date", nullptr));
        label_2->setText(QCoreApplication::translate("SalesReport", "End Date", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SalesReport", "Select Members", nullptr));
        execButton->setText(QCoreApplication::translate("SalesReport", "Include Only Executives", nullptr));
        regularButton->setText(QCoreApplication::translate("SalesReport", "Include Only Regulars", nullptr));
        pushButton->setText(QCoreApplication::translate("SalesReport", "Generate Report", nullptr));
        allButton->setText(QCoreApplication::translate("SalesReport", "Include All Members", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SalesReport: public Ui_SalesReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESREPORT_H
