/********************************************************************************
** Form generated from reading UI file 'Admin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QPushButton *customerButton;
    QPushButton *inventoryButton;
    QStackedWidget *stackedWidget;
    QWidget *customerPage;
    QTableView *customerPage_tableView;
    QPushButton *customerPage_addButton;
    QLineEdit *NameLineEdit;
    QLineEdit *MemberTypeLineEdit;
    QLineEdit *ExpirationDateLineEdit;
    QPushButton *customerPage_deleteButton;
    QLineEdit *IDLineEdit;
    QLabel *companyLabel_2;
    QWidget *inventoryPage;
    QTableView *InventoryTableView;
    QPushButton *inventoryPage_addButton;
    QPushButton *inventoryPage_editButton;
    QLineEdit *ItemNameLineEdit;
    QLineEdit *QuantityLineEdit;
    QLineEdit *InStockLineEdit;
    QPushButton *inventoryPage_deleteButton;
    QLineEdit *ItemPriceLineEdit;
    QLineEdit *RevenueLineEdit;
    QLabel *companyLabel_3;
    QLineEdit *inventoryPage_searchBar;
    QWidget *membershipPage;
    QPushButton *membershipPage_convertButton;
    QTableView *MembershipTableView;
    QLabel *companyLabel_4;
    QWidget *purchase;
    QLineEdit *idLine;
    QLineEdit *nameLine;
    QLineEdit *qtyLine;
    QLineEdit *priceLine;
    QPushButton *confirmButton;
    QLineEdit *dateLine;
    QTableView *testPurchase_inventoryTableView;
    QLineEdit *testPurchase_searchBar;
    QLabel *companyLabel;
    QPushButton *membershipButton;
    QPushButton *m;
    QLabel *copyrightLabel;
    QLabel *developerLabel;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(919, 387);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Admin->sizePolicy().hasHeightForWidth());
        Admin->setSizePolicy(sizePolicy);
        Admin->setSizeGripEnabled(false);
        customerButton = new QPushButton(Admin);
        customerButton->setObjectName(QString::fromUtf8("customerButton"));
        customerButton->setGeometry(QRect(20, 50, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Sans"));
        customerButton->setFont(font);
        inventoryButton = new QPushButton(Admin);
        inventoryButton->setObjectName(QString::fromUtf8("inventoryButton"));
        inventoryButton->setGeometry(QRect(20, 90, 121, 31));
        inventoryButton->setFont(font);
        stackedWidget = new QStackedWidget(Admin);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 0, 951, 831));
        customerPage = new QWidget();
        customerPage->setObjectName(QString::fromUtf8("customerPage"));
        customerPage_tableView = new QTableView(customerPage);
        customerPage_tableView->setObjectName(QString::fromUtf8("customerPage_tableView"));
        customerPage_tableView->setGeometry(QRect(0, 10, 562, 361));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customerPage_tableView->sizePolicy().hasHeightForWidth());
        customerPage_tableView->setSizePolicy(sizePolicy1);
        customerPage_tableView->setFrameShadow(QFrame::Plain);
        customerPage_addButton = new QPushButton(customerPage);
        customerPage_addButton->setObjectName(QString::fromUtf8("customerPage_addButton"));
        customerPage_addButton->setGeometry(QRect(690, 10, 61, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(9);
        customerPage_addButton->setFont(font1);
        NameLineEdit = new QLineEdit(customerPage);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        NameLineEdit->setGeometry(QRect(570, 10, 111, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS UI Gothic"));
        font2.setPointSize(12);
        NameLineEdit->setFont(font2);
        MemberTypeLineEdit = new QLineEdit(customerPage);
        MemberTypeLineEdit->setObjectName(QString::fromUtf8("MemberTypeLineEdit"));
        MemberTypeLineEdit->setGeometry(QRect(570, 70, 111, 21));
        MemberTypeLineEdit->setFont(font2);
        ExpirationDateLineEdit = new QLineEdit(customerPage);
        ExpirationDateLineEdit->setObjectName(QString::fromUtf8("ExpirationDateLineEdit"));
        ExpirationDateLineEdit->setGeometry(QRect(570, 100, 111, 21));
        ExpirationDateLineEdit->setFont(font2);
        customerPage_deleteButton = new QPushButton(customerPage);
        customerPage_deleteButton->setObjectName(QString::fromUtf8("customerPage_deleteButton"));
        customerPage_deleteButton->setGeometry(QRect(690, 70, 61, 51));
        customerPage_deleteButton->setFont(font1);
        IDLineEdit = new QLineEdit(customerPage);
        IDLineEdit->setObjectName(QString::fromUtf8("IDLineEdit"));
        IDLineEdit->setGeometry(QRect(570, 40, 111, 21));
        IDLineEdit->setFont(font2);
        companyLabel_2 = new QLabel(customerPage);
        companyLabel_2->setObjectName(QString::fromUtf8("companyLabel_2"));
        companyLabel_2->setGeometry(QRect(610, 220, 111, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Lucida Sans"));
        font3.setPointSize(8);
        companyLabel_2->setFont(font3);
        stackedWidget->addWidget(customerPage);
        inventoryPage = new QWidget();
        inventoryPage->setObjectName(QString::fromUtf8("inventoryPage"));
        InventoryTableView = new QTableView(inventoryPage);
        InventoryTableView->setObjectName(QString::fromUtf8("InventoryTableView"));
        InventoryTableView->setGeometry(QRect(0, 50, 561, 321));
        inventoryPage_addButton = new QPushButton(inventoryPage);
        inventoryPage_addButton->setObjectName(QString::fromUtf8("inventoryPage_addButton"));
        inventoryPage_addButton->setGeometry(QRect(710, 50, 51, 31));
        inventoryPage_addButton->setFont(font1);
        inventoryPage_editButton = new QPushButton(inventoryPage);
        inventoryPage_editButton->setObjectName(QString::fromUtf8("inventoryPage_editButton"));
        inventoryPage_editButton->setGeometry(QRect(710, 90, 51, 31));
        inventoryPage_editButton->setFont(font1);
        ItemNameLineEdit = new QLineEdit(inventoryPage);
        ItemNameLineEdit->setObjectName(QString::fromUtf8("ItemNameLineEdit"));
        ItemNameLineEdit->setGeometry(QRect(570, 50, 131, 21));
        ItemNameLineEdit->setFont(font2);
        QuantityLineEdit = new QLineEdit(inventoryPage);
        QuantityLineEdit->setObjectName(QString::fromUtf8("QuantityLineEdit"));
        QuantityLineEdit->setGeometry(QRect(640, 80, 61, 21));
        QuantityLineEdit->setFont(font2);
        InStockLineEdit = new QLineEdit(inventoryPage);
        InStockLineEdit->setObjectName(QString::fromUtf8("InStockLineEdit"));
        InStockLineEdit->setGeometry(QRect(570, 110, 131, 21));
        InStockLineEdit->setFont(font2);
        inventoryPage_deleteButton = new QPushButton(inventoryPage);
        inventoryPage_deleteButton->setObjectName(QString::fromUtf8("inventoryPage_deleteButton"));
        inventoryPage_deleteButton->setGeometry(QRect(710, 130, 51, 31));
        inventoryPage_deleteButton->setFont(font1);
        ItemPriceLineEdit = new QLineEdit(inventoryPage);
        ItemPriceLineEdit->setObjectName(QString::fromUtf8("ItemPriceLineEdit"));
        ItemPriceLineEdit->setGeometry(QRect(570, 80, 61, 21));
        ItemPriceLineEdit->setFont(font2);
        RevenueLineEdit = new QLineEdit(inventoryPage);
        RevenueLineEdit->setObjectName(QString::fromUtf8("RevenueLineEdit"));
        RevenueLineEdit->setGeometry(QRect(570, 140, 131, 21));
        RevenueLineEdit->setFont(font2);
        companyLabel_3 = new QLabel(inventoryPage);
        companyLabel_3->setObjectName(QString::fromUtf8("companyLabel_3"));
        companyLabel_3->setGeometry(QRect(610, 250, 111, 31));
        companyLabel_3->setFont(font3);
        inventoryPage_searchBar = new QLineEdit(inventoryPage);
        inventoryPage_searchBar->setObjectName(QString::fromUtf8("inventoryPage_searchBar"));
        inventoryPage_searchBar->setGeometry(QRect(0, 10, 281, 31));
        inventoryPage_searchBar->setFont(font1);
        stackedWidget->addWidget(inventoryPage);
        membershipPage = new QWidget();
        membershipPage->setObjectName(QString::fromUtf8("membershipPage"));
        membershipPage_convertButton = new QPushButton(membershipPage);
        membershipPage_convertButton->setObjectName(QString::fromUtf8("membershipPage_convertButton"));
        membershipPage_convertButton->setGeometry(QRect(10, 10, 161, 31));
        membershipPage_convertButton->setFont(font1);
        MembershipTableView = new QTableView(membershipPage);
        MembershipTableView->setObjectName(QString::fromUtf8("MembershipTableView"));
        MembershipTableView->setGeometry(QRect(0, 50, 561, 321));
        companyLabel_4 = new QLabel(membershipPage);
        companyLabel_4->setObjectName(QString::fromUtf8("companyLabel_4"));
        companyLabel_4->setGeometry(QRect(610, 190, 111, 31));
        companyLabel_4->setFont(font3);
        stackedWidget->addWidget(membershipPage);
        purchase = new QWidget();
        purchase->setObjectName(QString::fromUtf8("purchase"));
        idLine = new QLineEdit(purchase);
        idLine->setObjectName(QString::fromUtf8("idLine"));
        idLine->setGeometry(QRect(580, 50, 161, 21));
        nameLine = new QLineEdit(purchase);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setEnabled(false);
        nameLine->setGeometry(QRect(580, 80, 161, 21));
        qtyLine = new QLineEdit(purchase);
        qtyLine->setObjectName(QString::fromUtf8("qtyLine"));
        qtyLine->setGeometry(QRect(580, 140, 161, 21));
        priceLine = new QLineEdit(purchase);
        priceLine->setObjectName(QString::fromUtf8("priceLine"));
        priceLine->setEnabled(false);
        priceLine->setGeometry(QRect(580, 110, 161, 21));
        confirmButton = new QPushButton(purchase);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(620, 200, 91, 31));
        dateLine = new QLineEdit(purchase);
        dateLine->setObjectName(QString::fromUtf8("dateLine"));
        dateLine->setGeometry(QRect(580, 170, 161, 21));
        testPurchase_inventoryTableView = new QTableView(purchase);
        testPurchase_inventoryTableView->setObjectName(QString::fromUtf8("testPurchase_inventoryTableView"));
        testPurchase_inventoryTableView->setGeometry(QRect(0, 50, 561, 321));
        testPurchase_searchBar = new QLineEdit(purchase);
        testPurchase_searchBar->setObjectName(QString::fromUtf8("testPurchase_searchBar"));
        testPurchase_searchBar->setGeometry(QRect(0, 10, 281, 31));
        testPurchase_searchBar->setFont(font1);
        stackedWidget->addWidget(purchase);
        companyLabel = new QLabel(Admin);
        companyLabel->setObjectName(QString::fromUtf8("companyLabel"));
        companyLabel->setGeometry(QRect(20, 10, 131, 31));
        companyLabel->setFont(font3);
        membershipButton = new QPushButton(Admin);
        membershipButton->setObjectName(QString::fromUtf8("membershipButton"));
        membershipButton->setGeometry(QRect(20, 130, 121, 31));
        membershipButton->setFont(font);
        m = new QPushButton(Admin);
        m->setObjectName(QString::fromUtf8("m"));
        m->setGeometry(QRect(20, 170, 121, 31));
        m->setFont(font);
        copyrightLabel = new QLabel(Admin);
        copyrightLabel->setObjectName(QString::fromUtf8("copyrightLabel"));
        copyrightLabel->setGeometry(QRect(10, 360, 131, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(7);
        copyrightLabel->setFont(font4);
        developerLabel = new QLabel(Admin);
        developerLabel->setObjectName(QString::fromUtf8("developerLabel"));
        developerLabel->setGeometry(QRect(30, 340, 101, 21));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Lucida Sans Unicode"));
        font5.setPointSize(6);
        developerLabel->setFont(font5);

        retranslateUi(Admin);
        QObject::connect(confirmButton, SIGNAL(clicked()), Admin, SLOT(test_purchase()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Dialog", nullptr));
        customerButton->setText(QCoreApplication::translate("Admin", "Customer Info", nullptr));
        inventoryButton->setText(QCoreApplication::translate("Admin", "View Inventory", nullptr));
        customerPage_addButton->setText(QCoreApplication::translate("Admin", "Add", nullptr));
        NameLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Name...", nullptr));
        MemberTypeLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Member type...", nullptr));
        ExpirationDateLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Expiry Date...", nullptr));
        customerPage_deleteButton->setText(QCoreApplication::translate("Admin", "Delete", nullptr));
        IDLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "ID number...", nullptr));
        companyLabel_2->setText(QCoreApplication::translate("Admin", "\360\237\222\252 Bulk Club Inc.\360\237\222\252", nullptr));
        inventoryPage_addButton->setText(QCoreApplication::translate("Admin", "Add", nullptr));
        inventoryPage_editButton->setText(QCoreApplication::translate("Admin", "Edit", nullptr));
        ItemNameLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Item name...", nullptr));
        QuantityLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Qty...", nullptr));
        InStockLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Total Stock...", nullptr));
        inventoryPage_deleteButton->setText(QCoreApplication::translate("Admin", "Delete", nullptr));
        ItemPriceLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Price...", nullptr));
        RevenueLineEdit->setText(QString());
        RevenueLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Revenue...", nullptr));
        companyLabel_3->setText(QCoreApplication::translate("Admin", "\360\237\222\252 Bulk Club Inc.\360\237\222\252", nullptr));
        inventoryPage_searchBar->setPlaceholderText(QCoreApplication::translate("Admin", "Enter Item here...", nullptr));
        membershipPage_convertButton->setText(QCoreApplication::translate("Admin", "Convert Memberships", nullptr));
        companyLabel_4->setText(QCoreApplication::translate("Admin", "\360\237\222\252 Bulk Club Inc.\360\237\222\252", nullptr));
        idLine->setPlaceholderText(QCoreApplication::translate("Admin", "Customer ID...", nullptr));
        nameLine->setPlaceholderText(QCoreApplication::translate("Admin", "Item name...", nullptr));
        qtyLine->setPlaceholderText(QCoreApplication::translate("Admin", "Qty wanted...", nullptr));
        priceLine->setPlaceholderText(QCoreApplication::translate("Admin", "Price...", nullptr));
        confirmButton->setText(QCoreApplication::translate("Admin", "Make Purchase", nullptr));
        dateLine->setPlaceholderText(QCoreApplication::translate("Admin", "Date of purchase...", nullptr));
        testPurchase_searchBar->setPlaceholderText(QCoreApplication::translate("Admin", "Enter Item here...", nullptr));
        companyLabel->setText(QCoreApplication::translate("Admin", "\360\237\222\252 Bulk Club Inc.\360\237\222\252", nullptr));
        membershipButton->setText(QCoreApplication::translate("Admin", "Memberships", nullptr));
        m->setText(QCoreApplication::translate("Admin", "Test Purchase", nullptr));
        copyrightLabel->setText(QCoreApplication::translate("Admin", "\302\251 COPYRIGHT 2020 Bulk Club Inc. All Rights Reserved.", nullptr));
        developerLabel->setText(QCoreApplication::translate("Admin", "Developed by The Simps.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
