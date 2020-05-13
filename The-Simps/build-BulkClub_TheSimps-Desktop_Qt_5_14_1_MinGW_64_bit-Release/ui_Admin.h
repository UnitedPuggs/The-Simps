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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QPushButton *customerButton;
    QPushButton *inventoryButton;
    QStackedWidget *stackedWidget;
    QWidget *customerPage;
    QToolButton *customerPage_refreshButton;
    QTableView *customerPage_tableView;
    QLabel *label_2;
    QPushButton *customerPage_addButton;
    QLineEdit *RebateLineEdit;
    QLineEdit *NameLineEdit;
    QLabel *label_4;
    QLineEdit *MemberTypeLineEdit;
    QLabel *label;
    QLineEdit *ExpirationDateLineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *TotalSpentLineEdit;
    QPushButton *customerPage_deleteButton;
    QLineEdit *IDLineEdit;
    QWidget *inventoryPage;
    QToolButton *inventoryPage_refreshButton;
    QTableView *InventoryTableView;
    QPushButton *inventoryPage_addButton;
    QPushButton *inventoryPage_editButton;
    QLabel *label_7;
    QLineEdit *ItemNameLineEdit;
    QLabel *label_8;
    QLineEdit *QuantityLineEdit;
    QLabel *label_9;
    QLineEdit *InStockLineEdit;
    QLabel *label_11;
    QPushButton *inventoryPage_deleteButton;
    QLineEdit *ItemPriceLineEdit;
    QLabel *label_10;
    QLineEdit *RevenueLineEdit;
    QWidget *membershipPage;
    QPushButton *membershipPage_convertButton;
    QToolButton *membershipPage_refreshButton;
    QTableView *MembershipTableView;
    QWidget *purchase;
    QLineEdit *idLine;
    QLabel *customerLabel;
    QLineEdit *nameLine;
    QLabel *nameLabel;
    QLineEdit *qtyLine;
    QLabel *qtyLabel;
    QLineEdit *priceLine;
    QLabel *priceLabel;
    QPushButton *confirmButton;
    QLabel *dateLabel;
    QLineEdit *dateLine;
    QLabel *companyLabel;
    QPushButton *membershipButton;
    QPushButton *m;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(1118, 664);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Admin->sizePolicy().hasHeightForWidth());
        Admin->setSizePolicy(sizePolicy);
        Admin->setSizeGripEnabled(false);
        customerButton = new QPushButton(Admin);
        customerButton->setObjectName(QString::fromUtf8("customerButton"));
        customerButton->setGeometry(QRect(20, 280, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Sans"));
        customerButton->setFont(font);
        inventoryButton = new QPushButton(Admin);
        inventoryButton->setObjectName(QString::fromUtf8("inventoryButton"));
        inventoryButton->setGeometry(QRect(20, 320, 121, 31));
        inventoryButton->setFont(font);
        stackedWidget = new QStackedWidget(Admin);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 20, 911, 811));
        customerPage = new QWidget();
        customerPage->setObjectName(QString::fromUtf8("customerPage"));
        customerPage_refreshButton = new QToolButton(customerPage);
        customerPage_refreshButton->setObjectName(QString::fromUtf8("customerPage_refreshButton"));
        customerPage_refreshButton->setGeometry(QRect(0, 210, 31, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(9);
        customerPage_refreshButton->setFont(font1);
        customerPage_tableView = new QTableView(customerPage);
        customerPage_tableView->setObjectName(QString::fromUtf8("customerPage_tableView"));
        customerPage_tableView->setGeometry(QRect(10, 250, 562, 341));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customerPage_tableView->sizePolicy().hasHeightForWidth());
        customerPage_tableView->setSizePolicy(sizePolicy1);
        customerPage_tableView->setFrameShadow(QFrame::Plain);
        label_2 = new QLabel(customerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS UI Gothic"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        customerPage_addButton = new QPushButton(customerPage);
        customerPage_addButton->setObjectName(QString::fromUtf8("customerPage_addButton"));
        customerPage_addButton->setGeometry(QRect(700, 30, 181, 71));
        customerPage_addButton->setFont(font1);
        RebateLineEdit = new QLineEdit(customerPage);
        RebateLineEdit->setObjectName(QString::fromUtf8("RebateLineEdit"));
        RebateLineEdit->setGeometry(QRect(480, 150, 131, 31));
        RebateLineEdit->setFont(font2);
        NameLineEdit = new QLineEdit(customerPage);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        NameLineEdit->setGeometry(QRect(190, 30, 421, 31));
        NameLineEdit->setFont(font2);
        label_4 = new QLabel(customerPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 150, 171, 31));
        label_4->setFont(font2);
        MemberTypeLineEdit = new QLineEdit(customerPage);
        MemberTypeLineEdit->setObjectName(QString::fromUtf8("MemberTypeLineEdit"));
        MemberTypeLineEdit->setGeometry(QRect(190, 110, 131, 31));
        MemberTypeLineEdit->setFont(font2);
        label = new QLabel(customerPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 81, 31));
        label->setFont(font2);
        ExpirationDateLineEdit = new QLineEdit(customerPage);
        ExpirationDateLineEdit->setObjectName(QString::fromUtf8("ExpirationDateLineEdit"));
        ExpirationDateLineEdit->setGeometry(QRect(190, 150, 131, 31));
        ExpirationDateLineEdit->setFont(font2);
        label_5 = new QLabel(customerPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 110, 141, 31));
        label_5->setFont(font2);
        label_6 = new QLabel(customerPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 150, 141, 31));
        label_6->setFont(font2);
        label_3 = new QLabel(customerPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 141, 31));
        label_3->setFont(font2);
        TotalSpentLineEdit = new QLineEdit(customerPage);
        TotalSpentLineEdit->setObjectName(QString::fromUtf8("TotalSpentLineEdit"));
        TotalSpentLineEdit->setGeometry(QRect(480, 110, 131, 31));
        TotalSpentLineEdit->setFont(font2);
        customerPage_deleteButton = new QPushButton(customerPage);
        customerPage_deleteButton->setObjectName(QString::fromUtf8("customerPage_deleteButton"));
        customerPage_deleteButton->setGeometry(QRect(700, 120, 181, 71));
        customerPage_deleteButton->setFont(font1);
        IDLineEdit = new QLineEdit(customerPage);
        IDLineEdit->setObjectName(QString::fromUtf8("IDLineEdit"));
        IDLineEdit->setGeometry(QRect(190, 70, 421, 31));
        IDLineEdit->setFont(font2);
        stackedWidget->addWidget(customerPage);
        inventoryPage = new QWidget();
        inventoryPage->setObjectName(QString::fromUtf8("inventoryPage"));
        inventoryPage_refreshButton = new QToolButton(inventoryPage);
        inventoryPage_refreshButton->setObjectName(QString::fromUtf8("inventoryPage_refreshButton"));
        inventoryPage_refreshButton->setGeometry(QRect(0, 230, 31, 31));
        inventoryPage_refreshButton->setFont(font1);
        InventoryTableView = new QTableView(inventoryPage);
        InventoryTableView->setObjectName(QString::fromUtf8("InventoryTableView"));
        InventoryTableView->setGeometry(QRect(0, 270, 671, 321));
        inventoryPage_addButton = new QPushButton(inventoryPage);
        inventoryPage_addButton->setObjectName(QString::fromUtf8("inventoryPage_addButton"));
        inventoryPage_addButton->setGeometry(QRect(700, 80, 181, 41));
        inventoryPage_addButton->setFont(font1);
        inventoryPage_editButton = new QPushButton(inventoryPage);
        inventoryPage_editButton->setObjectName(QString::fromUtf8("inventoryPage_editButton"));
        inventoryPage_editButton->setGeometry(QRect(700, 20, 181, 41));
        inventoryPage_editButton->setFont(font1);
        label_7 = new QLabel(inventoryPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 140, 171, 31));
        label_7->setFont(font2);
        ItemNameLineEdit = new QLineEdit(inventoryPage);
        ItemNameLineEdit->setObjectName(QString::fromUtf8("ItemNameLineEdit"));
        ItemNameLineEdit->setGeometry(QRect(190, 20, 311, 31));
        ItemNameLineEdit->setFont(font2);
        label_8 = new QLabel(inventoryPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 60, 121, 31));
        label_8->setFont(font2);
        QuantityLineEdit = new QLineEdit(inventoryPage);
        QuantityLineEdit->setObjectName(QString::fromUtf8("QuantityLineEdit"));
        QuantityLineEdit->setGeometry(QRect(190, 100, 311, 31));
        QuantityLineEdit->setFont(font2);
        label_9 = new QLabel(inventoryPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 20, 141, 31));
        label_9->setFont(font2);
        InStockLineEdit = new QLineEdit(inventoryPage);
        InStockLineEdit->setObjectName(QString::fromUtf8("InStockLineEdit"));
        InStockLineEdit->setGeometry(QRect(190, 140, 311, 31));
        InStockLineEdit->setFont(font2);
        label_11 = new QLabel(inventoryPage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 100, 141, 31));
        label_11->setFont(font2);
        inventoryPage_deleteButton = new QPushButton(inventoryPage);
        inventoryPage_deleteButton->setObjectName(QString::fromUtf8("inventoryPage_deleteButton"));
        inventoryPage_deleteButton->setGeometry(QRect(700, 140, 181, 41));
        inventoryPage_deleteButton->setFont(font1);
        ItemPriceLineEdit = new QLineEdit(inventoryPage);
        ItemPriceLineEdit->setObjectName(QString::fromUtf8("ItemPriceLineEdit"));
        ItemPriceLineEdit->setGeometry(QRect(190, 60, 311, 31));
        ItemPriceLineEdit->setFont(font2);
        label_10 = new QLabel(inventoryPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 180, 171, 31));
        label_10->setFont(font2);
        RevenueLineEdit = new QLineEdit(inventoryPage);
        RevenueLineEdit->setObjectName(QString::fromUtf8("RevenueLineEdit"));
        RevenueLineEdit->setGeometry(QRect(190, 180, 311, 31));
        RevenueLineEdit->setFont(font2);
        stackedWidget->addWidget(inventoryPage);
        membershipPage = new QWidget();
        membershipPage->setObjectName(QString::fromUtf8("membershipPage"));
        membershipPage_convertButton = new QPushButton(membershipPage);
        membershipPage_convertButton->setObjectName(QString::fromUtf8("membershipPage_convertButton"));
        membershipPage_convertButton->setGeometry(QRect(40, 10, 161, 31));
        membershipPage_convertButton->setFont(font1);
        membershipPage_refreshButton = new QToolButton(membershipPage);
        membershipPage_refreshButton->setObjectName(QString::fromUtf8("membershipPage_refreshButton"));
        membershipPage_refreshButton->setGeometry(QRect(0, 10, 31, 31));
        membershipPage_refreshButton->setFont(font1);
        MembershipTableView = new QTableView(membershipPage);
        MembershipTableView->setObjectName(QString::fromUtf8("MembershipTableView"));
        MembershipTableView->setGeometry(QRect(0, 50, 544, 541));
        stackedWidget->addWidget(membershipPage);
        purchase = new QWidget();
        purchase->setObjectName(QString::fromUtf8("purchase"));
        idLine = new QLineEdit(purchase);
        idLine->setObjectName(QString::fromUtf8("idLine"));
        idLine->setGeometry(QRect(120, 210, 113, 21));
        customerLabel = new QLabel(purchase);
        customerLabel->setObjectName(QString::fromUtf8("customerLabel"));
        customerLabel->setGeometry(QRect(150, 190, 61, 16));
        nameLine = new QLineEdit(purchase);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(120, 270, 113, 21));
        nameLabel = new QLabel(purchase);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(150, 250, 61, 16));
        qtyLine = new QLineEdit(purchase);
        qtyLine->setObjectName(QString::fromUtf8("qtyLine"));
        qtyLine->setGeometry(QRect(120, 330, 113, 21));
        qtyLabel = new QLabel(purchase);
        qtyLabel->setObjectName(QString::fromUtf8("qtyLabel"));
        qtyLabel->setGeometry(QRect(150, 310, 47, 13));
        priceLine = new QLineEdit(purchase);
        priceLine->setObjectName(QString::fromUtf8("priceLine"));
        priceLine->setGeometry(QRect(120, 390, 113, 21));
        priceLabel = new QLabel(purchase);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));
        priceLabel->setGeometry(QRect(160, 370, 31, 16));
        confirmButton = new QPushButton(purchase);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(340, 300, 181, 71));
        dateLabel = new QLabel(purchase);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(160, 430, 47, 13));
        dateLine = new QLineEdit(purchase);
        dateLine->setObjectName(QString::fromUtf8("dateLine"));
        dateLine->setGeometry(QRect(120, 450, 113, 21));
        stackedWidget->addWidget(purchase);
        companyLabel = new QLabel(Admin);
        companyLabel->setObjectName(QString::fromUtf8("companyLabel"));
        companyLabel->setGeometry(QRect(20, 240, 131, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Lucida Sans"));
        font3.setPointSize(8);
        companyLabel->setFont(font3);
        membershipButton = new QPushButton(Admin);
        membershipButton->setObjectName(QString::fromUtf8("membershipButton"));
        membershipButton->setGeometry(QRect(20, 360, 121, 31));
        membershipButton->setFont(font);
        m = new QPushButton(Admin);
        m->setObjectName(QString::fromUtf8("m"));
        m->setGeometry(QRect(20, 400, 121, 31));
        m->setFont(font);

        retranslateUi(Admin);
        QObject::connect(confirmButton, SIGNAL(clicked()), Admin, SLOT(test_purchase()));

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Dialog", nullptr));
        customerButton->setText(QCoreApplication::translate("Admin", "Customer Info", nullptr));
        inventoryButton->setText(QCoreApplication::translate("Admin", "View Inventory", nullptr));
        customerPage_refreshButton->setText(QCoreApplication::translate("Admin", "\360\237\227\230", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "ID Number:", nullptr));
        customerPage_addButton->setText(QCoreApplication::translate("Admin", "Add Customer", nullptr));
        label_4->setText(QCoreApplication::translate("Admin", "Experation Date:", nullptr));
        label->setText(QCoreApplication::translate("Admin", "Name:", nullptr));
        label_5->setText(QCoreApplication::translate("Admin", "Total Spent:", nullptr));
        label_6->setText(QCoreApplication::translate("Admin", "Rebate:", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "Member Type:", nullptr));
        customerPage_deleteButton->setText(QCoreApplication::translate("Admin", "Delete Customer", nullptr));
        inventoryPage_refreshButton->setText(QCoreApplication::translate("Admin", "\360\237\227\230", nullptr));
        inventoryPage_addButton->setText(QCoreApplication::translate("Admin", "Add Item", nullptr));
        inventoryPage_editButton->setText(QCoreApplication::translate("Admin", "Edit Item", nullptr));
        label_7->setText(QCoreApplication::translate("Admin", "In Stock?", nullptr));
        label_8->setText(QCoreApplication::translate("Admin", "Item Price", nullptr));
        label_9->setText(QCoreApplication::translate("Admin", "Item Name:", nullptr));
        label_11->setText(QCoreApplication::translate("Admin", "Quantity", nullptr));
        inventoryPage_deleteButton->setText(QCoreApplication::translate("Admin", "Delete Item", nullptr));
        label_10->setText(QCoreApplication::translate("Admin", "Revenue", nullptr));
        membershipPage_convertButton->setText(QCoreApplication::translate("Admin", "Convert Memberships", nullptr));
        membershipPage_refreshButton->setText(QCoreApplication::translate("Admin", "\360\237\227\230", nullptr));
        customerLabel->setText(QCoreApplication::translate("Admin", "CustomerID", nullptr));
        nameLabel->setText(QCoreApplication::translate("Admin", "Item Name", nullptr));
        qtyLabel->setText(QCoreApplication::translate("Admin", "Quantity", nullptr));
        priceLabel->setText(QCoreApplication::translate("Admin", "Price", nullptr));
        confirmButton->setText(QCoreApplication::translate("Admin", "Make Purchase", nullptr));
        dateLabel->setText(QCoreApplication::translate("Admin", "Date", nullptr));
        companyLabel->setText(QCoreApplication::translate("Admin", "\360\237\222\252 Bulk Club Inc.\360\237\222\252", nullptr));
        membershipButton->setText(QCoreApplication::translate("Admin", "Memberships", nullptr));
        m->setText(QCoreApplication::translate("Admin", "Test Purchase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
