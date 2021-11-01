#include "importwindow.h"
#include "ui_importwindow.h"
#include <QMessageBox>
#include "protein.h"
ImportWindow::ImportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
    pop = new Protein * [25];
}

ImportWindow::~ImportWindow()
{
    delete ui;
}

void ImportWindow::receiveData(Protein **ms, int count){
    for (int i = 0; i < count;i++){
        pop[i] = ms[i];
    }
    countMass = count;
}

void ImportWindow::on_pushButton_clicked()
{
    pop[countMass] = new Protein();
    pop[countMass]->importFromFile((ui->lineEdit->text()).toStdString());
    pop[countMass]->Show();
    countMass = countMass + 1;
    QMessageBox::information(this,"","Suck Importing");

}
