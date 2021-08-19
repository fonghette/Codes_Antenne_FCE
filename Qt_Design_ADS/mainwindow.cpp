#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <windows.h>
#include <QTimer>
#include <QTextBrowser>
#include <wtypes.h>
#include <chrono>
#include <fstream>
#include <time.h>

#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsDef.h"
#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsAPI.h"

//--------------------------------------------------------------------------------
//-                                                                              -
//-                      DEFINITION DES VARIABLES GLOBALES                       -
//-                                                                              -
//--------------------------------------------------------------------------------

using namespace std;
using namespace std::chrono;

// Variables utilisées lors de la communication en ADS vers le programme TwinCAT
long        nError, nPort;
AmsAddr     Addr;
PAmsAddr    pAddr = &Addr;
USHORT      nAdsState;
USHORT      nDeviceState = 0;
bool        Communication_etablie = false;
bool        IHM_Initialisee = false;
DWORD       dwData;
void        *pData = NULL;

// Variables utilisées dans le processus de récupération des données dans un fichier
time_t      rawtime;
fstream     datafile;
bool        add_data = false;
int         compteur = 0;

//--------------------------------------------------------------------------------
//-                                                                              -
//-                DEFINITION DES CARACTERISTIQUES DU SYSTEME                    -
//-                                                                              -
//--------------------------------------------------------------------------------

const int   Temps_Raffraichissement = 50;
int         Periode_Releve = 10;
int         Indice_releve = 1;
const int   Commande_Initialisation = 0;
const int   Commande_En_Attente = 100;
const int   Commande_Moteurs = 200;
const int   Commande_Annulation = 300;
const int   Commande_Reset = 800;
const int   Commande_Erreur = 900;


//--------------------------------------------------------------------------------
//-                                                                              -
//-                  DEFINITION DES VARIABLES DANS TWINCAT                       -
//-                                                                              -
//--------------------------------------------------------------------------------

char        Traitement_Commande[]={"GVL.iEtatCmd"};
char        Position_voulue_M1X[]={"GVL.dSetPosition_M1X"};
char        Position_voulue_M1Y[]={"GVL.dSetPosition_M1Y"};
char        Position_voulue_M2X[]={"GVL.dSetPosition_M2X"};
char        Position_voulue_M2Y[]={"GVL.dSetPosition_M2Y"};
char        arrValues[]={"GVL.arrValues"};
char        arrErrors[]={"GVL.arrErrors"};
char        arrButees[]={"GVL.arrButees"};
char        arrData[]={"GVL.arrData"};
char        indice_fin[]={"GVL.ms"};

ULONG        Traitement_Commande_Handle;
ULONG        Position_voulue_M1X_Handle;
ULONG        Position_voulue_M1Y_Handle;
ULONG        Position_voulue_M2X_Handle;
ULONG        Position_voulue_M2Y_Handle;
ULONG        arrValues_Handle;
ULONG        arrErrors_Handle;
ULONG        arrButees_Handle;
ULONG        arrData_Handle;
ULONG        indice_fin_Handle;

//--------------------------------------------------------------------------------
//-                                                                              -
//-                 DEFINITION DES VARIABLES VALUE LIEES                         -
//-             CONTENANT LA VALEUR DES VARIABLES DANS TWINCAT                   -
//-                                                                              -
//--------------------------------------------------------------------------------

int         Traitement_Commande_Value;
double      Position_voulue_M1X_Value;
double      Position_voulue_M1Y_Value;
double      Position_voulue_M2X_Value;
double      Position_voulue_M2Y_Value;
double      arrValues_Val[16];
bool        arrErrors_Val[16];
bool        arrErrors_Before_Val[16];
double      arrButees_Val[12];
double      arrData_Val[200][16];
int         indice_fin_value;
int         indice_Data;

//--------------------------------------------------------------------------------
//-                                                                              -
//-                      INITIALISATTION DE L'INTERFACE                          -
//-                                                                              -
//--------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Permet d'appeler une fonction tous les Temps_Raffraichissement ms
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(Temps_Raffraichissement);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//--------------------------------------------------------------------------------
//-                                                                              -
//-                      FONCTIONS COMMUNICATION ADS                             -
//-                                                                              -
//--------------------------------------------------------------------------------

// Ecrit la commande dans la variable PLC associée
void Envoi_Commande(short int Commande)
{
    nError = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, Traitement_Commande_Handle, sizeof(Commande), &Commande);
      if (nError) cerr << "Error: AdsSyncWriteReq: " << nError << '\n';
}

// Init() permet d'initialiser la communication vers le client ADS, lancer le programme PLC et afficher les constantes de butees
void Init(Ui::MainWindow *ui)
{
    // Initialise la communication entre le PLC et l'IHM et l'indique
    nPort = AdsPortOpen();

    // Permet d'associer l'adresse en local
    /*nError = AdsGetLocalAddress(pAddr);
    if (nError) cerr << "Error w/ AdsGetLocalAddress" << nError << '\n';
    else
    {
        ui->Etat_Systeme->setStyleSheet("background-color: green");
        ui->Etat_Systeme->setText("<center>Communication établie");
        Communication_etablie = true;
    }*/

    // Associer avec l'adresse de la CPU
    pAddr->netId.b[0] = 5;
    pAddr->netId.b[1] = 15;
    pAddr->netId.b[2] = 239;
    pAddr->netId.b[3] = 174;
    pAddr->netId.b[4] = 1;
    pAddr->netId.b[5] = 1;

    // Port Twincat 3
    pAddr->port = 851;

    // On relève l'état du PLC et s'il n'y a pas d'erreur on atteste de la communication
    nError = AdsSyncReadStateReq(pAddr, &nAdsState, &nDeviceState);
        if (nError)
          cerr << "Error: AdsSyncReadStateReq: " << nError << '\n';
        else
        {
            ui->Etat_Systeme->setStyleSheet("background-color: green; font-size: 14pt;");
            ui->Etat_Systeme->setText("<center>Communication établie");
            Communication_etablie = true;
        }

    // On lance le PLC s'il n'est pas déjà lancé
    if (nAdsState != ADSSTATE_RUN)
    {
        nAdsState = ADSSTATE_RUN;
        nError = AdsSyncWriteControlReq (pAddr, nAdsState, nDeviceState, 0, pData);
            if (nError) cerr << "Error: AdsSyncWriteControlReq: " << nError << '\n';
    }

    // On définit tous les handle variable pour accéder aux variables twincat plus rapidement
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(Traitement_Commande_Handle), &Traitement_Commande_Handle, sizeof(Traitement_Commande), Traitement_Commande);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(Position_voulue_M1X_Handle), &Position_voulue_M1X_Handle, sizeof(Position_voulue_M1X), Position_voulue_M1X);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(Position_voulue_M1Y_Handle), &Position_voulue_M1Y_Handle, sizeof(Position_voulue_M1Y), Position_voulue_M1Y);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(Position_voulue_M2X_Handle), &Position_voulue_M2X_Handle, sizeof(Position_voulue_M2X), Position_voulue_M2X);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(Position_voulue_M2Y_Handle), &Position_voulue_M2Y_Handle, sizeof(Position_voulue_M2Y), Position_voulue_M2Y);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(arrValues_Handle), &arrValues_Handle, sizeof(arrValues), arrValues);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(arrErrors_Handle), &arrErrors_Handle, sizeof(arrErrors), arrErrors);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(arrButees_Handle), &arrButees_Handle, sizeof(arrButees), arrButees);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(arrData_Handle), &arrData_Handle, sizeof(arrData), arrData);
    AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(indice_fin_Handle), &indice_fin_Handle, sizeof(indice_fin), indice_fin);

    // Relève l'ensemble des constantes de butées et les affiche
    nError = AdsSyncReadReq(pAddr, ADSIGRP_SYM_VALBYHND, arrButees_Handle, sizeof(arrButees_Val), &arrButees_Val[0]);
      if (nError) cerr << "Error: AdsSyncReadReq: " << nError << '\n';
    ui->Butee->setText(QString::fromStdString("Limites M1X : ") + QString::number(arrButees_Val[0], 'g', 3) + QString::fromStdString(" trs < Position M1X < ") + QString::number(arrButees_Val[1], 'g', 3) + QString::fromStdString(" trs\n")
                   + QString::fromStdString("Limites M1Y : ") + QString::number(arrButees_Val[2], 'g', 3) + QString::fromStdString(" trs < Position M1Y < ") + QString::number(arrButees_Val[3], 'g', 3) + QString::fromStdString(" trs\n")
                   + QString::fromStdString("Limites M2X : ") + QString::number(arrButees_Val[4], 'g', 3) + QString::fromStdString(" trs < Position M2X < ") + QString::number(arrButees_Val[5], 'g', 3) + QString::fromStdString(" trs\n")
                   + QString::fromStdString("Limites M2Y : ") + QString::number(arrButees_Val[6], 'g', 3) + QString::fromStdString(" trs < Position M2Y < ") + QString::number(arrButees_Val[7], 'g', 3) + QString::fromStdString(" trs\n")
                   + QString::fromStdString("Limites M3X : ") + QString::number(arrButees_Val[8], 'g', 3) + QString::fromStdString(" trs < Position M3X < ") + QString::number(arrButees_Val[9], 'g', 3) + QString::fromStdString(" trs\n")
                   + QString::fromStdString("Limites M3Y : ") + QString::number(arrButees_Val[10], 'g', 3) + QString::fromStdString(" trs < Position M3Y < ") + QString::number(arrButees_Val[11], 'g', 3) + QString::fromStdString(" trs"));
}

// A l'inverse de l'init, la communication est fermée et le PLC est arrêté
void Close(Ui::MainWindow *ui)
{
    // Ferme le PLC s'il n'est pas déjà fermé
    nError = AdsSyncReadStateReq(pAddr, &nAdsState, &nDeviceState);
    if (nError) cerr << "Error: AdsSyncReadStateReq: " << nError << '\n';

    if (nAdsState != ADSSTATE_STOP)
    {
        nAdsState = ADSSTATE_STOP;
        nError = AdsSyncWriteControlReq (pAddr, nAdsState, nDeviceState, 0, pData);
            if (nError) cerr << "Error: AdsSyncWriteControlReq: " << nError << '\n';
    }

    // Arrête la communication avec le PLC et l'indique visuellement
    nError = AdsPortClose();
    if (nError) cerr << "Error: AdsPortClose: " << nError << '\n';
    else
    {
        ui->Etat_Systeme->setStyleSheet("background-color: red; font-size: 14pt;");
        ui->Etat_Systeme->setText("<center>Communication non établie");
        Communication_etablie = false;
    }
}

//--------------------------------------------------------------------------------
//-                                                                              -
//-                      INTERACTION INTERFACE                                   -
//-                                                                              -
//--------------------------------------------------------------------------------

// procédure qui permet de modifier la couleur de fond en fonction de l'état du système
// Ainsi, s'il n'y a pas d'erreur, le cadre est en vert mais s'il y a une erreur, il est en rouge
// Et surtout pour éviter d'écraser l'interface qui est déjà dans le bon état, on ne change que si un changement d'état est notifié
void Background_Text_Control(QTextBrowser *TextName, bool Etat_Led, bool Etat_Led_Before)
{
    // Si on observe un changement d'état
    if (Etat_Led != Etat_Led_Before || !IHM_Initialisee)
    {
        // Vert si c'est OK, Rouge si ça ne l'est pas
        if (Etat_Led) TextName->setStyleSheet("background-color: red; font-size: 14pt;");
        else TextName->setStyleSheet("background-color: green; font-size: 14pt;");

        // Permet d'initialiser la couleur de l'ensemble des trois encadrés, ensuite ne change de couleur que si changement d'état
        if (compteur == 2) IHM_Initialisee = true;
        else compteur += 1;
    }
}

// procédure qui permet de rendre visuel l'état de la commande et qui est appelée tous les Temps_de_raffraichissement millisecondes
// Ainsi, si le système est en attente, alors il est possible d'envoyer une commande, cadre vert
// Si la commande est indisponible, il y a une erreur à traiter, cadre rouge
// Sinon la commande est en cours de traitement, cadre jaune
// Ne s'active qu'en cas de modification de la valeur de traitement_commande_value
void Update_Etat_Commande(Ui::MainWindow *ui)
{
    // Etape qui permet de rassembler tout un groupe de traitement commande (210, 220, 230, 240 par exemple) en un seul 2 qui peut être traité seul
    int Traitement_Commande_Before_Value = Traitement_Commande_Value/100;

    // Lecture de la variable traitement commande
    nError = AdsSyncReadReq(pAddr, ADSIGRP_SYM_VALBYHND, Traitement_Commande_Handle, sizeof(&Traitement_Commande_Value), &Traitement_Commande_Value);
        if (nError) cerr << "Error: AdsSyncReadReq: " << nError << '\n';

    // En fonction de la valeur relevée et si l'état a changé on opère la bonne mise en page
    if (Traitement_Commande_Before_Value != Traitement_Commande_Value/100)
    {
        // Initialisation
        if (Traitement_Commande_Value/100 == 0)
        {
            ui->Traitement_Commande->setStyleSheet("background-color: yellow; font-size: 10pt;");
            ui->Traitement_Commande->setText("<center>Initialisation en cours");
        }
        // En Attente
        else if (Traitement_Commande_Value/100 == 1)
        {
            ui->Traitement_Commande->setStyleSheet("background-color: green; font-size: 10pt;");
            ui->Traitement_Commande->setText("<center>En attente");
        }
        // Commande moteur en cours
        else if (Traitement_Commande_Value/100 == 2)
        {
            ui->Traitement_Commande->setStyleSheet("background-color: yellow; font-size: 10pt;");
            ui->Traitement_Commande->setText("<center>En cours de déplacement");
        }
        // Annulation de la commande
        else if (Traitement_Commande_Value/100 == 3)
        {
            ui->Traitement_Commande->setStyleSheet("background-color: yellow; font-size: 10pt;");
            ui->Traitement_Commande->setText("<center>En cours d'annulation");
        }
        // Reset
        else if (Traitement_Commande_Value/100 == 8)
        {
            ui->Traitement_Commande->setStyleSheet("background-color: yellow; font-size: 10pt;");
            ui->Traitement_Commande->setText("<center>Reset en cours");
        }
        // Erreur
        else if (Traitement_Commande_Value/100 >= 9)
        {
            ui->Traitement_Commande->setStyleSheet("background-color: red; font-size: 10pt;");
            ui->Traitement_Commande->setText("<center>Commande indisponible - ERREUR");
        }
    }
}

// procédure qui est appelée tous les Temps_de_raffraichissement millisecondes
// Elle permet de relever et afficher l'état des capteurs à un instant t pour procéder à un contrôle en temps réel
void Update_ui(Ui::MainWindow *ui)
{
        // On relève ici toutes les valeurs de capteur
    nError = AdsSyncReadReq(pAddr, ADSIGRP_SYM_VALBYHND, arrValues_Handle, sizeof(arrValues_Val), &arrValues_Val[0]);
      if (nError) cerr << "Error: AdsSyncReadReq: " << nError << '\n';

    // On relève ici l'état de chaque système de contrôle : true = erreur
    nError = AdsSyncReadReq(pAddr, ADSIGRP_SYM_VALBYHND, arrErrors_Handle, sizeof(arrErrors_Val), &arrErrors_Val[0]);
      if (nError) cerr << "Error: AdsSyncReadReq: " << nError << '\n';

    // Affiche l'ensemble des températures ainsi que l'état du groupe -> vert si tout va bien, rouge si au moins une des températures est trop élevée
   ui->Temperature->setText(QString::fromStdString("<center>TC1 Miroir 1     : ") + QString::number(arrValues_Val[0], 'g', 3) + QString::fromStdString("°C \n\n <center>TC2 Miroir 1     : ")
                                      + QString::number(arrValues_Val[1], 'g', 3) + QString::fromStdString("°C \n\n <center>TC1 Miroir 2     : ")
                                      + QString::number(arrValues_Val[2], 'g', 3) + QString::fromStdString("°C \n\n <center>TC2 Miroir 2     : ")
                                      + QString::number(arrValues_Val[3], 'g', 3) + QString::fromStdString("°C \n\n <center>TC1 Miroir 3     : ")
                                      + QString::number(arrValues_Val[4], 'g', 3) + QString::fromStdString("°C \n\n <center>TC2 Miroir 3     : ")
                                      + QString::number(arrValues_Val[5], 'g', 3) + QString::fromStdString("°C \n\n"));
   Background_Text_Control(ui->Temperature, (arrErrors_Val[0] || arrErrors_Val[1] || arrErrors_Val[2] || arrErrors_Val[3] ||
                                                  arrErrors_Val[4] || arrErrors_Val[5]),
                                                 (arrErrors_Before_Val[0] || arrErrors_Before_Val[1] || arrErrors_Before_Val[2] || arrErrors_Before_Val[3] ||
                                                  arrErrors_Before_Val[4] || arrErrors_Before_Val[5]));

    // Affiche l'ensemble des tensions ainsi que l'état du groupe -> vert si tout va bien, rouge si au moins une des tensions est trop élevée
    ui->Tension->setText(QString::fromStdString("<center>Tension Cable M1 : ") + QString::number(arrValues_Val[6], 'g', 3) + QString::fromStdString("kN")
                   + QString::fromStdString("<center>Tension Cable M2 : ") + QString::number(arrValues_Val[7], 'g', 3) + QString::fromStdString("kN")
                   + QString::fromStdString("<center>Tension Cable M3 : ") + QString::number(arrValues_Val[8], 'g', 3) + QString::fromStdString("kN"));
    Background_Text_Control(ui->Tension, (arrErrors_Val[6] || arrErrors_Val[7] || arrErrors_Val[8]),
                                         (arrErrors_Before_Val[6] || arrErrors_Before_Val[7] || arrErrors_Before_Val[8]));

    // Affiche l'ensemble des positions moteurs ainsi que l'état du groupe -> vert si tout va bien, rouge si au moins une des positions est en butée ou pire
    if (Traitement_Commande_Value/100 != 0)
    {
        ui->Position->setText(QString::fromStdString("<center>Position M1X : ") + QString::number(arrValues_Val[9], 'g', 3) + QString::fromStdString(" tours")
                        + QString::fromStdString("<center>Position M1Y : ") + QString::number(arrValues_Val[10], 'g', 3) + QString::fromStdString(" tours")
                        + QString::fromStdString("<center>Position M2X : ") + QString::number(arrValues_Val[11], 'g', 3) + QString::fromStdString(" tours")
                        + QString::fromStdString("<center>Position M2Y : ") + QString::number(arrValues_Val[12], 'g', 3) + QString::fromStdString(" tours")
                        + QString::fromStdString("<center>Position M3X : ") + QString::number(arrValues_Val[13], 'g', 3) + QString::fromStdString(" tours")
                        + QString::fromStdString("<center>Position M3Y : ") + QString::number(arrValues_Val[14], 'g', 3) + QString::fromStdString(" tours"));
        Background_Text_Control(ui->Position, (arrErrors_Val[9] || arrErrors_Val[10] || arrErrors_Val[11] || arrErrors_Val[12] || arrErrors_Val[13] || arrErrors_Val[14]),
                                              (arrErrors_Before_Val[9] || arrErrors_Before_Val[10] || arrErrors_Before_Val[11] || arrErrors_Before_Val[12] || arrErrors_Before_Val[13] || arrErrors_Before_Val[14]));
    }
    else
    {
        ui->Position->setText("Initialisation en cours !");
        Background_Text_Control(ui->Position, (arrErrors_Val[9] || arrErrors_Val[10] || arrErrors_Val[11] || arrErrors_Val[12] || arrErrors_Val[13] || arrErrors_Val[14]),
                                              (arrErrors_Before_Val[9] || arrErrors_Before_Val[10] || arrErrors_Before_Val[11] || arrErrors_Before_Val[12] || arrErrors_Before_Val[13] || arrErrors_Before_Val[14]));
    }
    // Actualise les valeurs d'erreurs de la série précédente
    for (int i = 0; i < 15; i++) arrErrors_Before_Val[i] = arrErrors_Val[i];
}

// Procédure qui permet de relever toutes les nouvelles valeurs contenues dans le buffer depuis la dernière indentation
// Et de les ajouter à un fichier texte sous le format csv si l'utilisateur en a décidé ainsi -> défini par la variable bool add_data
void Update_data(Ui::MainWindow *ui)
{
    // On relève l'indice correspondant à la mesure de l'instant t
    nError = AdsSyncReadReq(pAddr, ADSIGRP_SYM_VALBYHND, indice_fin_Handle, sizeof(&indice_fin_value), &indice_fin_value);
        if (nError) cerr << "Error: AdsSyncReadReq: " << nError << '\n';

    // On relève ici toutes les valeurs de capteur
    nError = AdsSyncReadReq(pAddr, ADSIGRP_SYM_VALBYHND, arrData_Handle, sizeof(arrData_Val), &arrData_Val[0][0]);
      if (nError) cerr << "Error: AdsSyncReadReq: " << nError << '\n';

    // On regarde le nombre de données à récupérer par ligne
    int nb_data = size(arrValues_Val);

    // On regarde si l'utilisateur veut enregistrer la donnée puis on l'enregistre
    if (add_data)
    {
        // Si l'indice de fin est bien après l'indice actuel dans le tableau, on relève les données normales
        // (exemple indice_fin = 176, indice_Data = 123, on relève de 123 à 176 en incrémentant de 1)
        if (indice_fin_value > indice_Data)
        {
            // On parcourt toute les lignes
            for (int i = indice_Data; i < indice_fin_value; i++)
            {
                // On assigne les valeurs colonne par colonne
                for (int j = 0; j <= nb_data; j++)
                {
                    // On les assigne toutes les "periode d'échantillonnage" donc lorsque l'indice est égal à la période
                    if (Indice_releve == Periode_Releve){
                       if (j != nb_data) datafile << to_string(arrData_Val[i][j]) << ";" << ends;
                       else datafile << to_string(arrData_Val[i][j]) << endl;
                    }
                }
                // Soit on incrémente de 1 soit on revient à 1
                if (Indice_releve == Periode_Releve) Indice_releve = 1;
                else Indice_releve += 1;
            }
        }
        else
        {
            // Même chose que précédemment, seulement, si l'indice de fin est inférieur à l'indice actuel, on relève jusqu'à 199 et on revient à 0
            // (exemple indice_fin = 5, indice_Data = 170, on relève de 170 à 199 et de 0 à 5)
            for (int i = indice_Data; i < 200; i++)
            {
                for (int j = 0; j <= nb_data; j++)
                {
                    if (Indice_releve == Periode_Releve){
                       if (j != nb_data) datafile << to_string(arrData_Val[i][j]) << ";" << ends;
                       else datafile << to_string(arrData_Val[i][j]) << endl;
                    }
                }
                if (Indice_releve == Periode_Releve) Indice_releve = 1;
                else Indice_releve += 1;
            }
            for (int i = 0; i < indice_fin_value; i++)
            {
                for (int j = 0; j <= nb_data; j++)
                {
                    if (Indice_releve == Periode_Releve){
                        if (j != nb_data) datafile << to_string(arrData_Val[i][j]) << ";" << ends;
                        else datafile << to_string(arrData_Val[i][j]) << endl;
                    }
                }
                if (Indice_releve == Periode_Releve) Indice_releve = 1;
                else Indice_releve += 1;
            }
        }
    }

    // On actualise l'indice actuel
    indice_Data = indice_fin_value;
}

//--------------------------------------------------------------------------------
//-                                                                              -
//-                       DEFINITION DES SLOTS                                   -
//-                                                                              -
//--------------------------------------------------------------------------------

// procédure appelée lors du click sur LANCER CMD
// elle permet d'envoyer les consignes moteurs en fonction des angles demandés et de lancer la commande des moteurs
void MainWindow::on_CMD_MOTEUR_clicked()
{
    // Si le système est en attente, donc prêt à recevoir une commande, on relève d'abord nos valeurs entrées par l'Homme
    if (Traitement_Commande_Value == Commande_En_Attente)
    {
    QString Angle_Poloidal_Voulu;
    QString Angle_Toroidal_Voulu;
    Angle_Poloidal_Voulu = ui->Angle_Poloidal->toPlainText();
    Angle_Toroidal_Voulu = ui->Angle_Toroidal->toPlainText();

    // Ensuite, on affecte nos valeurs à envoyer à la variable Position_voulue qui est destinée à être envoyée au PLC
    // Pour cela on applique d'abord en amont la fonction de transfert pour obtenir la consigne moteur
    Position_voulue_M1X_Value = Angle_Poloidal_Voulu.toDouble();
    Position_voulue_M1Y_Value = Angle_Toroidal_Voulu.toDouble();

    // double Position_voulue_M1X = Angle_To_Motor_Position_M1X(Angle_Poloidal_Voulu, Angle_Toroidal_Voulu);

    // On l'écrit dans le PLC
    nError = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, Position_voulue_M1X_Handle, sizeof(Position_voulue_M1X_Value), &Position_voulue_M1X_Value);
      if (nError) cerr << "Error: AdsSyncWriteReq: " << nError << '\n';
    nError = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, Position_voulue_M1Y_Handle, sizeof(Position_voulue_M1Y_Value), &Position_voulue_M1Y_Value);
      if (nError) cerr << "Error: AdsSyncWriteReq: " << nError << '\n';
    // Do for all Motors

    // Et on finit par envoyer la commande de déplacement moteur
    Envoi_Commande(Commande_Moteurs);
    }
}

// procédure appelée lors du click Annuler -> annule la commande précédemment entrée et arrête les moteurs
void MainWindow::on_ANNUL_CMD_MOTEUR_clicked()
{
    if (Traitement_Commande_Value/100 == 2) Envoi_Commande(Commande_Annulation);
}

// procédure appelée lors du click Reset -> permet de réinitialiser les moteurs et le PLC en cas d'erreur notamment
void MainWindow::on_CMD_RESET_clicked()
{
    Envoi_Commande(Commande_Reset);
}

// Ferme la communication avec le PLC (et met dans un état d'arrêt ou rien ne se passe?)
void MainWindow::on_CMD_OFF_clicked()
{
    Close(ui);
}

// Ouvre la communication avec le PLC
void MainWindow::on_CMD_ON_clicked()
{
    Init(ui);
}

// procédure qui est appelée tous les Temps_de_raffraichissement millisecondes et utilise les fonctions implémentée ci-dessus
// Le bloc start, stop, duration permet d'afficher la durée des trois fonctions principales à s'exécuter
void MainWindow::update()
{
    if (Communication_etablie)
    {
        // auto start = high_resolution_clock::now();
        Update_ui(ui);
        Update_data(ui);
        Update_Etat_Commande(ui);
        // auto stop = high_resolution_clock::now();
        // auto duration = duration_cast<microseconds>(stop - start);
        // ui->Butee->setText(QString::fromStdString("<center>" + to_string(duration.count())));
    }
}

// Permet d'ajouter au fichier une dernière ligne pour indiquer que le relevé est terminé avant de fermer complètement le fichier et d'indiquer visuellement que l'on enregistre plus
void MainWindow::on_ARRETER_RELEVE_clicked()
{
    // On relève le temps actuel et on l'indique à la fin pour avoir la durée d'acquisition
    time(&rawtime);
    datafile << "FIN " << ctime(&rawtime) << "\n" << endl;

    // On ferme le fichier et on montre que l'enregistrement n'est plus en cours
    datafile.close();
    add_data = false;
    ui->file_name->setStyleSheet("background-color: red; font-size: 14pt;");
}

// Permet de créer le fichier demandé ou bien d'ajouter au fichier existant portant le même nom de nouvelles informations
// Lorsque le fichier est ouvert, on l'indique visuellement et on affecte à la variable add_data la valeur true
void MainWindow::on_CREER_FICHIER_clicked()
{
    // Relevé du nom du fichier entré par l'utilisateur et création du fichier de data
    QString filenameQ= ui->file_name->toPlainText();
    string filename = filenameQ.toStdString() + ".txt";
    datafile.open(filename, ios_base::app);

    // Initialisation du fichier pour obtenir l'en-tête des colonnes  et le temps actuel
    time(&rawtime);
    datafile << ctime(&rawtime);
    datafile << "TC1 M1;TC2 M1;TC1 M2;TC2 M2;TC1 M3;TC2 M3;Tens M1;Tens M2;Tens M3;Pos M1X;Pos M1Y;Pos M2X;Pos M2Y;Pos M3X;Pos M3Y";

    // On montre visuellement que le relevé de données a commencé
    ui->file_name->setStyleSheet("background-color: green; font-size: 14pt;");
    add_data = true;
}


void MainWindow::on_CMD_INIT_clicked()
{
    Envoi_Commande(Commande_Initialisation);
}


void MainWindow::on_CHANGER_FREQUENCE_clicked()
{
    if (not add_data) {

        // On relève la période d'échantillonage entrée
        Periode_Releve = ui->periode_echantillonnage->toPlainText().toInt();

        // Si la valeur est incorrecte, on obtient un 0, en cas de 0 on affecte la valeur par défaut
        if (Periode_Releve == 0) Periode_Releve = 10;
    }
}

