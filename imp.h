#ifndef IMP_H
#define IMP_H

#include <QDialog>

namespace Ui {
class Imp;
}

class Imp : public QDialog
{
    Q_OBJECT

public:
    explicit Imp(QWidget *parent = nullptr);
    ~Imp();

private:
    Ui::Imp *ui;
};

#endif // IMP_H
