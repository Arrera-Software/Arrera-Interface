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

    gtk_widget_show(fenetreAbout);
}

void fenetrePrincipale(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkImage *logoImage;
    const gchar* image_path = "ArreraInterfaceLogo.png";

    window = gtk_application_window_new (app);
    logoImage = GTK_IMAGE(gtk_image_new_from_file (image_path));
    gtk_image_get_icon_name (logoImage);
    gtk_window_set_title (GTK_WINDOW (window), "Arrera : Acceuil");
    gtk_window_set_default_size (GTK_WINDOW (window), 1000, 950);

    apropos();

    gtk_widget_show (window);
}
