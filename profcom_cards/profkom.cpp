#include "profkom.h"
#include "ui_profkom.h"
#include <QSqlDatabase>

#include <QFile>
#include <QSqlError>
#include <QSqlQuery>
#include <QBuffer>
#include <QImageReader>
#include <QPixmap>
#include <QUrl>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QFile>
#include <QPrinter>
#include <QTextDocument>

Profkom::Profkom(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Profkom){
    ui->setupUi(this);

    MBox = NULL;

    eventsVec.clear();

    connectBD();

    getEventList();

    ui->tabWidget->hide();


    QPixmap imageLogo("logo_profcom.png");
    ui->profcomLogoLabel->setPixmap(imageLogo.scaled(500,500,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    ui->labelStatusCard->hide();
    ui->pushButtonStatusCard->hide();
    ui->groupBox_3->hide();
    ui->groupBox_4->hide();
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
    ui->finalEventList->clear();
    query.prepare( "SELECT name FROM events WHERE date>=CURDATE() ORDER BY YEAR(Date) DESC, MONTH(Date) DESC, DAY(DATE) DESC");
    if(!query.exec()){
        ShowMessage("No find!","ERROR");
    }
    else{
        //        query.first();
        //        name.push_back(query.value(0).toString());
        while(query.next()){
            name.push_back(query.value(0).toString());
        }
        for(int i=0;i<name.length();i++){
            ui->Events->addItem(name[i]);
            ui->finalEventList->addItem(name[i]);
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
    db.setHostName("178.250.246.120");
    db.setDatabaseName("profcom");
    db.setUserName("profcom");
    db.setPassword("Z6SCXjct7255HR3d");
    bool ok = db.open();
    if(!ok)
        ShowMessage(db.lastError().text(),"EROR");
}

// метод формирования номера телефона
QString Profkom::phoneChange(QString tel){
    QString fin = "+7 (";
    fin = fin + tel[1] + tel[2] + tel[3] + ") ";
    fin = fin + tel[4] + tel[5] + tel[6] + "-";
    fin = fin + tel[7] + tel[8] + "-";
    fin = fin + tel[9] + tel[10];
    return fin;
}

// метод обработки ввода ИСУ
void Profkom::on_ISU_textChanged(const QString &arg1)
{
    QString tel = "";
    ui->labelPhoto->setText("");
    ui->visitedEventsList->clear();
    if(ui->ISU->text().size() == 6){
        isu = arg1;
        QSqlQuery query;

        query.prepare("SELECT chlens.fio, chlens.status_card, chlens.deposit, chlens.phone, sum(events.rate) FROM events,chlens,event_chlens WHERE chlens.isu ="+isu+" AND event_chlens.isu = 153836 AND event_chlens.id_event = events.id_event");

        if(!query.exec()){
            ShowMessage(query.lastError().text(),"ERROR");
        }
        else{
            query.first(); // запрос по фио
            ui->Fio->setText(query.value(0).toString());
            ui->telLable->setText(phoneChange(query.value(3).toString()));

            QNetworkProxyQuery proxy(QUrl("http://www.vk.com"));    // запрос по фоточке
            QList<QNetworkProxy> listOfProxy = QNetworkProxyFactory::systemProxyForQuery(proxy);
            QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
            if(listOfProxy.size())
                networkManager->setProxy(listOfProxy[0]);
            connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getImage(QNetworkReply*)));
            networkManager->get(QNetworkRequest(QUrl("http://0wx.ru/profcom/reg/savefile/"+isu+".png")));

            if(query.value(2).toString() == "1"){    // запрос по профвзносам
                ui->Deposit->setStyleSheet("QLabel { background-color : white; color : green; }");
                ui->Deposit->setText("Оплачены.");
                ui->buttonPayFees->setEnabled(0);
            }
            else{
                ui->Deposit->setStyleSheet("QLabel { background-color : white; color : red; }");
                ui->Deposit->setText("Не оплачены.");
                ui->buttonPayFees->setEnabled(1);
            }
            switch (query.value(1).toInt()) {
            case 0:
                ui->labelStatusCard->setText("Карта не заказана");
                ui->labelStatusCard->show();
                ui->groupBox_4->show();
                ui->labelCoef->setText(query.value(4).toString());
                ui->pushButtonStatusCard->hide();
                ui->groupBox_3->show();
                break;
            case 1:
                ui->labelStatusCard->setText("Карта заказана");
                ui->labelStatusCard->show();
                ui->groupBox_4->show();
                ui->labelCoef->setText(query.value(4).toString());
                ui->pushButtonStatusCard->show();
                ui->groupBox_3->show();
                break;
            case 2:
                ui->labelStatusCard->setText("Карта получена");
                ui->labelStatusCard->show();
                ui->groupBox_4->show();
                ui->labelCoef->setText(query.value(4).toString());
                ui->pushButtonStatusCard->hide();
                ui->groupBox_3->show();
                break;
            }


            query.exec("SELECT events.name FROM events, event_chlens WHERE event_chlens.isu ="+isu+"AND events.id_event=event_chlens.id_event");
            while(query.next()){
                ui->visitedEventsList->addItem(query.value(0).toString());
            }

        }
    }
}


// метод добавления на мероприятие
void Profkom::on_buttonAddEvents_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id_event FROM events WHERE name = '" +  ui->Events->currentText() +"'");
    query.first();
    int num = query.value(0).toInt();
    if(ui->Deposit->text() == "Оплачены."){
        query.exec("SELECT id_event FROM event_chlens WHERE isu = " + ui->ISU->text());
        while(query.next()){
            if(query.value(0).toInt() == num){
                ShowMessage("Уже на экскурсии","WARNING");
                return;
            }
        }
        query.exec("INSERT INTO event_chlens (isu, id_event) VALUES (" +
                   ui->ISU->text() + ", " +
                   QString::number(num) + ");");
    }
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
        ui->Deposit->setStyleSheet("QLabel { background-color : white; color : green; }");
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
                      "WHERE id_event = '"+QString::number(eventsVec[ui->comboBoxEvents->currentIndex()-1].id)+"'");
        if(!query.exec()){
            ShowMessage(query.lastError().text(),"ERROR");
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
        ShowMessage("Не удалось загрузить изображение.\nВозможно файл отсуствует.","WARNING");
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
        query.prepare( "SELECT * FROM events ORDER BY YEAR(Date) DESC, MONTH(Date) DESC, DAY(DATE) DESC");
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
    query.prepare("DELETE FROM events WHERE id_event = '"+QString::number(eventsVec[ui->comboBoxEvents->currentIndex()-1].id)+"'");
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
    getEventList();
}

// метод открытия файла с мероприятием
void Profkom::on_openEventFile_clicked()
{
    QSqlQuery query;
    QVector<people> list;
    people chel;
    QMap<QString, int> unIsu;
    QString str = QFileDialog::getOpenFileName(0, "Выберите файл с мерприятием", "", "*.csv");
    QFile file(str);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Ошибка открытия для чтения";
    }
    ui->eventsTable->setColumnCount(4);
    ui->eventsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        // ИСУ
        chel.isu = line.split(';')[0];
        // телефон
        chel.phone = line.split(';')[1];

        if(unIsu[chel.isu] == 1){
            continue;
        }

        unIsu[chel.isu]++;


        query.exec("UPDATE  chlens SET  phone = " + chel.phone.remove(QRegExp("\\D")) + " WHERE  isu = " + chel.isu);

        query.exec("SELECT isu, fio, phone,sum(rate) FROM events,chlens WHERE isu = " + chel.isu + " AND id_event in (SELECT id_event FROM event_chlens WHERE isu = " + chel.isu + ")");

        // ФИО
        query.first();
        chel.fio = query.value(1).toString();
        if(chel.fio == ""){
            continue;
        }
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

void Profkom::saveListParticipant(QList<Profkom::people> list, int rowc)   //Метод сохранения списка участников мероприятия в указанном формате. Поддерживаются форматы pdf,csv
{
    // rowc - количество людей в основном списке
    QString pathFilter;
    QString path = QFileDialog::getSaveFileName(this, "Cохранить файл","Список","PDF (*.pdf);;Excel (*.csv)",&pathFilter);
    if(!path.isEmpty()){
        if(pathFilter.contains("csv")){
            QString csv="ИСУ;ФИО;тел.\n";
            for(int i=0;i<list.size();i++){
                if(i==rowc)
                    csv +="\n;РЕЗЕРВ\n";
                csv += list[i].isu+";"+list[i].fio+";"+list[i].phone+"\n";
            }
            QFile csvFile(path);
            if(!csvFile.open(QIODevice::WriteOnly)){
                ShowMessage("Ошибка в записи\nОбратитесь к админимтратору","EROR");
            }
            csvFile.write(utf8ToWindows1251(csv));
            csvFile.close();
            ShowMessage("CSV файл успешно создан!","ОК");
        }
        if(pathFilter.contains("pdf")){
            QString html= "<html xmlns=\"http://www.w3.org/1999/xhtml\" dir=\"ltr\" lang=\"ru\">\n<head>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n"
                          "</head>\n<body>\n<table border=\"1\" cellpadding=\"3\" cellspacing=\"0\" border-color=\"red\">\n<tbody>\n<tr>\n<td>\n<p>ИСУ</p>\n</td>\n<td>\n<p>ФИО</p>\n</td>\n<td>\n<p>Телефон</p>\n</td>\n</tr>\n";
            for(int i=0;i<list.size();i++){
                if(i==rowc)
                    html +="</tbody>\n</table>\n<p><b>РЕЗЕРВ</b></p>\n<table border=\"1\" cellpadding=\"3\" cellspacing=\"0\" border-color=\"red\">\n<tbody>\n";
                html += "<tr>\n<td>\n<p>"+list[i].isu+"</p>\n</td>"+"<td>\n<p>"+list[i].fio+"</p>\n</td>\n"+"<td>\n<p>"+list[i].phone+"</p>\n</td>\n</tr>\n";
            }
            html += "</tbody>\n</table>\n</body>\n</html>";

            QTextDocument *document = new QTextDocument();
            document->setHtml(html);

            QPrinter printer(QPrinter::HighResolution);
            printer.setPageSize(QPrinter::A4);
            printer.setOutputFormat(QPrinter::PdfFormat);

            printer.setOutputFileName(path);

            document->print(&printer);
            delete document;

            ShowMessage("PDF файл успешно создан!","ОК");
        }
    }else{
        ShowMessage("Не удалось сохранить файл\nИмя файла было не задано","EROR");
        return;
    }
}

QByteArray Profkom::utf8ToWindows1251(QString utf8)
{
    return QTextCodec::codecForName("Windows-1251")->fromUnicode(QByteArray(QString(utf8).toStdString().c_str()));
}

void Profkom::on_outEventListButtion_clicked()
{
    QSqlQuery query;
    query.exec("SELECT amount FROM events WHERE name = '" + ui->finalEventList->currentText() + "'");
    query.next();
    int rowc = query.value(0).toInt(); // количество людей на мероприятии
    if(ui->eventsTable->rowCount() != 0){
        if((rowc) > ui->eventsTable->rowCount()){
            rowc = ui->eventsTable->rowCount();
        }
        QList<Profkom::people> outEventList;
        Profkom::people out;
        for (int row = 0 ; row < ui->eventsTable->rowCount() ; ++row) {
            out.fio = ui->eventsTable->item(row, 1)->text();
            out.phone = ui->eventsTable->item(row, 2)->text();
            out.isu = ui->eventsTable->item(row, 0)->text();
            outEventList.push_back(out);
        }

        saveListParticipant(outEventList, rowc);
    }
    else{
        ShowMessage("Таблица пуста", "ERROR");
    }
}

void Profkom::on_comboBoxEvents_currentTextChanged(const QString &currEvent)
{
    QSqlQuery query;
    QVector<QString> ppl;
    ui->eventPeopleTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    query.exec("SELECT fio FROM chlens WHERE isu IN (SELECT isu FROM event_chlens WHERE id_event = (SELECT id_event FROM events WHERE name = '" + currEvent + "')) ORDER BY fio");
    while(query.next()){
        ppl.push_back(query.value(0).toString());
    }
    ui->eventPeopleTable->setRowCount(ppl.size());
    ui->eventPeopleTable->setColumnCount(1);
    for(int i=0; i < ppl.size(); i++){
        ui->eventPeopleTable->setItem(i, 0, new QTableWidgetItem(ppl[i]));
    }
}

void Profkom::on_pushButtonUserIn_clicked()
{
    if(ui->lineEditNameUser->text().isEmpty() || ui->lineEditPassworUser->text().isEmpty()){
        ShowMessage("Не все поля введены","Ошибка");
        return;
    }
    QSqlQuery query;
    query.exec("SELECT isu,password,type_user FROM `users` WHERE isu = '"+ui->lineEditNameUser->text()+"' AND password = '"+ui->lineEditPassworUser->text()+"'");
    if(query.size()==0){
        ShowMessage("Такого пользователя не существует.\nПроверьте ввод логина и пароля","Ошибка");
        return;
    }
    query.first();
    userAccess(query.value(2).toInt());
}

void Profkom::userAccess(int userType)
{
    switch (userType) {
    case 0:
        ui->groupBox->hide();
        ui->groupBox_2->hide();
        ui->tabWidget->setTabEnabled(1,0);
        ui->tabWidget->setTabEnabled(2,0);
        ui->frame->hide();
        ui->tabWidget->show();
        break;
    case 1:
        ui->tabWidget->setTabEnabled(1,0);
        ui->tabWidget->setTabEnabled(2,0);
        ui->frame->hide();
        ui->tabWidget->show();
        break;
    case 2:
        ui->frame->hide();
        ui->tabWidget->show();
        break;
    default:
        ShowMessage("Такого пользователя не существует.\nОбратитесь к администратору","Ошибка");
        break;
    }
}

void Profkom::on_action_2_triggered()
{
    exit(0);
}

void Profkom::on_action_3_triggered()
{
    ui->lineEditNameUser->text().clear();
    ui->lineEditPassworUser->text().clear();
    ui->groupBox->show();
    ui->groupBox_2->show();
    ui->tabWidget->setTabEnabled(1,1);
    ui->tabWidget->setTabEnabled(2,1);
    ui->tabWidget->hide();
    ui->frame->show();

}
