#include "imp.h"
#include "ui_imp.h"

Imp::Imp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Imp)
{
    ui->setupUi(this);
}

Imp::~Imp()
{
    delete ui;
}
