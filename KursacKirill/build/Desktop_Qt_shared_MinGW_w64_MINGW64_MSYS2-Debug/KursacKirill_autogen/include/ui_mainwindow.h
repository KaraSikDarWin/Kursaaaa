/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AddNodeBtn;
    QGroupBox *groupBox_5;
    QDateEdit *DateLine;
    QPushButton *DeleteNodeBtn;
    QPushButton *FindNodeBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QLineEdit *GovNumbLine;
    QGroupBox *groupBox_2;
    QLineEdit *PhonLine;
    QGroupBox *groupBox_3;
    QLineEdit *BrendLine;
    QGroupBox *groupBox_4;
    QLineEdit *ModelLine;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *BaseTable;
    QWidget *tab_2;
    QTextEdit *DebugTab;
    QPushButton *SaveBtnBtn;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(907, 500);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        AddNodeBtn = new QPushButton(centralwidget);
        AddNodeBtn->setObjectName("AddNodeBtn");
        AddNodeBtn->setGeometry(QRect(811, 405, 80, 18));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(590, 400, 201, 80));
        DateLine = new QDateEdit(groupBox_5);
        DateLine->setObjectName("DateLine");
        DateLine->setGeometry(QRect(10, 40, 181, 21));
        DeleteNodeBtn = new QPushButton(centralwidget);
        DeleteNodeBtn->setObjectName("DeleteNodeBtn");
        DeleteNodeBtn->setGeometry(QRect(811, 431, 80, 18));
        FindNodeBtn = new QPushButton(centralwidget);
        FindNodeBtn->setObjectName("FindNodeBtn");
        FindNodeBtn->setGeometry(QRect(811, 457, 80, 18));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 400, 581, 81));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        GovNumbLine = new QLineEdit(groupBox);
        GovNumbLine->setObjectName("GovNumbLine");
        GovNumbLine->setGeometry(QRect(10, 40, 121, 20));
        GovNumbLine->setMaxLength(6);

        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName("groupBox_2");
        PhonLine = new QLineEdit(groupBox_2);
        PhonLine->setObjectName("PhonLine");
        PhonLine->setGeometry(QRect(10, 40, 121, 20));
        PhonLine->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        PhonLine->setMaxLength(11);

        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName("groupBox_3");
        BrendLine = new QLineEdit(groupBox_3);
        BrendLine->setObjectName("BrendLine");
        BrendLine->setGeometry(QRect(10, 40, 121, 20));
        BrendLine->setMaxLength(30);

        horizontalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName("groupBox_4");
        ModelLine = new QLineEdit(groupBox_4);
        ModelLine->setObjectName("ModelLine");
        ModelLine->setGeometry(QRect(10, 40, 121, 20));
        ModelLine->setMaxLength(30);

        horizontalLayout_3->addWidget(groupBox_4);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 901, 361));
        tab = new QWidget();
        tab->setObjectName("tab");
        BaseTable = new QTableWidget(tab);
        if (BaseTable->columnCount() < 5)
            BaseTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qtablewidgetitem->setBackground(QColor(250, 0, 0));
        BaseTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(59, 0, 255));
        BaseTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setBackground(QColor(38, 255, 0));
        BaseTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setBackground(QColor(240, 253, 0));
        BaseTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setBackground(QColor(255, 0, 221));
        BaseTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        BaseTable->setObjectName("BaseTable");
        BaseTable->setGeometry(QRect(0, 0, 901, 341));
        BaseTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        BaseTable->setDragDropOverwriteMode(true);
        BaseTable->setDragDropMode(QAbstractItemView::DragDropMode::NoDragDrop);
        BaseTable->horizontalHeader()->setCascadingSectionResizes(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        DebugTab = new QTextEdit(tab_2);
        DebugTab->setObjectName("DebugTab");
        DebugTab->setGeometry(QRect(0, 0, 891, 341));
        DebugTab->setReadOnly(true);
        tabWidget->addTab(tab_2, QString());
        SaveBtnBtn = new QPushButton(centralwidget);
        SaveBtnBtn->setObjectName("SaveBtnBtn");
        SaveBtnBtn->setGeometry(QRect(810, 380, 81, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 907, 17));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\223\320\220\320\230", nullptr));
        AddNodeBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        DeleteNodeBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        FindNodeBtn->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\264\320\260\321\202\321\203", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\201. \320\275\320\276\320\274\320\265\321\200", nullptr));
        GovNumbLine->setInputMask(QString());
        GovNumbLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "X353AY", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        PhonLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "89084548343", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260 \320\260\320\262\321\202\320\276", nullptr));
        BrendLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nissan", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \320\260\320\262\321\202\320\276", nullptr));
        ModelLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        QTableWidgetItem *___qtablewidgetitem = BaseTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\201. \320\275\320\276\320\274\320\265\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = BaseTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = BaseTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260 \320\260\320\262\321\202\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = BaseTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \320\260\320\262\321\202\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = BaseTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\236\321\202\320\273\320\260\320\264\320\272\320\260", nullptr));
        SaveBtnBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
