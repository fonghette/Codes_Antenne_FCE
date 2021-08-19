/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *CONTROL_GROUP;
    QGroupBox *Position_group;
    QGroupBox *Positions;
    QTextBrowser *Position;
    QGroupBox *Butees;
    QTextBrowser *Butee;
    QGroupBox *groupBox_5;
    QTextBrowser *Etat_Systeme;
    QGroupBox *Tension_group;
    QTextBrowser *Tension;
    QGroupBox *Temperature_group;
    QTextBrowser *Temperature;
    QGroupBox *groupBox_3;
    QTextEdit *file_name;
    QPushButton *CREER_FICHIER;
    QPushButton *ARRETER_RELEVE;
    QTextEdit *periode_echantillonnage;
    QPushButton *CHANGER_FREQUENCE;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPushButton *CMD_MOTEUR;
    QPushButton *ANNUL_CMD_MOTEUR;
    QLabel *label_3;
    QTextBrowser *Traitement_Commande;
    QGroupBox *groupBox_6;
    QLabel *label;
    QTextEdit *Angle_Poloidal;
    QTextEdit *Angle_Toroidal;
    QLabel *label_2;
    QGroupBox *groupBox_7;
    QTextEdit *Angle_Poloidal_2;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *Angle_Toroidal_2;
    QGroupBox *groupBox_8;
    QLabel *label_6;
    QTextEdit *Angle_Poloidal_3;
    QLabel *label_7;
    QTextEdit *Angle_Toroidal_3;
    QGroupBox *groupBox_4;
    QPushButton *CMD_ON;
    QPushButton *CMD_RESET;
    QPushButton *CMD_OFF;
    QPushButton *CMD_INIT;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1586, 1252);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CONTROL_GROUP = new QGroupBox(centralwidget);
        CONTROL_GROUP->setObjectName(QString::fromUtf8("CONTROL_GROUP"));
        CONTROL_GROUP->setGeometry(QRect(320, 0, 811, 681));
        CONTROL_GROUP->setStyleSheet(QString::fromUtf8("border-color: rgb(170, 0, 0);"));
        Position_group = new QGroupBox(CONTROL_GROUP);
        Position_group->setObjectName(QString::fromUtf8("Position_group"));
        Position_group->setGeometry(QRect(20, 20, 411, 651));
        Position_group->setStyleSheet(QString::fromUtf8(""));
        Positions = new QGroupBox(Position_group);
        Positions->setObjectName(QString::fromUtf8("Positions"));
        Positions->setGeometry(QRect(10, 30, 391, 231));
        Positions->setStyleSheet(QString::fromUtf8(""));
        Position = new QTextBrowser(Positions);
        Position->setObjectName(QString::fromUtf8("Position"));
        Position->setGeometry(QRect(10, 30, 371, 191));
        Position->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Californian FB\";"));
        Butees = new QGroupBox(Position_group);
        Butees->setObjectName(QString::fromUtf8("Butees"));
        Butees->setGeometry(QRect(10, 260, 391, 241));
        Butees->setStyleSheet(QString::fromUtf8(""));
        Butee = new QTextBrowser(Butees);
        Butee->setObjectName(QString::fromUtf8("Butee"));
        Butee->setGeometry(QRect(10, 30, 371, 191));
        Butee->setStyleSheet(QString::fromUtf8("font-size: 12pt"));
        groupBox_5 = new QGroupBox(Position_group);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 520, 391, 121));
        groupBox_5->setStyleSheet(QString::fromUtf8(""));
        Etat_Systeme = new QTextBrowser(groupBox_5);
        Etat_Systeme->setObjectName(QString::fromUtf8("Etat_Systeme"));
        Etat_Systeme->setGeometry(QRect(10, 20, 371, 91));
        Etat_Systeme->setStyleSheet(QString::fromUtf8("background-color: red;"));
        Tension_group = new QGroupBox(CONTROL_GROUP);
        Tension_group->setObjectName(QString::fromUtf8("Tension_group"));
        Tension_group->setGeometry(QRect(440, 250, 331, 131));
        Tension_group->setStyleSheet(QString::fromUtf8(""));
        Tension = new QTextBrowser(Tension_group);
        Tension->setObjectName(QString::fromUtf8("Tension"));
        Tension->setGeometry(QRect(10, 30, 311, 91));
        Tension->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Californian FB\";"));
        Temperature_group = new QGroupBox(CONTROL_GROUP);
        Temperature_group->setObjectName(QString::fromUtf8("Temperature_group"));
        Temperature_group->setGeometry(QRect(440, 20, 331, 231));
        Temperature_group->setStyleSheet(QString::fromUtf8(""));
        Temperature = new QTextBrowser(Temperature_group);
        Temperature->setObjectName(QString::fromUtf8("Temperature"));
        Temperature->setGeometry(QRect(10, 30, 311, 191));
        Temperature->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Californian FB\";"));
        groupBox_3 = new QGroupBox(CONTROL_GROUP);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(440, 420, 321, 251));
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        file_name = new QTextEdit(groupBox_3);
        file_name->setObjectName(QString::fromUtf8("file_name"));
        file_name->setGeometry(QRect(10, 20, 301, 51));
        file_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        CREER_FICHIER = new QPushButton(groupBox_3);
        CREER_FICHIER->setObjectName(QString::fromUtf8("CREER_FICHIER"));
        CREER_FICHIER->setGeometry(QRect(20, 80, 131, 31));
        CREER_FICHIER->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);"));
        ARRETER_RELEVE = new QPushButton(groupBox_3);
        ARRETER_RELEVE->setObjectName(QString::fromUtf8("ARRETER_RELEVE"));
        ARRETER_RELEVE->setGeometry(QRect(170, 80, 131, 31));
        ARRETER_RELEVE->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);"));
        periode_echantillonnage = new QTextEdit(groupBox_3);
        periode_echantillonnage->setObjectName(QString::fromUtf8("periode_echantillonnage"));
        periode_echantillonnage->setGeometry(QRect(20, 150, 131, 71));
        CHANGER_FREQUENCE = new QPushButton(groupBox_3);
        CHANGER_FREQUENCE->setObjectName(QString::fromUtf8("CHANGER_FREQUENCE"));
        CHANGER_FREQUENCE->setGeometry(QRect(170, 170, 131, 28));
        CHANGER_FREQUENCE->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 301, 681));
        groupBox->setStyleSheet(QString::fromUtf8("border-color: rgb(170, 0, 0);"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 200, 281, 471));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        CMD_MOTEUR = new QPushButton(groupBox_2);
        CMD_MOTEUR->setObjectName(QString::fromUtf8("CMD_MOTEUR"));
        CMD_MOTEUR->setGeometry(QRect(0, 330, 131, 51));
        CMD_MOTEUR->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Times New Roman\";\n"
"background-color: rgb(202, 202, 202);"));
        ANNUL_CMD_MOTEUR = new QPushButton(groupBox_2);
        ANNUL_CMD_MOTEUR->setObjectName(QString::fromUtf8("ANNUL_CMD_MOTEUR"));
        ANNUL_CMD_MOTEUR->setGeometry(QRect(160, 330, 121, 51));
        ANNUL_CMD_MOTEUR->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Times New Roman\";\n"
"background-color: rgb(202, 202, 202);"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 390, 181, 16));
        label_3->setStyleSheet(QString::fromUtf8(""));
        Traitement_Commande = new QTextBrowser(groupBox_2);
        Traitement_Commande->setObjectName(QString::fromUtf8("Traitement_Commande"));
        Traitement_Commande->setGeometry(QRect(20, 410, 251, 51));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 30, 271, 91));
        label = new QLabel(groupBox_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 16));
        label->setStyleSheet(QString::fromUtf8(""));
        Angle_Poloidal = new QTextEdit(groupBox_6);
        Angle_Poloidal->setObjectName(QString::fromUtf8("Angle_Poloidal"));
        Angle_Poloidal->setGeometry(QRect(10, 40, 111, 31));
        Angle_Toroidal = new QTextEdit(groupBox_6);
        Angle_Toroidal->setObjectName(QString::fromUtf8("Angle_Toroidal"));
        Angle_Toroidal->setGeometry(QRect(160, 40, 101, 31));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 20, 91, 16));
        label_2->setStyleSheet(QString::fromUtf8(""));
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 130, 271, 91));
        Angle_Poloidal_2 = new QTextEdit(groupBox_7);
        Angle_Poloidal_2->setObjectName(QString::fromUtf8("Angle_Poloidal_2"));
        Angle_Poloidal_2->setGeometry(QRect(10, 40, 111, 31));
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 91, 16));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 20, 91, 16));
        label_5->setStyleSheet(QString::fromUtf8(""));
        Angle_Toroidal_2 = new QTextEdit(groupBox_7);
        Angle_Toroidal_2->setObjectName(QString::fromUtf8("Angle_Toroidal_2"));
        Angle_Toroidal_2->setGeometry(QRect(160, 40, 101, 31));
        groupBox_8 = new QGroupBox(groupBox_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(0, 230, 271, 91));
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 20, 91, 16));
        label_6->setStyleSheet(QString::fromUtf8(""));
        Angle_Poloidal_3 = new QTextEdit(groupBox_8);
        Angle_Poloidal_3->setObjectName(QString::fromUtf8("Angle_Poloidal_3"));
        Angle_Poloidal_3->setGeometry(QRect(10, 40, 111, 31));
        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(170, 20, 91, 16));
        label_7->setStyleSheet(QString::fromUtf8(""));
        Angle_Toroidal_3 = new QTextEdit(groupBox_8);
        Angle_Toroidal_3->setObjectName(QString::fromUtf8("Angle_Toroidal_3"));
        Angle_Toroidal_3->setGeometry(QRect(160, 40, 101, 31));
        groupBox_8->raise();
        groupBox_6->raise();
        CMD_MOTEUR->raise();
        ANNUL_CMD_MOTEUR->raise();
        label_3->raise();
        Traitement_Commande->raise();
        groupBox_7->raise();
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 40, 281, 151));
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        CMD_ON = new QPushButton(groupBox_4);
        CMD_ON->setObjectName(QString::fromUtf8("CMD_ON"));
        CMD_ON->setGeometry(QRect(10, 20, 131, 51));
        CMD_ON->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Times New Roman\";\n"
"background-color: rgb(202, 202, 202);"));
        CMD_RESET = new QPushButton(groupBox_4);
        CMD_RESET->setObjectName(QString::fromUtf8("CMD_RESET"));
        CMD_RESET->setGeometry(QRect(150, 90, 121, 51));
        CMD_RESET->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Times New Roman\";\n"
"background-color: rgb(202, 202, 202);"));
        CMD_OFF = new QPushButton(groupBox_4);
        CMD_OFF->setObjectName(QString::fromUtf8("CMD_OFF"));
        CMD_OFF->setGeometry(QRect(150, 20, 121, 51));
        CMD_OFF->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Times New Roman\";\n"
"background-color: rgb(202, 202, 202);"));
        CMD_INIT = new QPushButton(groupBox_4);
        CMD_INIT->setObjectName(QString::fromUtf8("CMD_INIT"));
        CMD_INIT->setGeometry(QRect(10, 90, 131, 51));
        CMD_INIT->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Times New Roman\";\n"
"background-color: rgb(202, 202, 202);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1586, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CONTROL_GROUP->setTitle(QCoreApplication::translate("MainWindow", "CONTROL GROUP", nullptr));
        Position_group->setTitle(QCoreApplication::translate("MainWindow", "Position Control", nullptr));
        Positions->setTitle(QCoreApplication::translate("MainWindow", "Positions Actuelles", nullptr));
        Position->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Californian FB'; font-size:16pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        Butees->setTitle(QCoreApplication::translate("MainWindow", "But\303\251es", nullptr));
        Butee->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:8pt;\"><br /></p></body></html>", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "ETAT SYSTEME", nullptr));
        Etat_Systeme->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Californian FB'; font-size:14pt; font-weight:600;\">Communication non \303\251tablie</span></p></body></html>", nullptr));
        Tension_group->setTitle(QCoreApplication::translate("MainWindow", "Tension Control", nullptr));
        Tension->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Californian FB'; font-size:16pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p></body></html>", nullptr));
        Temperature_group->setTitle(QCoreApplication::translate("MainWindow", "Temperature Control", nullptr));
        Temperature->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Californian FB'; font-size:16pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p></body></html>", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "FICHIER DATA", nullptr));
        file_name->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Californian FB'; font-size:10pt; font-weight:72;\">Inserer le nom du fichier ici</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        CREER_FICHIER->setText(QCoreApplication::translate("MainWindow", "CREER", nullptr));
        ARRETER_RELEVE->setText(QCoreApplication::translate("MainWindow", "ARRETER", nullptr));
        periode_echantillonnage->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Rentrer ici la p\303\251riode d'\303\251chantillonnage en ms</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">La p\303\251riode par d\303\251faut est de 10 ms </p></body></html>", nullptr));
        CHANGER_FREQUENCE->setText(QCoreApplication::translate("MainWindow", "CHANGER PERIODE", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "COMMANDE GROUP", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "COMMANDE MOTEURS", nullptr));
        CMD_MOTEUR->setText(QCoreApplication::translate("MainWindow", "LANCER CMD", nullptr));
        ANNUL_CMD_MOTEUR->setText(QCoreApplication::translate("MainWindow", "ANNULER", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Traitement Commande", nullptr));
        Traitement_Commande->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Miroir Haut M1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Angle Polo\303\257dal", nullptr));
        Angle_Poloidal->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        Angle_Toroidal->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Angle Toro\303\257dal", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Miroir Milieu M2", nullptr));
        Angle_Poloidal_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Angle Polo\303\257dal", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Angle Toro\303\257dal", nullptr));
        Angle_Toroidal_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Miroir Bas M3", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Angle Polo\303\257dal", nullptr));
        Angle_Poloidal_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Angle Toro\303\257dal", nullptr));
        Angle_Toroidal_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Californian FB'; font-size:10pt; font-weight:72;\"><br /></p></body></html>", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "GESTION GENERALE", nullptr));
        CMD_ON->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        CMD_RESET->setText(QCoreApplication::translate("MainWindow", "RESET ", nullptr));
        CMD_OFF->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        CMD_INIT->setText(QCoreApplication::translate("MainWindow", "INITIALISATION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
