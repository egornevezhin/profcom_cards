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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
        lineEdit->setGeometry(QRect(10, 10, 111, 21));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 47, 13));
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
        label->setText(QApplication::translate("Profkom", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Profkom", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Profkom", "Tab 2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Profkom", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class Profkom: public Ui_Profkom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFKOM_H
