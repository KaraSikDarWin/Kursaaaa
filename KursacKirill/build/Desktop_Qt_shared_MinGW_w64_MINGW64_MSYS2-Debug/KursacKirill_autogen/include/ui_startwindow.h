/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QSplitter *splitter;
    QSpinBox *HashTableSizeIn;
    QPushButton *HashTableInBtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(231, 187);
        splitter = new QSplitter(StartWindow);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(11, 140, 211, 21));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        HashTableSizeIn = new QSpinBox(splitter);
        HashTableSizeIn->setObjectName("HashTableSizeIn");
        splitter->addWidget(HashTableSizeIn);
        HashTableInBtn = new QPushButton(splitter);
        HashTableInBtn->setObjectName("HashTableInBtn");
        HashTableInBtn->setAutoFillBackground(false);
        splitter->addWidget(HashTableInBtn);
        widget = new QWidget(StartWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 0, 211, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);


        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "Dialog", nullptr));
        HashTableInBtn->setText(QCoreApplication::translate("StartWindow", "OK", nullptr));
        label->setText(QCoreApplication::translate("StartWindow", "\320\227\320\264\321\200\320\260\320\262\321\201\321\202\320\262\321\203\320\271\321\202\320\265!", nullptr));
        label_2->setText(QCoreApplication::translate("StartWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \321\205\321\215\321\210 \321\202\320\260\320\261\320\273\320\270\321\206\321\213.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
