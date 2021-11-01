#include "printsum.h"
#include "ui_printsum.h"

PrintSum::PrintSum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintSum)
{
    ui->setupUi(this);
}

PrintSum::~PrintSum()
{
    delete ui;
}
