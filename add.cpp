#include "add.h"
#include "ui_add.h"
#include <QString>
#include <iostream>
using namespace std;
#include <QMessageBox>

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    pop = new Protein * [25];
}

Add::~Add()
{
    delete ui;
}

void Add::receiveData(Protein **ms, int count)
{
    for (int i = 0; i < count;i++){
        pop[i] = ms[i];
    }
    countMass = count;
}

void Add::on_pushButton_clicked()
{
    int index = ui->spinBox->value();
    Protein *oneP = pop[index];
    if (ui->spinBox_2->value() == 1){
        AcidProt *pip = new AcidProt((ui->lineEdit->text()).toStdString());
        oneP->Add(*pip);
        QMessageBox::information(this,"","Suck insert");
    }
    else{
        Acid *pip = new Acid((ui->lineEdit->text()).toStdString(),((ui->lineEdit_2->text()).toStdString())[0]);
        oneP->Add(*pip);
        QMessageBox::information(this,"","Suck insert");
    }
}

