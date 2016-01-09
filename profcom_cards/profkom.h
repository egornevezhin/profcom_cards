#ifndef PROFKOM_H
#define PROFKOM_H

#include <QMainWindow>
#include <QString>
#include <qimage.h>
#include <QVector>

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

    void on_pushButton_clicked();

private:
    Ui::Profkom *ui;
};

#endif // PROFKOM_H
