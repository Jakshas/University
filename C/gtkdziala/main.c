#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdbool.h>

typedef struct
{
    int n;
    int perm[1000];
    GtkWidget *clickers[1000][1000];
} arguments;

bool next_perm(int n, int p[n])
{
    if(n==1)
        return false;
    if(!next_perm(n-1,p+1))
    {
        if(p[0]>p[1])
            return false;

        else
        {
            for(int i=n-1; i>0; i--)
                if(p[i]>p[0])
                {
                    int a=p[0];
                    p[0]=p[i];
                    p[i]=a;
                    break;
                }
            for(int j=1; j<n/2+n%2; j++)
            {
                int a=p[j];
                p[j]=p[n-j];
                p[n-j]=a;
            }
            return true;
        }
    }
    else return true;
}
static void button_clicked(GtkWidget *widget, gpointer user_data)
{
    arguments *arg = user_data;
    for(int i=0; i<arg->n; i++)
        for(int j=0; j<arg->n; j++)
        {
            if(arg->perm[i]==j+1)
                gtk_label_set_text(GTK_LABEL(arg->clickers[i][j]), "X");
            else
                gtk_label_set_text(GTK_LABEL(arg->clickers[i][j]), " ");
        }
    next_perm(arg->n, arg->perm);
}
int main (int argc, char *argv[])
{
    if(argc<2)
        exit(1);

    arguments T;
    T.n=atoi(argv[1]);
    for(int i=0; i<T.n; i++)
        T.perm[i]=i+1;


    gtk_init(&argc, &argv);

    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Permutacje");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);

    GtkWidget *grid;
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 0);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 0);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);



    for(int i = 0; i<T.n; i++)
        for(int j=0; j<T.n; j++)
        {
            GtkWidget *label = gtk_label_new(" ");
            T.clickers[i][j]=label;
            gtk_grid_attach(GTK_GRID(grid), label, i, j, 1, 1);

            GtkWidget *frame = gtk_frame_new(NULL);
            gtk_grid_attach(GTK_GRID(grid),frame, i,j,1,1);

        }


    GtkWidget *button = gtk_button_new_with_label("Start");
    gtk_box_pack_end(GTK_BOX(box1), button, TRUE, TRUE, 10);

    g_signal_connect(button, "clicked" ,G_CALLBACK(button_clicked),&T);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
