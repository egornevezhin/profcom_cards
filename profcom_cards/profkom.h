#ifndef PROFKOM_H
#define PROFKOM_H

#include <QMainWindow>

namespace Ui {
class Profkom;
}

class Profkom : public QMainWindow
{
    Q_OBJECT

public:
    explicit Profkom(QWidget *parent = 0);
    ~Profkom();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Profkom *ui;

    int a;
};

#endif // PROFKOM_H
