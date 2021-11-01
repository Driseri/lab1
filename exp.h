#ifndef EXP_H
#define EXP_H

#include <QDialog>

namespace Ui {
class Exp;
}

class Exp : public QDialog
{
    Q_OBJECT

public:
    explicit Exp(QWidget *parent = nullptr);
    ~Exp();

private:
    Ui::Exp *ui;
};

#endif // EXP_H
