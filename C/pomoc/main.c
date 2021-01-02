#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

void value_changed(GtkRange *range, gpointer win)
{
    gdouble val = gtk_range_get_value(range);
    gchar *str = g_strdup_printf("%.f", val);
    gtk_label_set_text(GTK_LABEL(win), str);

    g_free(str);
}
typedef struct start
{
    GtkWidget *window2;
    GtkWidget *box;
    GtkWidget *skalapl;
    GtkWidget *skalanum;
    GtkWidget *ilosckul[4];
    GtkWidget *nazwa[3];
     gint n;
    GtkWidget *przycisk[400];
    GtkWidget *tabela;
} start;
static void poczatek( struct start *str);

int main(int argc, char *argv[])
{
    struct start *str;
    str=(start *)malloc(sizeof(start));

    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 250);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_title(GTK_WINDOW(window), "Kulki");

    poczatek(str);

    gtk_container_add(GTK_CONTAINER(window),str-> window2);

    g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

static void poczatek( struct start *str)
{
    str->window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(str->window2), GTK_WIN_POS_CENTER_ON_PARENT);
    gtk_window_set_default_size(GTK_WINDOW(str->window2), 100, 150);
    gtk_container_set_border_width(GTK_CONTAINER(str->window2), 10);
    gtk_window_set_title(GTK_WINDOW(str->window2), "Kulki");

    str->box = gtk_grid_new();
    str->nazwa[0]=gtk_label_new("Liczba kul pojawiaj¹cych siê:");
    gtk_grid_attach(GTK_GRID(str->box),str->nazwa[0],0,1,1,1);

    str->skalapl = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,5, 20, 1);
    gtk_scale_set_draw_value(GTK_SCALE(str->skalapl), FALSE);
    gtk_widget_set_size_request(str->skalapl, 150, 2);
    str->skalanum = gtk_label_new("...");
    gtk_misc_set_alignment(GTK_MISC(str->skalanum), 0.0, 1);

    for (int h=0; h<4; h++)
    {
        char tab[4];
        tab[0]=(char)(h+'1');
        tab[1]='x';
        tab[2]=(char)(h+'1');
        tab[3]='\0';

        str->ilosckul[h]=gtk_check_button_new_with_label(tab);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(str->ilosckul[h]), FALSE);
        gtk_grid_attach(GTK_GRID(str->box),str->ilosckul[h],h,3,1,1);
    }
    str->nazwa[1]=gtk_label_new("Wielkoœæ planszy:");
    gtk_grid_attach(GTK_GRID(str->box),str->nazwa[1],0,5,1,1);

    gtk_grid_attach(GTK_GRID(str->box),str->skalapl,1,6,1,1);
    gtk_grid_attach(GTK_GRID(str->box),str->skalanum,20,6,1,1);

      str->nazwa[2]=gtk_label_new("Iloœæ kolorów:");
    gtk_grid_attach(GTK_GRID(str->box),str->nazwa[2],0,7,1,1);

    for (int h=0; h<5; h++)
    {
        char tab[2];
        tab[0]=(char)(h+'3');
        tab[1]='\0';

        str->ilosckul[h]=gtk_check_button_new_with_label(tab);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(str->ilosckul[h]), FALSE);
        gtk_grid_attach(GTK_GRID(str->box),str->ilosckul[h],h,9,1,1);
    }

    gtk_container_add(GTK_CONTAINER(str->window2),str-> box);

    g_signal_connect(str->window2, "destroy",G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(str->skalapl, "value-changed",G_CALLBACK(value_changed),str->skalanum);

    gtk_widget_show_all(str->window2);
}

static void podstaw(GtkWidget *widget, struct pl *wpl) {

 g_print("%d",widget);
}
