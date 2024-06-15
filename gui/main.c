#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>


int main(int argc, char **argv) {

    GtkWidget *laboite;
    GtkWidget *hbox;
    GtkWidget *btnStart;
    GtkWidget *btnConfig;
    GtkWidget *btnHelp;

    gtk_init(&argc, &argv);

    laboite = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(laboite), 1920, 1080);
    gtk_window_set_position(GTK_WINDOW(laboite), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(laboite), "D A C T Y L O G I C I E L");



    hbox = gtk_vbox_new(TRUE, 15);

    btnStart = gtk_button_new_with_label("Dmarrer");
    btnConfig = gtk_button_new_with_label("Configuration");
    btnHelp = gtk_button_new_with_label("Aide");

    gtk_container_add(GTK_CONTAINER(laboite), hbox);

    gtk_box_pack_start(GTK_BOX(hbox), btnStart, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), btnConfig, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), btnHelp, TRUE, TRUE, 0);


    gtk_widget_show_all(laboite);

    gtk_main();



  return EXIT_SUCCESS;
}