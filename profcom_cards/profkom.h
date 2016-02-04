#ifndef PROFKOM_H
#define PROFKOM_H

#include <QMainWindow>
#include <QString>
#include <QImage>
#include <QVector>
#include <QMessageBox>
#include <QtNetwork>

namespace Ui {
class Profkom;
}

class Profkom : public QMainWindow
{
    Q_OBJECT

public:
    explicit Profkom(QWidget *parent = 0);
    ~Profkom();

private:
    Ui::Profkom *ui;

    QMessageBox *MBox;

    QString isu;

    struct events{
      int id;
      QString name;
      QDate date;
      int amount;
      int rate;
    };

    struct people{
        QString isu;
        QString rate;
        QString phone;
        QString fio;
    };

    QVector<events> eventsVec;


private slots:
    void ShowMessage(QString messageText,QString Title);

    void on_ISU_textChanged(const QString &arg1);

    QString phoneChange(QString tel);

    void connectBD();

    void getEventList();

    void on_buttonAddEvents_clicked();

    void on_buttonPayFees_clicked();

    void on_eventAdd_clicked();

    void getImage(QNetworkReply *reply);

    void on_tabWidget_tabBarClicked(int index);

    void on_comboBoxEvents_activated(int index);

    void on_buttonDeleteEvent_clicked();

    void on_openEventFile_clicked();

    void saveListParticipant(QList<people> list, int rowc);

    QByteArray utf8ToWindows1251(QString utf8);

    void on_outEventListButtion_clicked();
    void on_comboBoxEvents_currentTextChanged(const QString &arg1);
    void on_Events_currentTextChanged(const QString &arg1);
};

#endif // PROFKOM_H
