#include "exportwindow.h"
#include "ui_exportwindow.h"
#include <QMessageBox>
ExportWindow::ExportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportWindow)
{
    ui->setupUi(this);
}

ExportWindow::~ExportWindow()
{
    delete ui;
}

void ExportWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"","Экспорт успешен");
}


void ExportWindow::recData(Protein **ms,int *count){
    for (int i = 0; i < *count;i++){
        pop[i] = ms[i];
    }
    countMass = *count;
}
