/********************************************************************************
** Form generated from reading UI file 'Manager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manager
{
public:
    QLabel *companyLabel;
    QStackedWidget *stackedWidget;
    QWidget *salesPage;
    QPushButton *salesPage_previewButton;
    QTableView *salesPage_tableView;
    QToolButton *sales_refresh;
    QLabel *executiveLabel;
    QLabel *normalLabel;
    QLineEdit *executiveLine;
    QLineEdit *normalLine;
    QLineEdit *sales_searchBar;
    QPushButton *sales_searchButton;
    QLabel *totalLabel;
    QLineEdit *grandTotalLin;
    QWidget *customerPage;
    QComboBox *customerPage_sortBox;
    QLineEdit *customerPage_searchBar;
    QToolButton *customerPage_refreshButton;
    QPushButton *customerPage_searchButton;
    QTableView *customerPage_tableView;
    QWidget *membershipPage;
    QToolButton *membershipPage_refreshButton;
    QLineEdit *membershipPage_searchBar;
    QPushButton *membershipPage_searchButton;
    QTableView *membershipPage_tableView;
    QWidget *inventoryPage;
    QToolButton *inventoryPage_refreshButton;
    QLineEdit *inventoryPage_searchBar;
    QPushButton *inventoryPage_searchButton;
    QComboBox *inventoryPage_sortBox;
    QTableView *inventoryPage_tableView;
    QWidget *rebatePage;
    QComboBox *rebatePage_sortBox;
    QToolButton *rebatePage_refreshButton;
    QTableView *rebatePage_tableView;
    QPushButton *inventoryButton;
    QPushButton *salesButton;
    QPushButton *membershipButton;
    QPushButton *customerButton;
    QPushButton *rebatesButton;

    void setupUi(QDialog *Manager)
    {
        if (Manager->objectName().isEmpty())
            Manager->setObjectName(QString::fromUtf8("Manager"));
        Manager->resize(920, 599);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Manager->sizePolicy().hasHeightForWidth());
        Manager->setSizePolicy(sizePolicy);
        Manager->setSizeGripEnabled(false);
        companyLabel = new QLabel(Manager);
        companyLabel->setObjectName(QString::fromUtf8("companyLabel"));
        companyLabel->setGeometry(QRect(10, 10, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Sans"));
        font.setPointSize(8);
        companyLabel->setFont(font);
        stackedWidget = new QStackedWidget(Manager);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(140, 0, 771, 601));
        salesPage = new QWidget();
        salesPage->setObjectName(QString::fromUtf8("salesPage"));
        salesPage_previewButton = new QPushButton(salesPage);
        salesPage_previewButton->setObjectName(QString::fromUtf8("salesPage_previewButton"));
        salesPage_previewButton->setGeometry(QRect(650, 10, 111, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(9);
        salesPage_previewButton->setFont(font1);
        salesPage_tableView = new QTableView(salesPage);
        salesPage_tableView->setObjectName(QString::fromUtf8("salesPage_tableView"));
        salesPage_tableView->setGeometry(QRect(0, 50, 761, 491));
        sales_refresh = new QToolButton(salesPage);
        sales_refresh->setObjectName(QString::fromUtf8("sales_refresh"));
        sales_refresh->setGeometry(QRect(0, 20, 26, 20));
        executiveLabel = new QLabel(salesPage);
        executiveLabel->setObjectName(QString::fromUtf8("executiveLabel"));
        executiveLabel->setGeometry(QRect(0, 540, 111, 16));
        normalLabel = new QLabel(salesPage);
        normalLabel->setObjectName(QString::fromUtf8("normalLabel"));
        normalLabel->setGeometry(QRect(0, 560, 91, 16));
        executiveLine = new QLineEdit(salesPage);
        executiveLine->setObjectName(QString::fromUtf8("executiveLine"));
        executiveLine->setGeometry(QRect(110, 542, 30, 16));
        executiveLine->setReadOnly(true);
        normalLine = new QLineEdit(salesPage);
        normalLine->setObjectName(QString::fromUtf8("normalLine"));
        normalLine->setGeometry(QRect(90, 560, 30, 16));
        normalLine->setReadOnly(true);
        sales_searchBar = new QLineEdit(salesPage);
        sales_searchBar->setObjectName(QString::fromUtf8("sales_searchBar"));
        sales_searchBar->setGeometry(QRect(30, 10, 251, 31));
        sales_searchButton = new QPushButton(salesPage);
        sales_searchButton->setObjectName(QString::fromUtf8("sales_searchButton"));
        sales_searchButton->setGeometry(QRect(290, 10, 71, 31));
        sales_searchButton->setFont(font1);
        totalLabel = new QLabel(salesPage);
        totalLabel->setObjectName(QString::fromUtf8("totalLabel"));
        totalLabel->setGeometry(QRect(600, 540, 41, 16));
        grandTotalLin = new QLineEdit(salesPage);
        grandTotalLin->setObjectName(QString::fromUtf8("grandTotalLin"));
        grandTotalLin->setGeometry(QRect(640, 542, 113, 16));
        grandTotalLin->setReadOnly(true);
        stackedWidget->addWidget(salesPage);
        customerPage = new QWidget();
        customerPage->setObjectName(QString::fromUtf8("customerPage"));
        customerPage->setFont(font1);
        customerPage_sortBox = new QComboBox(customerPage);
        customerPage_sortBox->setObjectName(QString::fromUtf8("customerPage_sortBox"));
        customerPage_sortBox->setGeometry(QRect(620, 10, 141, 31));
        customerPage_sortBox->setFont(font1);
        customerPage_searchBar = new QLineEdit(customerPage);
        customerPage_searchBar->setObjectName(QString::fromUtf8("customerPage_searchBar"));
        customerPage_searchBar->setGeometry(QRect(40, 10, 251, 31));
        customerPage_refreshButton = new QToolButton(customerPage);
        customerPage_refreshButton->setObjectName(QString::fromUtf8("customerPage_refreshButton"));
        customerPage_refreshButton->setGeometry(QRect(0, 10, 31, 31));
        customerPage_searchButton = new QPushButton(customerPage);
        customerPage_searchButton->setObjectName(QString::fromUtf8("customerPage_searchButton"));
        customerPage_searchButton->setGeometry(QRect(300, 10, 71, 31));
        customerPage_searchButton->setFont(font1);
        customerPage_tableView = new QTableView(customerPage);
        customerPage_tableView->setObjectName(QString::fromUtf8("customerPage_tableView"));
        customerPage_tableView->setGeometry(QRect(0, 50, 761, 541));
        stackedWidget->addWidget(customerPage);
        membershipPage = new QWidget();
        membershipPage->setObjectName(QString::fromUtf8("membershipPage"));
        membershipPage_refreshButton = new QToolButton(membershipPage);
        membershipPage_refreshButton->setObjectName(QString::fromUtf8("membershipPage_refreshButton"));
        membershipPage_refreshButton->setGeometry(QRect(0, 10, 31, 31));
        membershipPage_refreshButton->setFont(font1);
        membershipPage_searchBar = new QLineEdit(membershipPage);
        membershipPage_searchBar->setObjectName(QString::fromUtf8("membershipPage_searchBar"));
        membershipPage_searchBar->setGeometry(QRect(40, 10, 301, 31));
        membershipPage_searchBar->setFont(font1);
        membershipPage_searchButton = new QPushButton(membershipPage);
        membershipPage_searchButton->setObjectName(QString::fromUtf8("membershipPage_searchButton"));
        membershipPage_searchButton->setGeometry(QRect(350, 10, 71, 31));
        membershipPage_searchButton->setFont(font1);
        membershipPage_tableView = new QTableView(membershipPage);
        membershipPage_tableView->setObjectName(QString::fromUtf8("membershipPage_tableView"));
        membershipPage_tableView->setGeometry(QRect(0, 50, 761, 541));
        stackedWidget->addWidget(membershipPage);
        inventoryPage = new QWidget();
        inventoryPage->setObjectName(QString::fromUtf8("inventoryPage"));
        inventoryPage_refreshButton = new QToolButton(inventoryPage);
        inventoryPage_refreshButton->setObjectName(QString::fromUtf8("inventoryPage_refreshButton"));
        inventoryPage_refreshButton->setGeometry(QRect(0, 10, 31, 31));
        inventoryPage_refreshButton->setFont(font1);
        inventoryPage_searchBar = new QLineEdit(inventoryPage);
        inventoryPage_searchBar->setObjectName(QString::fromUtf8("inventoryPage_searchBar"));
        inventoryPage_searchBar->setGeometry(QRect(40, 10, 281, 31));
        inventoryPage_searchBar->setFont(font1);
        inventoryPage_searchButton = new QPushButton(inventoryPage);
        inventoryPage_searchButton->setObjectName(QString::fromUtf8("inventoryPage_searchButton"));
        inventoryPage_searchButton->setGeometry(QRect(330, 10, 71, 31));
        inventoryPage_searchButton->setFont(font1);
        inventoryPage_sortBox = new QComboBox(inventoryPage);
        inventoryPage_sortBox->setObjectName(QString::fromUtf8("inventoryPage_sortBox"));
        inventoryPage_sortBox->setGeometry(QRect(620, 10, 141, 31));
        inventoryPage_sortBox->setFont(font1);
        inventoryPage_tableView = new QTableView(inventoryPage);
        inventoryPage_tableView->setObjectName(QString::fromUtf8("inventoryPage_tableView"));
        inventoryPage_tableView->setGeometry(QRect(0, 50, 761, 541));
        stackedWidget->addWidget(inventoryPage);
        rebatePage = new QWidget();
        rebatePage->setObjectName(QString::fromUtf8("rebatePage"));
        rebatePage_sortBox = new QComboBox(rebatePage);
        rebatePage_sortBox->setObjectName(QString::fromUtf8("rebatePage_sortBox"));
        rebatePage_sortBox->setGeometry(QRect(620, 10, 141, 31));
        rebatePage_sortBox->setFont(font1);
        rebatePage_refreshButton = new QToolButton(rebatePage);
        rebatePage_refreshButton->setObjectName(QString::fromUtf8("rebatePage_refreshButton"));
        rebatePage_refreshButton->setGeometry(QRect(0, 10, 31, 31));
        rebatePage_refreshButton->setFont(font1);
        rebatePage_tableView = new QTableView(rebatePage);
        rebatePage_tableView->setObjectName(QString::fromUtf8("rebatePage_tableView"));
        rebatePage_tableView->setGeometry(QRect(0, 50, 761, 541));
        stackedWidget->addWidget(rebatePage);
        inventoryButton = new QPushButton(Manager);
        inventoryButton->setObjectName(QString::fromUtf8("inventoryButton"));
        inventoryButton->setGeometry(QRect(10, 170, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lucida Sans"));
        inventoryButton->setFont(font2);
        salesButton = new QPushButton(Manager);
        salesButton->setObjectName(QString::fromUtf8("salesButton"));
        salesButton->setGeometry(QRect(10, 50, 121, 31));
        salesButton->setFont(font);
        membershipButton = new QPushButton(Manager);
        membershipButton->setObjectName(QString::fromUtf8("membershipButton"));
        membershipButton->setGeometry(QRect(10, 130, 121, 31));
        membershipButton->setFont(font2);
        customerButton = new QPushButton(Manager);
        customerButton->setObjectName(QString::fromUtf8("customerButton"));
        customerButton->setGeometry(QRect(10, 90, 121, 31));
        customerButton->setFont(font);
        rebatesButton = new QPushButton(Manager);
        rebatesButton->setObjectName(QString::fromUtf8("rebatesButton"));
        rebatesButton->setGeometry(QRect(10, 210, 121, 31));
        rebatesButton->setFont(font2);

        retranslateUi(Manager);
        QObject::connect(inventoryPage_searchBar, SIGNAL(textChanged(QString)), Manager, SLOT(refreshSearch()));
        QObject::connect(salesPage_tableView, SIGNAL(viewportEntered()), Manager, SLOT(generateReport()));
        QObject::connect(sales_refresh, SIGNAL(clicked()), Manager, SLOT(generateReport()));
        QObject::connect(membershipPage_searchBar, SIGNAL(textChanged(QString)), Manager, SLOT(refreshMonthsSearch()));
        QObject::connect(customerPage_searchBar, SIGNAL(textChanged(QString)), Manager, SLOT(refreshCustomerSearch()));
        QObject::connect(sales_searchBar, SIGNAL(textChanged(QString)), Manager, SLOT(refreshSalesSearch()));
        QObject::connect(sales_searchButton, SIGNAL(clicked()), Manager, SLOT(sales_search()));

        QMetaObject::connectSlotsByName(Manager);
    } // setupUi

    void retranslateUi(QDialog *Manager)
    {
        Manager->setWindowTitle(QCoreApplication::translate("Manager", "Dialog", nullptr));
        companyLabel->setText(QCoreApplication::translate("Manager", "\360\237\222\252 Bulk Club Inc.\360\237\222\252", nullptr));
        salesPage_previewButton->setText(QCoreApplication::translate("Manager", "Preview Report", nullptr));
        sales_refresh->setText(QCoreApplication::translate("Manager", "\360\237\227\230", nullptr));
        executiveLabel->setText(QCoreApplication::translate("Manager", "Executive Shoppers:", nullptr));
        normalLabel->setText(QCoreApplication::translate("Manager", "Normal Shoppers:", nullptr));
        sales_searchBar->setPlaceholderText(QCoreApplication::translate("Manager", "Enter Customer Name/ID here...", nullptr));
        sales_searchButton->setText(QCoreApplication::translate("Manager", "Search", nullptr));
        totalLabel->setText(QCoreApplication::translate("Manager", "Total: $", nullptr));
        customerPage_searchBar->setPlaceholderText(QCoreApplication::translate("Manager", "Enter Customer Name/ID here...", nullptr));
        customerPage_refreshButton->setText(QCoreApplication::translate("Manager", "\360\237\227\230", nullptr));
        customerPage_searchButton->setText(QCoreApplication::translate("Manager", "Search", nullptr));
        membershipPage_refreshButton->setText(QCoreApplication::translate("Manager", "\360\237\227\230", nullptr));
        membershipPage_searchBar->setPlaceholderText(QCoreApplication::translate("Manager", "Enter in a month e.g. November...", nullptr));
        membershipPage_searchButton->setText(QCoreApplication::translate("Manager", "Search", nullptr));
        inventoryPage_refreshButton->setText(QCoreApplication::translate("Manager", "\360\237\227\230", nullptr));
        inventoryPage_searchBar->setPlaceholderText(QCoreApplication::translate("Manager", "Enter Item here...", nullptr));
        inventoryPage_searchButton->setText(QCoreApplication::translate("Manager", "Search", nullptr));
        rebatePage_refreshButton->setText(QCoreApplication::translate("Manager", "\360\237\227\230", nullptr));
        inventoryButton->setText(QCoreApplication::translate("Manager", "Inventory List", nullptr));
        salesButton->setText(QCoreApplication::translate("Manager", "Sales Info", nullptr));
        membershipButton->setText(QCoreApplication::translate("Manager", "Memberships", nullptr));
        customerButton->setText(QCoreApplication::translate("Manager", "Customer Details", nullptr));
        rebatesButton->setText(QCoreApplication::translate("Manager", "View Rebates", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manager: public Ui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
