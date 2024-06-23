/********************************************************************************
** Form generated from reading UI file 'debugwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWINDOW_H
#define UI_DEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_DebugWindow
{
public:
    QTreeView *treeView;

    void setupUi(QDialog *DebugWindow)
    {
        if (DebugWindow->objectName().isEmpty())
            DebugWindow->setObjectName("DebugWindow");
        DebugWindow->resize(400, 300);
        treeView = new QTreeView(DebugWindow);
        treeView->setObjectName("treeView");
        treeView->setGeometry(QRect(0, 0, 291, 201));

        retranslateUi(DebugWindow);

        QMetaObject::connectSlotsByName(DebugWindow);
    } // setupUi

    void retranslateUi(QDialog *DebugWindow)
    {
        DebugWindow->setWindowTitle(QCoreApplication::translate("DebugWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugWindow: public Ui_DebugWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWINDOW_H
