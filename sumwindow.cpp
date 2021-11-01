#include "sumwindow.h"
#include "ui_sumwindow.h"
#include <iostream>
#include <string>
using namespace std;

SumWindow::SumWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SumWindow)
{
    ui->setupUi(this);
    pop = new Protein * [25];
}

SumWindow::~SumWindow()
{
    delete ui;
}

void SumWindow::on_pushButton_clicked()
{
    int id1 = ui->spinBox->value();
    int id2 = ui->spinBox_2->value();
    pop[id1]->Sum(*pop[id1],*pop[id2]);
    string *mass = pop[id1]->Show();
    ui->label->setText("Полученный Протеин:\n\n");
    for (int i = 0; i < pop[id1]->getCount(); i++){
        ui->label->setText(ui->label->text() + "Id: " + QString::fromStdString(to_string(i)) + "\n");
        ui->label->setText(ui->label->text() + "Полное имя: " + QString::fromStdString(mass[i]) + "\n");
        ui->label->setText(ui->label->text() + "\n\n");
    }
}

void SumWindow::receiveData(Protein **ms, int count){
    for (int i = 0; i < count;i++){
        pop[i] = ms[i];
    }
    countMass = count;
}
