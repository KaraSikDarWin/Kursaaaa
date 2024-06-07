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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QSplitter *splitter;
    QSpinBox *HashTableSizeIn;
    QPushButton *HashTableInBtn;

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

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "Dialog", nullptr));
        HashTableInBtn->setText(QCoreApplication::translate("StartWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
