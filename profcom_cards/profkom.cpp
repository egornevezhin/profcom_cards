#include "profkom.h"
#include "ui_profkom.h"

Profkom::Profkom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Profkom)
{
    ui->setupUi(this);
    a = 0;
    //ui->lineEdit->hide();
}

Profkom::~Profkom()
{
    delete ui;
}

void Profkom::on_lineEdit_textChanged(const QString &arg1) {
    a++;
    if(a == 6){
        ui->lineEdit->clear();
        a = 0;
    }
    ui->label->setText( arg1);


}
