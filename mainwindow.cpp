#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    prota=new Protein* [25];
    count = 0;

    addWindow = new Add();
    connect(this,SIGNAL(sendData(Protein**,int)),addWindow,SLOT(receiveData(Protein**,int)));

    impWindow = new ImportWindow();
    connect(this,SIGNAL(sendData(Protein**,int)),impWindow,SLOT(receiveData(Protein**,int)));

    showWind = new Show();
    connect(this,SIGNAL(sendData(Protein**,int)),showWind,SLOT(receiveData(Protein**,int)));

    exWindow = new ExportWindow();
    connect(this,SIGNAL(sData(Protein**,int*)),exWindow,SLOT(recData(Protein**,int*)));

    sumWind = new SumWindow();
    connect(this,SIGNAL(sendData(Protein**,int)),sumWind,SLOT(receiveData(Protein**,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_7_clicked()
{
    if (count <= 25){
        prota[count] = new Protein();
        count = count + 1;
        QMessageBox::information(this,"","Добавлен новый пустой протеин");
    }
    else
        QMessageBox::warning(this,"ОПАААА!","У вас много протеинов, удалите несколько!");
}


void MainWindow::on_pushButton_2_clicked()
{
    emit sendData(this->prota,this->count);
    addWindow->setModal(true);
    addWindow->setWindowTitle("Add new acid into protein");
    addWindow->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    emit sendData(this->prota,(this->count));
    impWindow->setModal(true);
    impWindow->setWindowTitle("Import");
    impWindow->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    emit sData(this->prota,&(this->count));
    exWindow->setModal(true);
    exWindow->setWindowTitle("Export");
    exWindow->show();
}


void MainWindow::on_pushButton_clicked()
{
    emit sendData(this->prota,this->count);
    showWind->setModal(true);
    showWind->setWindowTitle("Show");
    showWind->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    emit sendData(this->prota,this->count);
    sumWind->setModal(true);
    sumWind->setWindowTitle("Sum");
    sumWind->show();
}
