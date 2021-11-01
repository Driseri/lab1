#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include <QDialog>
#include "protein.h"

namespace Ui {
class ImportWindow;
}

class ImportWindow : public QDialog
{
    Q_OBJECT

public slots:
    void receiveData(Protein **ms,int count);
public:
    explicit ImportWindow(QWidget *parent = nullptr);
    ~ImportWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ImportWindow *ui;
    Protein **pop;
    int countMass;
};

#endif // IMPORTWINDOW_H
