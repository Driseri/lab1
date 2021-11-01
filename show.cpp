#include "show.h"
#include "ui_show.h"
#include <QString>
#include <iostream>
using namespace std;
Show::Show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show)
{
    ui->setupUi(this);
    pop = new Protein * [25];
}

Show::~Show()
{
    delete ui;
}

void Show::on_pushButton_clicked()
{
    int id = ui->spinBox->value();
    Protein *ps = pop[id];
    ui->label->setText("Данный Протеин:\n\n");
    string *mass = ps->Show();
    for (int i = 0; i < ps->getCount(); i++){
        ui->label->setText(ui->label->text() + "Id: " + QString::fromStdString(to_string(i)) + "\n");
        ui->label->setText(ui->label->text() + "Полное имя: " + QString::fromStdString(mass[i]) + "\n");
        ui->label->setText(ui->label->text() + "\n\n");
    }
}

void Show::receiveData(Protein **ms, int count)
{
    for (int i = 0; i < count;i++){
        pop[i] = ms[i];
    }
    countMass = count;
}
