#include <gtk/gtk.h>


#define NAMEAPP "Arrera Interface"
#define VERSION "I2023-1.00.dev05/2023"
#define COPYRIGHT "Copyright Arrera Software by Baptiste P 2023-"

void apropos()
{
    GtkWidget *fenetreAbout;
    GtkImage *logoImage;
    GdkPaintable *logoPaintable;
    const gchar* image_path = "ArreraInterfaceLogo.png";

    fenetreAbout = gtk_about_dialog_new();

    //Ajout du nom dans le fenetre a propos
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(fenetreAbout),NAMEAPP);

    //mise du logo
    logoImage = GTK_IMAGE(gtk_image_new_from_file (image_path));
    logoPaintable = gtk_image_get_paintable (logoImage);
    gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(fenetreAbout),logoPaintable);

    //Affichage de la version
    gtk_about_dialog_set_version (GTK_ABOUT_DIALOG(fenetreAbout),VERSION);

    //Affichage des copyright
    gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG(fenetreAbout),COPYRIGHT);

    gtk_widget_set_visible(fenetreAbout,true);
}

void fenetrePrincipale(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *gridMain;
    //bouton
    GtkWidget *boutonApropos ;
    GtkWidget *boutonSetting;
    GtkWidget *boutonAssistant1;
    GtkWidget *boutonAssistant2;
    GtkWidget *boutonTableur;
    GtkWidget *boutonText;
    GtkWidget *boutonGesMTP;
    GtkWidget *boutonAppArrera;
    //box
    GtkWidget *boxBottom;
    GtkWidget *boxMain1 ;
    GtkWidget *boxMain2 ;
    //layout
    GtkLayoutManager *layoutBottom;
    GtkLayoutManager *layoutMain1;
    GtkLayoutManager *layoutMain2;
    //Creation de la fenetre
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
    //Creation des deux box
    boxMain1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    boxMain2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    boxBottom = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    //Creation des layout
    layoutMain1 = gtk_box_layout_new(GTK_ORIENTATION_HORIZONTAL);
    layoutMain2 = gtk_box_layout_new(GTK_ORIENTATION_HORIZONTAL);
    layoutBottom = gtk_box_layout_new(GTK_ORIENTATION_HORIZONTAL);
    //parametrage Layout
    gtk_box_layout_set_spacing(GTK_BOX_LAYOUT(layoutMain1),40);
    gtk_box_layout_set_spacing(GTK_BOX_LAYOUT(layoutMain2),40);
    gtk_box_layout_set_spacing(GTK_BOX_LAYOUT(layoutBottom),80);
    //Ajout des layout au box
    gtk_widget_set_layout_manager(boxMain1,layoutMain1);
    gtk_widget_set_layout_manager(boxMain2,layoutMain2);
    gtk_widget_set_layout_manager(boxBottom,layoutBottom);
    //ajout des bouton au box
    //boxMain1
    gtk_box_append(GTK_BOX(boxMain1),boutonAssistant1);
    gtk_box_append(GTK_BOX(boxMain1),boutonAppArrera);
    gtk_box_append(GTK_BOX(boxMain1),boutonAssistant2);
    //boxMain2
    gtk_box_append(GTK_BOX(boxMain2),boutonTableur);
    gtk_box_append(GTK_BOX(boxMain2),boutonGesMTP);
    gtk_box_append(GTK_BOX(boxMain2),boutonText);
    //boxBottom
    gtk_box_append(GTK_BOX(boxBottom),boutonApropos);
    gtk_box_append(GTK_BOX(boxBottom),boutonSetting);
    //Creation de la grille
    gridMain = gtk_grid_new();
    //Ajout de la fonction des bouton
    g_signal_connect(boutonApropos,"clicked",G_CALLBACK(apropos),NULL);
    //Ajout des box a la grille
    gtk_grid_attach(GTK_GRID(gridMain),boxMain1,0,0,1,1);
    gtk_grid_attach(GTK_GRID(gridMain),boxMain2,0,1,1,1);
    gtk_grid_attach(GTK_GRID(gridMain),boxBottom,2,2,1,1);
    // Définition de l'alignement et de l'expansion des widgets

    gtk_widget_set_halign(boxMain1, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(boxMain1, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand(boxMain1, TRUE);
    gtk_widget_set_vexpand(boxMain1, TRUE);

    gtk_widget_set_halign(boxMain2, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(boxMain2, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand(boxMain2, TRUE);
    gtk_widget_set_vexpand(boxMain2, TRUE);

    //affichage
    gtk_window_set_child(GTK_WINDOW(window),gridMain );
    gtk_widget_set_visible(window,true);
}
