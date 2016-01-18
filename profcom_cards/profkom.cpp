#include "profkom.h"
#include "ui_profkom.h"
#include <QSqlDatabase>

#include <QFile>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QBuffer>
#include <QImageReader>
#include <QPixmap>
#include <vector>
#include <QUrl>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTableWidgetItem>


Profkom::Profkom(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Profkom){
    ui->setupUi(this);

    MBox = NULL;

    eventsVec.clear();

    connectBD();

    getEventList();

}

Profkom::~Profkom()
{
    delete ui;
}

    // получение списка мероприятий
void Profkom::getEventList(){
    QSqlQuery query;
    QVector<QString> name;
    ui->Events->clear();
    query.prepare( "SELECT name FROM events WHERE date>=CURDATE()");
    if(!query.exec()){
        ShowMessage("No find!","EROR");
    }
    else{
        //        query.first();
        //        name.push_back(query.value(0).toString());
        while(query.next()){
            name.push_back(query.value(0).toString());
        }
        for(int i=0;i<name.length();i++){
            ui->Events->addItem(name[i]);
        }
    }
}

    // метод вывода сообщений
void Profkom::ShowMessage(QString messageText, QString Title)
{
    MBox=new QMessageBox;
    MBox->setWindowTitle(Title.toUtf8());
    MBox->setText(messageText.toUtf8());
    MBox->show();
}

    // метод соединения с БД
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


    // метод обработки ввода ИСУ
void Profkom::on_ISU_textChanged(const QString &arg1)
{
    QString s, fio, deposit;
    ui->labelPhoto->setText("");
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

            QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);                // запрос по фоточке
            connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getImage(QNetworkReply*)));
            networkManager->get(QNetworkRequest(QUrl("http://94.19.5.51/profcom/photo/"+isu+".png")));

            if(query.value(2).toString() == "1"){    // запрос по профвзносам
                ui->Deposit->setText("Оплачены.");
                ui->buttonPayFees->setEnabled(0);
            }
            else{
                ui->Deposit->setText("Не оплачены.");
                ui->buttonPayFees->setEnabled(1);
            }
        }
    }
}


    // метод добавления мероприятия
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

    // метод оплаты профвзносов
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

    // метод добавления мероприятия
void Profkom::on_eventAdd_clicked()
{
    QSqlQuery query;
    if(ui->comboBoxEvents->currentIndex()==0){
        if(!ui->eventName->text().isEmpty() && !ui->eventAmount->text().isEmpty() && !ui->eventRate->text().isEmpty()){
            query.prepare("INSERT INTO events (name, date, amount, rate) VALUES ('" +
                          ui->eventName->text() + "', '" +
                          QString::number(ui->eventDate->date().year()) + "-" + QString::number(ui->eventDate->date().month()) + "-" + QString::number(ui->eventDate->date().day()) + "', '" +
                          ui->eventAmount->text() + "', '" +
                          ui->eventRate->text() +"')");
            if(!query.exec()){
                ShowMessage(query.lastError().text(),"EROR");
            }
        }
        else{
            ShowMessage("Заполнены не все поля!","EROR");
        }
    }
    else{
        query.prepare("UPDATE events SET name = '"+ ui->eventName->text() +"', " +
                      "date = '"+QString::number(ui->eventDate->date().year()) + "-" + QString::number(ui->eventDate->date().month()) + "-" + QString::number(ui->eventDate->date().day()) + "', " +
                      "amount = '"+ui->eventAmount->text() + "', " +
                      "rate = '"+ui->eventRate->text() + "' "+
                      "WHERE id = '"+QString::number(eventsVec[ui->comboBoxEvents->currentIndex()-1].id)+"'");
        if(!query.exec()){
            ShowMessage(query.lastError().text(),"EROR");
        }else{
            ShowMessage("Изменения успешно сохранены","ОК");
        }

    }
    on_tabWidget_tabBarClicked(1);

    ui->eventName->clear();
    ui->eventDate->setDate(QDate::currentDate());
    ui->eventAmount->clear();
    ui->eventRate->clear();

}

    // получение изображения члена ИСУ
void Profkom::getImage(QNetworkReply *reply)
{
    QByteArray data;
    QImage image;
    if (reply->error() == QNetworkReply::NoError)
    {
        data = reply->readAll();
        image = QImage::fromData(data);

    }else {
        ShowMessage("Не удалось загрузить изображение.\nВозможно файл отцуствует.","WARNING");
    }
    ui->labelPhoto->setPixmap(QPixmap::fromImage(image).scaled(110,150,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

    // фишечка Андрея на редактирование мероприятия
void Profkom::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0){
        getEventList();
    }
    if(index==1){
        ui->eventDate->setDate(QDate::currentDate());
        QSqlQuery query;
        ui->comboBoxEvents->clear();
        query.prepare( "SELECT * FROM events");
        if(!query.exec()){
            ShowMessage("No find!","EROR");
            return;
        }
        eventsVec.clear();
        while(query.next()){
            events* event = new events;
            event->id = query.value(0).toInt();
            event->name = query.value(1).toString();
            event->date = query.value(2).toDate();
            event->amount = query.value(3).toInt();
            event->rate = query.value(4).toInt();
            eventsVec.push_back(*event);
        }
        ui->comboBoxEvents->addItem("Добавить новое мероприятие");
        for(int i=0;i<eventsVec.length();i++){
            ui->comboBoxEvents->addItem(eventsVec[i].name);
        }
    }
    on_comboBoxEvents_activated(0);
}

    //
void Profkom::on_comboBoxEvents_activated(int index)
{
    if(index!=0){
        index--;
        ui->eventName->setText(eventsVec[index].name);
        ui->eventDate->setDate(eventsVec[index].date);
        ui->eventAmount->setText(QString::number(eventsVec[index].amount));
        ui->eventRate->setText(QString::number(eventsVec[index].rate));
        ui->buttonDeleteEvent->setEnabled(1);
    }
    else{
        ui->eventName->clear();
        ui->eventDate->setDate(QDate::currentDate());
        ui->eventAmount->clear();
        ui->eventRate->clear();
        ui->buttonDeleteEvent->setEnabled(0);
    }
}

    // метод удаления мероприятия
void Profkom::on_buttonDeleteEvent_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM events WHERE id = '"+QString::number(eventsVec[ui->comboBoxEvents->currentIndex()-1].id)+"'");
    if(!query.exec()){
        ShowMessage(query.lastError().text(),"EROR");
    }else{
        ShowMessage("Мероприятие успешно удалено","ОК");
    }

    on_tabWidget_tabBarClicked(1);

    ui->eventName->clear();
    ui->eventDate->setDate(QDate::currentDate());
    ui->eventAmount->clear();
    ui->eventRate->clear();
}

    // метод открытия файла с мероприятием
void Profkom::on_openEventFile_clicked()
{
    QSqlQuery query;
    QVector<people> list;
    people chel;
    QString str = QFileDialog::getOpenFileName(0, "Выберите файл с мерприятием", "", "*.csv");
    QFile file(str);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Ошибка открытия для чтения";
    }
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        // ИСУ
        chel.isu = line.split(';')[0];
        // телефон
        chel.phone = line.split(';')[1];
        query.exec("UPDATE  chlens SET  phone = " + chel.phone + " WHERE  isu = " + chel.isu);

        query.exec("SELECT isu, fio, phone,sum(rate) FROM events,chlens WHERE isu = " + chel.isu + " AND id_event in (SELECT id_event FROM event_chlens WHERE isu = " + chel.isu + ")");

        // ФИО
        query.first();
        chel.fio = query.value(1).toString();
        // коэффицент
        chel.rate = query.value(3).toString();
        list.push_back(chel);
    }
    people temp;
    int m;
    for (int i=0; i < list.size() - 1; i++){
        m = i;
        for (int j = i + 1; j < list.size(); j++){
            if(list[j].rate.toInt() < list[m].rate.toInt())
                m = j;
        }
        temp.fio = list[i].fio;
        temp.isu = list[i].isu;
        temp.phone = list[i].phone;
        temp.rate = list[i].rate;

        list[i].fio = list[m].fio;
        list[i].isu = list[m].isu;
        list[i].phone = list[m].phone;
        list[i].rate = list[m].rate;

        list[m].fio = temp.fio;
        list[m].isu = temp.isu;
        list[m].phone = temp.phone;
        list[m].rate = temp.rate;
    }
    ui->eventsTable->setRowCount(list.size());
    for(int i=0;i<list.size();i++){
        // ису
        ui->eventsTable->setItem(i, 0, new QTableWidgetItem(list[i].isu));
        // ФИO
        ui->eventsTable->setItem(i, 1, new QTableWidgetItem(list[i].fio));
        // телефон
        ui->eventsTable->setItem(i, 2, new QTableWidgetItem(list[i].phone));
        // коэффицент
        ui->eventsTable->setItem(i, 3, new QTableWidgetItem(list[i].rate));
    }
}
