/********************************************************************************
** Form generated from reading UI file 'profkom.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profkom
{
public:
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *labelPhoto;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *Fio;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QComboBox *Events;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonAddEvents;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QListWidget *visitedEventsList;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLineEdit *ISU;
    QLabel *label_10;
    QLabel *telLable;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *Deposit;
    QPushButton *buttonPayFees;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_11;
    QLabel *labelCoef;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelStatusCard;
    QPushButton *pushButtonStatusCard;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QComboBox *comboBoxEvents;
    QLabel *label_4;
    QLineEdit *eventName;
    QLabel *label_6;
    QDateEdit *eventDate;
    QLabel *label_7;
    QLineEdit *eventAmount;
    QLabel *label_8;
    QLineEdit *eventRate;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonDeleteEvent;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *eventAdd;
    QTableWidget *eventPeopleTable;
    QWidget *tab_3;
    QTableWidget *eventsTable;
    QPushButton *openEventFile;
    QPushButton *outEventListButtion;
    QComboBox *finalEventList;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *profcomLogoLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNameUser;
    QLineEdit *lineEditNameUser;
    QLabel *LabelPassworUser;
    QLineEdit *lineEditPassworUser;
    QPushButton *pushButtonUserIn;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_5;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Profkom)
    {
        if (Profkom->objectName().isEmpty())
            Profkom->setObjectName(QStringLiteral("Profkom"));
        Profkom->setEnabled(true);
        Profkom->resize(680, 548);
        action_2 = new QAction(Profkom);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(Profkom);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralWidget = new QWidget(Profkom);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_10 = new QVBoxLayout(centralWidget);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        labelPhoto = new QLabel(tab);
        labelPhoto->setObjectName(QStringLiteral("labelPhoto"));
        labelPhoto->setLayoutDirection(Qt::LeftToRight);
        labelPhoto->setAutoFillBackground(false);
        labelPhoto->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelPhoto);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        Fio = new QLabel(tab);
        Fio->setObjectName(QStringLiteral("Fio"));

        horizontalLayout_2->addWidget(Fio);


        verticalLayout_5->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        Events = new QComboBox(groupBox);
        Events->setObjectName(QStringLiteral("Events"));

        verticalLayout_3->addWidget(Events);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonAddEvents = new QPushButton(groupBox);
        buttonAddEvents->setObjectName(QStringLiteral("buttonAddEvents"));

        horizontalLayout->addWidget(buttonAddEvents);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_5->addWidget(groupBox);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        verticalLayout_5->addWidget(label_9);

        visitedEventsList = new QListWidget(tab);
        visitedEventsList->setObjectName(QStringLiteral("visitedEventsList"));

        verticalLayout_5->addWidget(visitedEventsList);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_6->addWidget(label);

        ISU = new QLineEdit(tab);
        ISU->setObjectName(QStringLiteral("ISU"));

        verticalLayout_6->addWidget(ISU);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        verticalLayout_6->addWidget(label_10);

        telLable = new QLabel(tab);
        telLable->setObjectName(QStringLiteral("telLable"));

        verticalLayout_6->addWidget(telLable);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Deposit = new QLabel(groupBox_2);
        Deposit->setObjectName(QStringLiteral("Deposit"));

        verticalLayout_4->addWidget(Deposit);

        buttonPayFees = new QPushButton(groupBox_2);
        buttonPayFees->setObjectName(QStringLiteral("buttonPayFees"));

        verticalLayout_4->addWidget(buttonPayFees);


        verticalLayout_6->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_11 = new QVBoxLayout(groupBox_4);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        labelCoef = new QLabel(groupBox_4);
        labelCoef->setObjectName(QStringLiteral("labelCoef"));

        verticalLayout_11->addWidget(labelCoef);


        verticalLayout_6->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        labelStatusCard = new QLabel(groupBox_3);
        labelStatusCard->setObjectName(QStringLiteral("labelStatusCard"));

        verticalLayout_9->addWidget(labelStatusCard);

        pushButtonStatusCard = new QPushButton(groupBox_3);
        pushButtonStatusCard->setObjectName(QStringLiteral("pushButtonStatusCard"));

        verticalLayout_9->addWidget(pushButtonStatusCard);


        verticalLayout_6->addWidget(groupBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_6);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        comboBoxEvents = new QComboBox(tab_2);
        comboBoxEvents->setObjectName(QStringLiteral("comboBoxEvents"));

        verticalLayout_7->addWidget(comboBoxEvents);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout_7->addWidget(label_4);

        eventName = new QLineEdit(tab_2);
        eventName->setObjectName(QStringLiteral("eventName"));

        verticalLayout_7->addWidget(eventName);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_7->addWidget(label_6);

        eventDate = new QDateEdit(tab_2);
        eventDate->setObjectName(QStringLiteral("eventDate"));

        verticalLayout_7->addWidget(eventDate);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout_7->addWidget(label_7);

        eventAmount = new QLineEdit(tab_2);
        eventAmount->setObjectName(QStringLiteral("eventAmount"));

        verticalLayout_7->addWidget(eventAmount);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        verticalLayout_7->addWidget(label_8);

        eventRate = new QLineEdit(tab_2);
        eventRate->setObjectName(QStringLiteral("eventRate"));

        verticalLayout_7->addWidget(eventRate);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        buttonDeleteEvent = new QPushButton(tab_2);
        buttonDeleteEvent->setObjectName(QStringLiteral("buttonDeleteEvent"));
        buttonDeleteEvent->setEnabled(false);
        buttonDeleteEvent->setCheckable(false);

        horizontalLayout_4->addWidget(buttonDeleteEvent);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        eventAdd = new QPushButton(tab_2);
        eventAdd->setObjectName(QStringLiteral("eventAdd"));

        horizontalLayout_4->addWidget(eventAdd);


        verticalLayout_7->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_7);

        eventPeopleTable = new QTableWidget(tab_2);
        eventPeopleTable->setObjectName(QStringLiteral("eventPeopleTable"));
        eventPeopleTable->horizontalHeader()->setVisible(false);
        eventPeopleTable->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(eventPeopleTable);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        eventsTable = new QTableWidget(tab_3);
        eventsTable->setObjectName(QStringLiteral("eventsTable"));
        eventsTable->setGeometry(QRect(20, 10, 551, 241));
        eventsTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        eventsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        eventsTable->setSortingEnabled(false);
        eventsTable->setColumnCount(0);
        eventsTable->horizontalHeader()->setVisible(false);
        eventsTable->verticalHeader()->setVisible(false);
        openEventFile = new QPushButton(tab_3);
        openEventFile->setObjectName(QStringLiteral("openEventFile"));
        openEventFile->setGeometry(QRect(20, 270, 75, 23));
        outEventListButtion = new QPushButton(tab_3);
        outEventListButtion->setObjectName(QStringLiteral("outEventListButtion"));
        outEventListButtion->setGeometry(QRect(110, 270, 71, 23));
        finalEventList = new QComboBox(tab_3);
        finalEventList->setObjectName(QStringLiteral("finalEventList"));
        finalEventList->setGeometry(QRect(200, 270, 201, 22));
        tabWidget->addTab(tab_3, QString());

        verticalLayout_10->addWidget(tabWidget);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        profcomLogoLabel = new QLabel(frame);
        profcomLogoLabel->setObjectName(QStringLiteral("profcomLogoLabel"));

        horizontalLayout_6->addWidget(profcomLogoLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_8->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelNameUser = new QLabel(frame);
        labelNameUser->setObjectName(QStringLiteral("labelNameUser"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNameUser);

        lineEditNameUser = new QLineEdit(frame);
        lineEditNameUser->setObjectName(QStringLiteral("lineEditNameUser"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNameUser);

        LabelPassworUser = new QLabel(frame);
        LabelPassworUser->setObjectName(QStringLiteral("LabelPassworUser"));

        formLayout->setWidget(1, QFormLayout::LabelRole, LabelPassworUser);

        lineEditPassworUser = new QLineEdit(frame);
        lineEditPassworUser->setObjectName(QStringLiteral("lineEditPassworUser"));
        lineEditPassworUser->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPassworUser);


        verticalLayout->addLayout(formLayout);

        pushButtonUserIn = new QPushButton(frame);
        pushButtonUserIn->setObjectName(QStringLiteral("pushButtonUserIn"));

        verticalLayout->addWidget(pushButtonUserIn);


        horizontalLayout_7->addLayout(verticalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_8->addLayout(horizontalLayout_7);

        verticalSpacer_5 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_5);


        verticalLayout_10->addWidget(frame);

        Profkom->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Profkom);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        Profkom->setMenuBar(menuBar);
        statusBar = new QStatusBar(Profkom);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Profkom->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_3);
        menu->addSeparator();
        menu->addAction(action_2);

        retranslateUi(Profkom);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Profkom);
    } // setupUi

    void retranslateUi(QMainWindow *Profkom)
    {
        Profkom->setWindowTitle(QApplication::translate("Profkom", "\320\237\321\200\320\276\321\204\320\272\320\276\320\274 \320\243\320\275\320\270\320\262\320\265\321\200\321\201\320\270\321\202\320\265\321\202\320\260 \320\230\320\242\320\234\320\236", 0));
        action_2->setText(QApplication::translate("Profkom", "\320\222\321\213\321\205\320\276\320\264", 0));
        action_3->setText(QApplication::translate("Profkom", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Profkom", "\320\244\320\276\321\202\320\276", 0));
        labelPhoto->setText(QString());
        label_3->setText(QApplication::translate("Profkom", "[\320\230\320\241\320\243]\320\244\320\230\320\236", 0));
        Fio->setText(QString());
        groupBox->setTitle(QApplication::translate("Profkom", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0));
        label_5->setText(QApplication::translate("Profkom", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\275\320\260 \320\274\320\265\321\200\320\276\320\277\321\200\320\270\321\217\321\202\320\270\320\265:", 0));
        buttonAddEvents->setText(QApplication::translate("Profkom", "OK", 0));
        label_9->setText(QApplication::translate("Profkom", "\320\237\320\276\321\201\320\265\321\211\320\265\320\275\320\275\321\213\320\265 \320\274\320\265\321\200\320\276\320\277\321\200\320\270\321\217\321\202\320\270\321\217", 0));
        label->setText(QApplication::translate("Profkom", "\320\235\320\276\320\274\320\265\321\200 \320\230\320\241\320\243", 0));
        label_10->setText(QApplication::translate("Profkom", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", 0));
        telLable->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Profkom", "\320\237\321\200\320\276\321\204\320\262\320\267\320\275\320\276\321\201\321\213", 0));
        Deposit->setText(QString());
        buttonPayFees->setText(QApplication::translate("Profkom", "\320\236\320\277\320\273\320\260\321\202\320\270\321\202\321\214", 0));
        groupBox_4->setTitle(QApplication::translate("Profkom", "K\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202", 0));
        labelCoef->setText(QApplication::translate("Profkom", "coef", 0));
        groupBox_3->setTitle(QApplication::translate("Profkom", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\272\320\260\321\200\321\202\321\213", 0));
        labelStatusCard->setText(QApplication::translate("Profkom", "Cars_Status", 0));
        pushButtonStatusCard->setText(QApplication::translate("Profkom", "\320\227\320\260\320\261\321\200\320\260\320\273 \320\272\320\260\321\200\321\202\321\203", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Profkom", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        label_4->setText(QApplication::translate("Profkom", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        label_6->setText(QApplication::translate("Profkom", "\320\224\320\260\321\202\320\260", 0));
        eventDate->setDisplayFormat(QApplication::translate("Profkom", "dd-MM-yyyy", 0));
        label_7->setText(QApplication::translate("Profkom", "\320\232\320\276\320\273-\320\262\320\276 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\276\320\262", 0));
        label_8->setText(QApplication::translate("Profkom", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\265\320\275\321\202", 0));
        buttonDeleteEvent->setText(QApplication::translate("Profkom", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        eventAdd->setText(QApplication::translate("Profkom", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Profkom", "\320\234\320\265\321\200\320\276\320\277\321\200\320\270\321\217\321\202\320\270\321\217", 0));
        openEventFile->setText(QApplication::translate("Profkom", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        outEventListButtion->setText(QApplication::translate("Profkom", "\320\241\320\277\320\270\321\201\320\272\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Profkom", "\320\241\320\277\320\270\321\201\320\272\320\270", 0));
        profcomLogoLabel->setText(QApplication::translate("Profkom", "Logo", 0));
        labelNameUser->setText(QApplication::translate("Profkom", "\320\230\320\241\320\243:", 0));
        LabelPassworUser->setText(QApplication::translate("Profkom", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0));
        pushButtonUserIn->setText(QApplication::translate("Profkom", "\320\222\320\276\320\271\321\202\320\270", 0));
        menu->setTitle(QApplication::translate("Profkom", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class Profkom: public Ui_Profkom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFKOM_H
