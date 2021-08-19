#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QTimer>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void update();

    //--------------------------------------------------------------------------------
    //-                                                                              -
    //-                DEFINITION DES FONCTIONS LIEES AUX BOUTONS                    -
    //-                                                                              -
    //--------------------------------------------------------------------------------

private slots:
    void on_CMD_MOTEUR_clicked();
    void on_ANNUL_CMD_MOTEUR_clicked();
    void on_CMD_RESET_clicked();
    void on_CMD_OFF_clicked();
    void on_CMD_ON_clicked();

    void on_ARRETER_RELEVE_clicked();
    void on_CREER_FICHIER_clicked();

    void on_CMD_INIT_clicked();

    void on_CHANGER_FREQUENCE_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;

    //--------------------------------------------------------------------------------
    //-                                                                              -
    //-             DEFINITION DES ELEMENTS INTERACTIFS DE L'INTERFACE               -
    //-                                                                              -
    //--------------------------------------------------------------------------------

    QTextBrowser *Butee;
    QTextBrowser *Position;
    QTextBrowser *Temperature;
    QTextBrowser *Tension;
    QTextBrowser *Traitement_Commande;
    QTextBrowser *Etat_Systeme;
    QTextEdit *Angle_Poloidal;
    QTextEdit *Angle_Toroidal;
    QTextEdit *Angle_Poloidal_2;
    QTextEdit *Angle_Toroidal_2;
    QTextEdit *Angle_Poloidal_3;
    QTextEdit *Angle_Toroidal_3;
    QTextEdit *file_name;
    QTextEdit *periode_echantillonage;

};
#endif // MAINWINDOW_H
