#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

// Fonction pour afficher le nom du bouton dans une nouvelle fenêtre
void afficher_nom(GtkWidget *widget, gpointer data) {
    const gchar *nom = gtk_button_get_label(GTK_BUTTON(widget));

    // Création d'une nouvelle fenêtre
    GtkWidget *fenetre_nom = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(fenetre_nom), "Nom du bouton");
    gtk_window_set_default_size(GTK_WINDOW(fenetre_nom), 400, 200);
    gtk_container_set_border_width(GTK_CONTAINER(fenetre_nom), 10);

    // Label pour afficher le nom du bouton
    GtkWidget *label = gtk_label_new(NULL);
    gtk_label_set_text(GTK_LABEL(label), nom);

    // Ajout du label à la fenêtre
    gtk_container_add(GTK_CONTAINER(fenetre_nom), label);

    // Affichage de la fenêtre
    gtk_widget_show_all(fenetre_nom);
}

int main(int argc, char **argv) {
    GtkWidget *laboite;
    GtkWidget *hbox;
    GtkWidget *btnStart;
    GtkWidget *btnConfig;
    GtkWidget *btnHelp;

    gtk_init(&argc, &argv);

    laboite = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(laboite), 800, 600);
    gtk_window_set_position(GTK_WINDOW(laboite), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(laboite), "D A C T Y L O G I C I E L");

    hbox = gtk_vbox_new(TRUE, 15);

    btnStart = gtk_button_new_with_label("Démarrer");
    btnConfig = gtk_button_new_with_label("Configuration");
    btnHelp = gtk_button_new_with_label("Aide");

    gtk_container_add(GTK_CONTAINER(laboite), hbox);

    // Connexion des signaux pour afficher le nom du bouton dans une nouvelle fenêtre
    g_signal_connect(btnStart, "clicked", G_CALLBACK(afficher_nom), NULL);
    g_signal_connect(btnConfig, "clicked", G_CALLBACK(afficher_nom), NULL);
    g_signal_connect(btnHelp, "clicked", G_CALLBACK(afficher_nom), NULL);

    gtk_box_pack_start(GTK_BOX(hbox), btnStart, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), btnConfig, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), btnHelp, TRUE, TRUE, 0);

    gtk_widget_show_all(laboite);

    gtk_main();

    return EXIT_SUCCESS;
}
