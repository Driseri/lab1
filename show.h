#ifndef SHOW_H
#define SHOW_H

#include <QDialog>
#include "protein.h"

namespace Ui {
class Show;
}

class Show : public QDialog
{
    Q_OBJECT

public slots:
    void receiveData(Protein **ms, int count);

public:
    explicit Show(QWidget *parent = nullptr);
    ~Show();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Show *ui;
    Protein **pop;
    int countMass;
};

#endif // SHOW_H
