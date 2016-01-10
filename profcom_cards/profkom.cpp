#include "profkom.h"
#include "ui_profkom.h"
#include <QSqlDatabase>

#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QBuffer>
#include <QImageReader>
#include <QPixmap>
#include <vector>



Profkom::Profkom(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Profkom){
    ui->setupUi(this);

    MBox = NULL;

    connectBD();

    getEventList();

}

Profkom::~Profkom()
{
    delete ui;
}

void Profkom::getEventList(){
    QSqlQuery query;
    QVector<QString> name;
    ui->Events->clear();
    query.prepare( "SELECT name FROM events");
    if(!query.exec()){
        ShowMessage("No find!","EROR");
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

void Profkom::ShowMessage(QString messageText, QString Title)
{
    MBox=new QMessageBox;
    MBox->setWindowTitle(Title.toUtf8());
    MBox->setText(messageText.toUtf8());
    MBox->show();
}

void Profkom::connectBD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("94.19.5.51");
    db.setDatabaseName("profcom");
    db.setUserName("profcom");
    db.setPassword("12");
    bool ok = db.open();
    if(ok)
        ShowMessage("Connected succesful!","OK");
    else
        ShowMessage(db.lastError().text(),"EROR");
}



void Profkom::on_ISU_textChanged(const QString &arg1)
{
    QString s, fio, deposit;
    if(ui->ISU->text().size() == 6){
        isu = arg1;
        QSqlQuery query;

        query.prepare("SELECT fio, photo_url, deposit FROM chlens WHERE isu = " + isu);

        if(!query.exec()){
            ShowMessage(query.lastError().text(),"EROR");
        }
        else{
            query.first(); // запрос по фио
            ui->Fio->setText(query.value(0).toString());

            //query.next(); // запрос по фоточке
            //getFile(QUrl(query.value(1).toString()));
            QPixmap pixmap("buf.png");
            ui->labelPhoto->setPixmap(pixmap.scaled(110,150,Qt::KeepAspectRatio,Qt::SmoothTransformation));

            //            QByteArray array = query.value(0).toByteArray();
            //            QBuffer buffer(&array);
            //            buffer.open( QIODevice::ReadOnly );
            //            QImageReader reader(&buffer, "jpg");
            //            QImage image = reader.read();
            //            QGraphicsScene *scn = new QGraphicsScene( ui->Photo );
            //            ui->Photo->setScene( scn );
            //            QPixmap pix( QPixmap::fromImage(image) );
            //            scn->addPixmap( pix );
            //            ui->Photo->show();

            //query.next(); // запрос по профвзносам
            if(query.value(2).toString() == "1")
                ui->Deposit->setText("Оплачены.");
            else
                ui->Deposit->setText("Не оплачены.");
        }

        ui->ISU->clear();
    }
}


void Profkom::on_buttonAddEvents_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id FROM events WHERE name = '" +  ui->Events->currentText() +"'");
    query.first();
    int num = query.value(0).toInt();
    if(ui->Deposit->text() == "Оплачены.")
        query.exec("INSERT INTO event_chlens (isu, id_event) VALUES (" +
                   ui->ISU->text() + ", " +
                   QString::number(num) + ");");
    else{
        ShowMessage("Не оплачены профвзносы","WARNING");
    }
}

void Profkom::on_buttonPayFees_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE chlens SET deposit = '1' WHERE isu = " + isu);
    if(query.exec()){
        ui->Deposit->setText("Оплачены.");
    }
    else{
        ShowMessage(query.lastError().text(),"EROR");
    }
}

void Profkom::on_eventAdd_clicked()
{
    QSqlQuery query;
    QMessageBox mb;
    if(!ui->eventName->text().isEmpty() && !ui->eventAmount->text().isEmpty() && !ui->eventRate->text().isEmpty()){
        query.prepare("INSERT INTO events (name, date, amount, rate) VALUES ('" +
                      ui->eventName->text() + "', '" +
                      QString::number(ui->eventDate->date().year()) + "-" + QString::number(ui->eventDate->date().month()) + "-" + QString::number(ui->eventDate->date().day()) + "', '" +
                      ui->eventAmount->text() + "', '" +
                      ui->eventRate->text() +"')");
        if(!query.exec()){
            mb.setText(query.lastError().text());
            mb.exec();
        }
        getEventList();
    }
    else{
        mb.setText("Заполнены не все поля!");
        mb.exec();
    }
}
