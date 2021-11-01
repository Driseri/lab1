#include "exp.h"
#include "ui_exp.h"

Exp::Exp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exp)
{
    ui->setupUi(this);
}

Exp::~Exp()
{
    delete ui;
}
