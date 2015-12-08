#include "profkom.h"
#include "ui_profkom.h"

Profkom::Profkom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Profkom)
{
    ui->setupUi(this);
}

Profkom::~Profkom()
{
    delete ui;
}
