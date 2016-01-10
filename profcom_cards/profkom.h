#ifndef PROFKOM_H
#define PROFKOM_H

#include <QMainWindow>
#include <QString>
#include <QImage>
#include <QVector>
#include <QMessageBox>
#include <QUrl>

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
    void ShowMessage(QString messageText,QString Title);

    void on_ISU_textChanged(const QString &arg1);

    void connectBD();

    void getEventList();

    void on_buttonAddEvents_clicked();

    void on_buttonPayFees_clicked();

    void on_eventAdd_clicked();

private:
    Ui::Profkom *ui;

    QMessageBox *MBox;

    QString isu;
};

#endif // PROFKOM_H
