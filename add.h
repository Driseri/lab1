#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "protein.h"

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public slots:
    void receiveData(Protein **ms, int count);

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add *ui;
    Protein **pop;
    int countMass;
};

#endif // ADD_H
