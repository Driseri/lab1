#ifndef EXPORTWINDOW_H
#define EXPORTWINDOW_H

#include <QDialog>
#include "protein.h"
namespace Ui {
class ExportWindow;
}

class ExportWindow : public QDialog
{
    Q_OBJECT

public slots:
    void recData(Protein**,int *count);

public:
    explicit ExportWindow(QWidget *parent = nullptr);
    ~ExportWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ExportWindow *ui;
    Protein **pop;
    int countMass;
};

#endif // EXPORTWINDOW_H
