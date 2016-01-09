/********************************************************************************
** Form generated from reading UI file 'profkom.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFKOM_H
#define UI_PROFKOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profkom
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLabel *label;
    QGraphicsView *Photo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *Fio;
    QGroupBox *groupBox;
    QLabel *label_5;
    QComboBox *Events;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLabel *Deposit;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QWidget *tab_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Profkom)
    {
        if (Profkom->objectName().isEmpty())
            Profkom->setObjectName(QStringLiteral("Profkom"));
        Profkom->setEnabled(true);
        Profkom->resize(600, 400);
        centralWidget = new QWidget(Profkom);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 600, 360));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(400, 30, 111, 21));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 10, 71, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        Photo = new QGraphicsView(tab);
        Photo->setObjectName(QStringLiteral("Photo"));
        Photo->setGeometry(QRect(10, 30, 110, 150));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Photo->sizePolicy().hasHeightForWidth());
        Photo->setSizePolicy(sizePolicy);
        Photo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Photo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Photo->setInteractive(false);
        Photo->setSceneRect(QRectF(0, 0, 0, 0));
        Photo->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 47, 13));
        label_2->setFont(font);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 10, 47, 13));
        label_3->setFont(font);
        Fio = new QLabel(tab);
        Fio->setObjectName(QStringLiteral("Fio"));
        Fio->setGeometry(QRect(140, 30, 241, 16));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(140, 60, 241, 121));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 221, 20));
        label_5->setFont(font);
        Events = new QComboBox(groupBox);
        Events->setObjectName(QStringLiteral("Events"));
        Events->setGeometry(QRect(10, 50, 171, 22));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 80, 75, 23));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 60, 161, 80));
        Deposit = new QLabel(groupBox_2);
        Deposit->setObjectName(QStringLiteral("Deposit"));
        Deposit->setGeometry(QRect(10, 20, 131, 16));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 50, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        Profkom->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Profkom);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        Profkom->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Profkom);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Profkom->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Profkom);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Profkom->setStatusBar(statusBar);

        retranslateUi(Profkom);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Profkom);
    } // setupUi

    void retranslateUi(QMainWindow *Profkom)
    {
        Profkom->setWindowTitle(QApplication::translate("Profkom", "Profkom", 0));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Profkom", "\320\235\320\276\320\274\320\265\321\200 \320\230\320\241\320\243", 0));
        label_2->setText(QApplication::translate("Profkom", "\320\244\320\276\321\202\320\276", 0));
        label_3->setText(QApplication::translate("Profkom", "\320\244\320\230\320\236", 0));
        Fio->setText(QString());
        groupBox->setTitle(QApplication::translate("Profkom", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0));
        label_5->setText(QApplication::translate("Profkom", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\275\320\260 \320\274\320\265\321\200\320\276\320\277\321\200\320\270\321\217\321\202\320\270\320\265:", 0));
        pushButton->setText(QApplication::translate("Profkom", "OK", 0));
        groupBox_2->setTitle(QApplication::translate("Profkom", "\320\237\321\200\320\276\321\204\320\262\320\267\320\275\320\276\321\201\321\213", 0));
        Deposit->setText(QString());
        pushButton_2->setText(QApplication::translate("Profkom", "\320\236\320\277\320\273\320\260\321\202\320\270\321\202\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Profkom", "\320\255\320\272\321\201\320\272\321\203\321\200\321\201\320\270\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Profkom", "\320\222\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\320\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Profkom", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\274\320\276\321\211\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Profkom: public Ui_Profkom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFKOM_H
