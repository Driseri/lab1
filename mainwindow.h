#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <protein.h>
#include "add.h"
#include "importwindow.h"
#include "exportwindow.h"
#include "show.h"
#include "sumwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void sendData(Protein **ms, int count);
    void sData(Protein**,int *count);

protected:
    Protein** prota;
    int count;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Add *addWindow;
    ImportWindow *impWindow;
    ExportWindow *exWindow;
    Show *showWind;
    SumWindow *sumWind;
};
#endif // MAINWINDOW_H
