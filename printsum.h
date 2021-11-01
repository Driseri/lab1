#ifndef PRINTSUM_H
#define PRINTSUM_H

#include <QDialog>

namespace Ui {
class PrintSum;
}

class PrintSum : public QDialog
{
    Q_OBJECT

public:
    explicit PrintSum(QWidget *parent = nullptr);
    ~PrintSum();

private:
    Ui::PrintSum *ui;
};

#endif // PRINTSUM_H
