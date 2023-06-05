#include "interface.h"

void fenetrePrincipale(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *grille;
    GtkWidget *cadre;
    GtkWidget *box ;
    //bouton
    GtkWidget *boutonApropos ;
    GtkWidget *boutonSetting;
    GtkWidget *boutonAssistant1;
    GtkWidget *boutonAssistant2;
    GtkWidget *boutonTableur;
    GtkWidget *boutonText;
    GtkWidget *boutonGesMTP;
    GtkWidget *boutonAppArrera;


    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Arrera : Acceuil");
    gtk_window_set_default_size (GTK_WINDOW (window), 1000, 950);
    //Creation des bouton
    boutonApropos = gtk_button_new_with_label ("A propos");
    boutonSetting = gtk_button_new_with_label("Parametre");

    boutonAssistant1 = gtk_button_new_with_label("SIX");
    boutonAssistant2 = gtk_button_new_with_label("Ryley");
    boutonTableur = gtk_button_new_with_label("Application Tableur");
    boutonText = gtk_button_new_with_label("Traitement de texte");
    boutonGesMTP = gtk_button_new_with_label("Gestionnaire de mots de passe");
    boutonAppArrera = gtk_button_new_with_label("Application Arrera");
    //Creation de la grille
    grille = gtk_grid_new();
    //expension de la grille
    gtk_widget_set_vexpand(grille,true);
    gtk_widget_set_hexpand(grille,true);
    //Ajout de la fonction des bouton
    g_signal_connect(boutonApropos,"clicked",G_CALLBACK(apropos),NULL);
    //Atache des widget sur la grille
    gtk_grid_attach(GTK_GRID(grille),boutonApropos,0,0,1,1);
    gtk_grid_attach(GTK_GRID(grille),boutonSetting,0,1,1,1);

    gtk_grid_attach(GTK_GRID(grille),boutonAssistant1,0,2,1,1);
    gtk_grid_attach(GTK_GRID(grille),boutonAssistant2,0,3,1,1);
    gtk_grid_attach(GTK_GRID(grille),boutonTableur,0,4,1,1);
    gtk_grid_attach(GTK_GRID(grille),boutonText,0,5,1,1);
    gtk_grid_attach(GTK_GRID(grille),boutonGesMTP,0,6,1,1);
    gtk_grid_attach(GTK_GRID(grille),boutonAppArrera,0,7,1,1);
    //affichage
    gtk_window_set_child(GTK_WINDOW(window),grille);
    gtk_widget_set_visible(window,true);
}
