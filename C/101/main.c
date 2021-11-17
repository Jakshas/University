#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdbool.h>

void perm(int n, int tablica[]);

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        return 0;
    }
    int n=atoi(argv[1]);
    gtk_init(&argc, &argv);
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Krulowe");
    gtk_container_set_border_width(GTK_CONTAINER(window), 30);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    GtkWidget *box1 =gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);
    GtkWidget *grid =gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);
    GtkWidget *button =gtk_button_new_with_label("krulowa");
    gtk_container_add(GTK_CONTAINER(box1), button);
    GtkWidget *label=gtk_label_new("X");
    int tabela[100]= {-1};
    perm( n, tabela);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j=tabela[i])
            {
                label=gtk_label_new("X");
                gtk_grid_attach(GTK_GRID(grid),label, i, j, 1, 1);
            }
            else
            {
                label=gtk_label_new("O");
                gtk_grid_attach(GTK_GRID(grid),label, i, j, 1, 1);
            }
        }
        gtk_widget_show_all(window);
        gtk_main();
        return 0;
    }
}
void perm(int n, int tablica[])
{
    int nc=n;
    n=0;
    if(n<nc-1)
    {
        for(int i = n; i < nc; i++)
        {
            int c = tablica[n];
            tablica[n] = tablica[i];
            tablica[i] = c;
            perm(n+1,tablica);
        }
        int c = tablica[n];
        for(int i = n; i < nc-1; i++)
            tablica[i] = tablica[i+1];
        tablica[nc-1] = c;
    }
    else
    {
        int x=0;
        for(int p = 0; p < nc; p++)
        {
            for(int licznik=1; p+licznik < nc; licznik++)
            {
                if(tablica[p]+licznik==tablica[p+licznik])
                {
                    x++;
                    break;
                }
                for(int licznik=1; p+licznik < nc ; licznik++)
                    if(tablica[p]-licznik==tablica[p+licznik])
                    {
                        x++;
                        break;
                    }
            }
        }
    }
}
//Jakub Szajner
