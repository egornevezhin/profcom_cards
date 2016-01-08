#include "profkom.h"
#include "ui_profkom.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

void conn(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("profcom");
    db.setUserName("root");
    db.setPassword("1234");
    bool ok = db.open();
    QMessageBox mb;
    if(ok)
        mb.setText("Connected succesful!");
    else
        mb.setText(db.lastError().text());
    mb.exec();
}

Profkom::Profkom(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Profkom){
        ui->setupUi(this);
        conn();
    }

Profkom::~Profkom()
{
    delete ui;
}
