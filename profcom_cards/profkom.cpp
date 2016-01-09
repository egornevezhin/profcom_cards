#include "profkom.h"
#include "ui_profkom.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QBuffer>
#include <QImageReader>
#include <QPixmap>
#include <vector>


void conn(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("profcom");
    db.setUserName("prog");
    db.setPassword("12");
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

        // запрос по мероприятиям
        QMessageBox mb;
        QSqlQuery query;
        QVector<QString> name;
        query.prepare( "SELECT NAME FROM EVENTS");
        if(!query.exec()){
            mb.setText("No find!");
            mb.exec();
        }
        else{
            query.first();
            name.push_back(query.value(0).toString());
            while(query.next()){
                 name.push_back(query.value(0).toString());
            }
            for(int i=0;i<name.length();i++){
                ui->Events->addItem(name[i]);
            }
        }
    }

Profkom::~Profkom()
{
    delete ui;
}

void Profkom::on_lineEdit_textChanged(const QString &arg1)
{
    QImage image;
    QString s, fio, deposit;
    if(ui->lineEdit->text().size() == 6){
        s = ui->lineEdit->text();
        QSqlQuery query;
        QMessageBox mb;
        // запрос по фио
        query.prepare( "SELECT FIO FROM CHLENS WHERE ISU = " + s);
        if(!query.exec()){
            mb.setText("No find!");
            mb.exec();
        }
        else{
            query.first();
            fio = query.value(0).toString();
            ui->Fio->setText(fio);
        }
        // запрос по фото
        query.prepare( "SELECT PHOTO FROM PHOTO WHERE ISU = " + s);
        if(!query.exec()){
            mb.setText("No find!");
            mb.exec();
        }
        else{
            query.first();
            QByteArray array = query.value(0).toByteArray();
            QBuffer buffer(&array);
            buffer.open( QIODevice::ReadOnly );

            QImageReader reader(&buffer, "jpg");
            QImage image = reader.read();

            QGraphicsScene *scn = new QGraphicsScene( ui->Photo );
            ui->Photo->setScene( scn );
            QPixmap pix( QPixmap::fromImage(image) );
            scn->addPixmap( pix );

            ui->Photo->show();
        }
        // запрос по профвзносам
        query.prepare( "SELECT DEPOSIT FROM CHLENS WHERE ISU = " + s);
        if(!query.exec()){
            mb.setText("No find!");
            mb.exec();
        }
        else{
            query.first();
            deposit = query.value(0).toString();
            if(deposit == "1")
                ui->Deposit->setText("оплачены.");
            else
                ui->Deposit->setText("не оплачены.");
        }

        ui->lineEdit->clear();
    }
}
