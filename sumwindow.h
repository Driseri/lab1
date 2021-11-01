#ifndef SUMWINDOW_H
#define SUMWINDOW_H

#include <QDialog>
#include "protein.h"

namespace Ui {
class SumWindow;
}

class SumWindow : public QDialog
{
    Q_OBJECT
public slots:
    void receiveData(Protein **ms, int count);
public:
    explicit SumWindow(QWidget *parent = nullptr);
    ~SumWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SumWindow *ui;
    Protein **pop;
    int countMass;
};

#endif // SUMWINDOW_H
