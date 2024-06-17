#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "D:/NormKursac/KursacKirill/Headears/SupportFunctions.h"
#include <QMainWindow>
#include <QTextStream>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:



public slots:
    void startSignal(int string, int filelength);
    void Initial();
    void AddBtnBtn();
    void DelBtnBtn();
    void FindBtnBtn();
    void SaveBtn();
public:
    void WalkCirle(Circle *head);
    void WalkTree(Node *t);
    void PrintToTable();
    void AddRow(Circle* p);
    void WalkCirleWrite(Circle *head, QTextStream &writestream);
    void WalkTreeWrite(Node *t, QTextStream &writestream);
    void PrintToTableWrite(QTextStream &writestream);
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
