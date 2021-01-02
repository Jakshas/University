#include "funkcje.h"
#include "main.h"
int p1[12][12]=
                        {
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,11,1,600,1,1000,1,0,11,1,600,1},
                    {1,0,1,0,1,10,1,0,1,1,0,1},
                    {1,203,1,0,203,0,203,0,1,300,0,1},
                    {1,0,0,0,1,1,1,0,1,1,0,1},
                    {1,100,1,0,0,0,0,0,400,0,0,1},
                    {1,1,1,400,1,1,203,1,1,1,0,1},
                    {1,0,0,0,203,0,0,1,0,0,0,1},
                    {1,0,1,0,1,0,0,0,0,1,1,1},
                    {1,0,1,0,0,0,1,1,0,0,0,1},
                    {1,2,1,300,1,0,1,100,0,1,3,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1}
                }
    ;
    int p2[12][12]=
                        {
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,11,1,600,1,1000,1,0,11,1,600,1},
                    {1,0,1,0,1,10,1,0,1,1,0,1},
                    {1,203,1,203,203,203,203,0,1,300,0,1},
                    {1,0,0,0,1,1,1,0,1,1,0,1},
                    {1,100,1,0,0,0,0,0,400,0,0,1},
                    {1,1,1,400,1,1,203,1,1,1,0,1},
                    {1,0,0,0,203,0,0,1,0,0,0,1},
                    {1,0,1,0,1,0,0,0,0,1,1,1},
                    {1,0,0,0,0,0,1,1,0,0,0,1},
                    {1,2,1,300,1,0,1,100,0,1,3,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1}
                }
    ;
    int p3[12][12]=
                        {
                    {1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,11,1,600,1,1000,1,0,11,1,600,1},
                    {1,0,1,0,1,10,1,0,1,1,0,1},
                    {1,203,1,203,203,203,203,0,1,300,0,1},
                    {1,0,0,0,1,1,1,0,1,1,0,1},
                    {1,100,1,0,0,0,0,0,400,0,0,1},
                    {1,1,1,400,1,1,203,1,1,1,0,1},
                    {1,0,0,0,203,0,0,1,0,0,0,1},
                    {1,0,1,0,1,0,0,0,0,1,1,1},
                    {1,0,1,0,0,0,1,1,0,0,0,1},
                    {1,2,0,300,1,0,1,100,0,1,3,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1}
                }
    ;

int main(int argc,char *argv[])
{
    Wska plansza;
    if ((potoki=initPipes(argc,argv)) == NULL)
        return 1;
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            plansza.wiodcznosc[j][i]=0;
        }
    }
    if(strcmp(argv[1],"B")==0)
    {
        plansza.gracz=2;
    }
    else
    {
        plansza.gracz=1;
    }
    for(int i=0; i<4; i++)
    {
        plansza.ekwipunek[i]=0;
    }
    if(plansza.gracz==1)
    {
        plansza.tura=1;
    }
    else
    {
        plansza.tura=0;
    }
    int ktora;
    if(plansza.gracz==1){
        srand(time(0));
            ktora=rand()%3;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
                if(ktora==0){
            plansza.t[j][i]=p1[j][i];}
             if(ktora==1){
            plansza.t[j][i]=p2[j][i];}
             if(ktora==2){
            plansza.t[j][i]=p3[j][i];}
        }
    }
    przepiszslowo(&plansza);
    sendStringToPipe(potoki,plansza.slowo);
    }
    gtk_init(&argc, &argv);
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Labirynt");
    gtk_container_set_border_width(GTK_CONTAINER(window), 30);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    GtkWidget *box1 =gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    GtkWidget *glowna =gtk_grid_new();
    GtkWidget *grid =gtk_grid_new();
    GtkWidget *grid2 =gtk_grid_new();
    GtkWidget *eq=gtk_grid_new();
    GtkWidget *gridt =gtk_grid_new();
    plansza.gridt=gridt;
    plansza.gridek=eq;
    GtkWidget *image;
    image = gtk_image_new_from_file ("up.jpg");
    GtkWidget *button = gtk_button_new();
    gtk_button_set_image (GTK_BUTTON (button), image);
    image = gtk_image_new_from_file ("left.jpg");
    GtkWidget *button1 = gtk_button_new();
    gtk_button_set_image (GTK_BUTTON (button1), image);
    image = gtk_image_new_from_file ("right.jpg");
    GtkWidget *button2 = gtk_button_new();
    gtk_button_set_image (GTK_BUTTON (button2), image);
    image = gtk_image_new_from_file ("down.jpg");
    GtkWidget *button3 = gtk_button_new();
    gtk_button_set_image (GTK_BUTTON (button3), image);
    plansza.window=window;
    gtk_box_pack_start(GTK_BOX(box1), glowna, TRUE, TRUE, 0);
    gtk_grid_attach(GTK_GRID(glowna),grid, 0,0,1,1);
    gtk_grid_attach(GTK_GRID(glowna),gridt, 3,0,1,1);
    gtk_grid_attach(GTK_GRID(glowna),grid2, 2,0,1,1);
    gtk_container_set_border_width(GTK_CONTAINER(grid2), 30);
    gtk_grid_attach(GTK_GRID(glowna),eq, 2,1,1,1);
    GtkWidget *label;
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    if(plansza.gracz==1)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=9; j<12; j++)
            {
                plansza.wiodcznosc[j][i]=1;
            }
        }
    }
    else
    {
        for(int i=9; i<12; i++)
        {
            for(int j=9; j<12; j++)
            {
                plansza.wiodcznosc[j][i]=1;
            }
        }
    }
    plansza.grid=grid;
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(plansza.wiodcznosc[j][i]==1)
            {
                switch(plansza.t[j][i])
                {
                case 1:
                    image=gtk_image_new_from_file("x.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 0:
                    image=gtk_image_new_from_file("pusty.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 2:
                    image=gtk_image_new_from_file("A.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 3:
                    image=gtk_image_new_from_file("B.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 10:
                    image=gtk_image_new_from_file("D.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 100:
                    image=gtk_image_new_from_file("Dz1.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 101:
                    image=gtk_image_new_from_file("Dz2.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 11:
                    image=gtk_image_new_from_file("K.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 203:
                case 202:
                case 201:
                    image=gtk_image_new_from_file("St.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;

                case 1000:
                    image=gtk_image_new_from_file("Sk.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 300:
                    image=gtk_image_new_from_file("M.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 600:
                    image=gtk_image_new_from_file("Ki.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                case 400:
                    image=gtk_image_new_from_file("Du.jpg");
                    plansza.pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
                    break;
                }
            }
            else
            {
                image=gtk_image_new_from_file("mgla.jpg");
                plansza.pola[j][i]=image;
                gtk_grid_attach(GTK_GRID(grid),plansza.pola[j][i], i, j, 1, 1);
            }

        }
    }
    gtk_grid_attach(GTK_GRID(grid2),button,6,2,1,1);
    gtk_grid_attach(GTK_GRID(grid2),button1,5,3,1,1);
    gtk_grid_attach(GTK_GRID(grid2),button2,7,3,1,1);
    gtk_grid_attach(GTK_GRID(grid2),button3,6,4,1,1);

    gtk_grid_set_row_spacing(GTK_GRID(eq), 0);
    gtk_grid_set_row_homogeneous(GTK_GRID(eq), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(eq), 0);
    gtk_grid_set_column_homogeneous(GTK_GRID(eq), TRUE);
    label=gtk_label_new("Ekwipunek");
    gtk_grid_attach(GTK_GRID(eq),label,0,0,4,1);
    for(int z=0; z<4; z++)
    {
        GtkWidget *frame = gtk_frame_new(NULL);
        gtk_grid_attach(GTK_GRID(eq),frame, z,1,1,1);
        image=gtk_image_new_from_file("pustek.jpg");
        plansza.ek[z]=image;
        gtk_grid_attach(GTK_GRID(eq),plansza.ek[z], z, 1, 1, 1);
    }
    if(plansza.gracz==1){
                    image=gtk_image_new_from_file("tr.jpg");
                    plansza.tu=image;
                    gtk_grid_attach(GTK_GRID(gridt),plansza.tu, 0, 0, 1, 1);
    }else{
    image=gtk_image_new_from_file("t.jpg");
                    plansza.tu=image;
                    gtk_grid_attach(GTK_GRID(gridt),plansza.tu, 0, 0, 1, 1);}
    gtk_widget_show_all(eq);
    g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), &plansza);
    g_timeout_add(100,pobierz_tekst,&plansza);
    g_signal_connect(button, "clicked",G_CALLBACK(button_clickedu),&plansza);
    g_signal_connect(button1, "clicked",G_CALLBACK(button_clickedl),&plansza);
    g_signal_connect(button2, "clicked",G_CALLBACK(button_clickedr),&plansza);
    g_signal_connect(button3, "clicked",G_CALLBACK(button_clickedd),&plansza);
    gtk_widget_show_all(window);
    gtk_main();
}
int button_clickedu(GtkWidget *widget, gpointer user_data)
{
    Wska *plansza=user_data;

    if(plansza->tura==1)
    {
        int x,y;
        for(int i=1; i<12; i++)
        {
            for(int j=1; j<12; j++)
            {
                if(plansza->t[i][j]==plansza->gracz+1)
                {
                    y=i;
                    x=j;
                }
            }
        }
        int ek=0;
        int pp=0;
        int j=0;
        GtkWidget *dialog;
        switch(plansza->t[y-1][x])
        {
        case 0:
            plansza->t[y][x]=0;
            plansza->t[y-1][x]=plansza->gracz+1;
            break;
        case 1:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==600)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y-1][x]=0;
                plansza->ekwipunek[j]=0;
            }else{
            return 0;
            }
            break;
        case 11:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                plansza->ekwipunek[ek]=11;

            }
            plansza->t[y][x]=0;
            plansza->t[y-1][x]=plansza->gracz+1;
            break;
        case 10:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==11)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y][x]=0;
                plansza->t[y-1][x]=plansza->gracz+1;
                plansza->ekwipunek[j]=0;
            }
            else
            {
            }
            break;
        case 100:
            plansza->t[y-1][x]=101;
            if(plansza->t[5][9]==0)
            {
                plansza->t[5][9]=1;
            }
            break;
        case 101:
            plansza->t[y-1][x]=100;
            if(plansza->t[5][9]==0)
            {
            plansza->t[5][9]=0;}
            break;
        case 203:
        case 202:
        case 201:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==300)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y-1][x]=201;
            }
            plansza->t[y-1][x]=plansza->t[y-1][x]-1;
            if(plansza->t[y-1][x]==200)
            {
                plansza->t[y-1][x]=0;
            }
            break;
        case 1000:
            plansza->t[y-1][x]=0;
            przepiszslowo(plansza);
            sendStringToPipe(potoki,plansza->slowo);
            dialog = gtk_message_dialog_new(GTK_WINDOW(plansza->window),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Wygrales");
            gtk_window_set_title(GTK_WINDOW(dialog), "Koniec gry");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(plansza->window);
            exit(1);
            break;
        case 300:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                ;
                plansza->ekwipunek[ek]=300;

            }
            plansza->t[y][x]=0;
            plansza->t[y-1][x]=plansza->gracz+1;
            break;
        case 600:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                plansza->ekwipunek[ek]=600;
            }
            plansza->t[y][x]=0;
            plansza->t[y-1][x]=plansza->gracz+1;
            break;
        case 400:
            plansza->t[y][x]=0;
            plansza->t[y-1][x]=0;
            srand(time(0));
            x=rand()%12;
            y=rand()%12;
            while(plansza->t[y][x]!=0)
            {
                x=rand()%12;
                y=rand()%12;
            }
            plansza->t[y][x]=plansza->gracz+1;
            for(int i=-1; i<2; i++)
            {
                for(int j=-1; j<2; j++)
                {
                    plansza->wiodcznosc[y+i][x+j]=1;
                }
            }
        }
        plansza->tura=1;
        if(plansza->t[y-1][x]==plansza->gracz+1)
        {
            for(int i=-1; i<2; i++)
            {
                plansza->wiodcznosc[y-2][x+i]=1;
            }
        }
        przepiszslowo(plansza);
        sendStringToPipe(potoki,plansza->slowo);
        plansza->tura=0;
        wypisz(plansza);
    }
}
int button_clickedd(GtkWidget *widget, gpointer user_data)
{
    Wska *plansza=user_data;
    char g[10];
    if(plansza->gracz==1)
    {
        strcpy(g,"A");
    }
    else
    {
        strcpy(g,"B");
    }
    int x,y;
    if(plansza->tura==1)
    {
        for(int i=1; i<12; i++)
        {
            for(int j=1; j<12; j++)
            {
                if(plansza->t[i][j]==plansza->gracz+1)
                {
                    y=i;
                    x=j;
                }
            }
        }
        int ek=0;
        int pp=0;
        int j=0;
        GtkWidget *dialog;
        switch(plansza->t[y+1][x])
        {
        case 1:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==600)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y+1][x]=0;
                plansza->ekwipunek[j]=0;
            }else{
            return 0;
            }
            break;
        case 0:
            plansza->t[y][x]=0;
            plansza->t[y+1][x]=plansza->gracz+1;
            break;
        case 100:
            plansza->t[y+1][x]=101;
            if(plansza->t[5][9]==0)
            {
                plansza->t[5][9]=1;
            }
            break;
        case 101:
            plansza->t[y+1][x]=100;
            plansza->t[5][9]=0;
            break;
        case 11:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                plansza->ekwipunek[ek]=11;
            }
            plansza->t[y][x]=0;
            plansza->t[y+1][x]=plansza->gracz+1;
            break;
        case 203:
        case 202:
        case 201:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==300)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y+1][x]=201;
            }
            plansza->t[y+1][x]=plansza->t[y+1][x]-1;
            if(plansza->t[y+1][x]==200)
            {
                plansza->t[y+1][x]=0;
            }
            break;
        case 10:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==11)
                {
                    ek++;
                }
            }
            if(ek>0)
            {
                plansza->t[y][x]=0;
                plansza->t[y+1][x]=plansza->gracz+1;
            }
            break;
        case 1000:
            plansza->t[y+1][x]=0;
            przepiszslowo(plansza);
            sendStringToPipe(potoki,plansza->slowo);
            dialog = gtk_message_dialog_new(GTK_WINDOW(plansza->window),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Wygrales");
            gtk_window_set_title(GTK_WINDOW(dialog), "Information");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
            exit(1);
            break;
        case 300:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                ;
                plansza->ekwipunek[ek]=300;

            }
            plansza->t[y][x]=0;
            plansza->t[y+1][x]=plansza->gracz+1;
            break;
        case 600:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                ;
                plansza->ekwipunek[ek]=600;

            }
            plansza->t[y][x]=0;
            plansza->t[y+1][x]=plansza->gracz+1;
            break;
        case 400:
            plansza->t[y][x]=0;
            plansza->t[y+1][x]=0;
            srand(time(0));
            x=rand()%12;
            y=rand()%12;
            while(plansza->t[y][x]!=0)
            {
                x=rand()%12;
                y=rand()%12;
            }
            printf("%d,%d",x,y);
            plansza->t[y][x]=plansza->gracz+1;
            for(int i=-1; i<2; i++)
            {
                for(int j=-1; j<2; j++)
                {
                    plansza->wiodcznosc[y+i][x+j]=1;
                }
            }
        }
        plansza->tura=1;
        if(plansza->t[y+1][x]==plansza->gracz+1)
        {
            for(int i=-1; i<2; i++)
            {
                plansza->wiodcznosc[y+2][x+i]=1;
            }
        }
        przepiszslowo(plansza);
        sendStringToPipe(potoki,plansza->slowo);
        plansza->tura=0;
        wypisz(plansza);
    }
}
int button_clickedl(GtkWidget *widget, gpointer user_data)
{
    Wska *plansza=user_data;
    char g[10];
    if(plansza->gracz==1)
    {
        strcpy(g,"A");
    }
    else
    {
        strcpy(g,"B");
    }
    int x,y;
    if(plansza->tura==1)
    {
        for(int i=1; i<12; i++)
        {
            for(int j=1; j<12; j++)
            {
                if(plansza->t[i][j]==plansza->gracz+1)
                {
                    y=i;
                    x=j;
                }
            }
        }
        int ek=0;
        int pp=0;
        int j=0;
        GtkWidget *dialog;
        switch(plansza->t[y][x-1])
        {
        case 0:
            plansza->t[y][x]=0;
            plansza->t[y][x-1]=plansza->gracz+1;
            break;
        case 1:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==600)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y][x-1]=0;
                plansza->ekwipunek[j]=0;
            }
            else{
            return 0;
            }
            break;
        case 11:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                plansza->ekwipunek[ek]=11;
            }
            plansza->t[y][x]=0;
            plansza->t[y][x-1]=plansza->gracz+1;
            break;
        case 203:
        case 202:
        case 201:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==300)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y][x-1]=201;
            }
            plansza->t[y][x-1]=plansza->t[y][x-1]-1;
            if(plansza->t[y][x-1]==200)
            {
                plansza->t[y][x-1]=0;
            }
            break;
        case 10:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==11)
                {
                    ek++;
                }
            }
            if(ek>0)
            {
                plansza->t[y][x]=0;
                plansza->t[y][x-1]=plansza->gracz+1;
            }
            break;
        case 100:
            plansza->t[y][x-1]=101;
            if(plansza->t[5][9]==0)
            {
                plansza->t[5][9]=1;
            }
            break;
        case 101:
            plansza->t[y][x-1]=100;
            plansza->t[5][9]=0;
            break;
        case 1000:
            plansza->t[y][x-1]=0;
            przepiszslowo(plansza);
            sendStringToPipe(potoki,plansza->slowo);
            dialog = gtk_message_dialog_new(GTK_WINDOW(plansza->window),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Wygrales");
            gtk_window_set_title(GTK_WINDOW(dialog), "Information");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
            exit(1);
            break;
        case 300:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                ;
                plansza->ekwipunek[ek]=300;

            }
            plansza->t[y][x]=0;
            plansza->t[y][x-1]=plansza->gracz+1;
            break;
        case 600:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                ;
                plansza->ekwipunek[ek]=600;

            }
            plansza->t[y][x]=0;
            plansza->t[y][x-1]=plansza->gracz+1;
            break;
        case 400:
            plansza->t[y][x]=0;
            plansza->t[y][x-1]=0;

            srand(time(0));
            x=rand()%12;
            y=rand()%12;
            while(plansza->t[y][x]!=0)
            {
                x=rand()%12;
                y=rand()%12;
            }
            printf("%d,%d",x,y);
            plansza->t[y][x]=plansza->gracz+1;
            for(int i=-1; i<2; i++)
            {
                for(int j=-1; j<2; j++)
                {
                    plansza->wiodcznosc[y+i][x+j]=1;
                }
            }
            break;
        }
        plansza->tura=1;
        if(plansza->t[y][x-1]==plansza->gracz+1)
        {
            for(int i=-1; i<2; i++)
            {
                plansza->wiodcznosc[y+i][x-2]=1;
            }
        }
        przepiszslowo(plansza);
        sendStringToPipe(potoki,plansza->slowo);
        plansza->tura=0;
        wypisz(plansza);
    }
}
int button_clickedr(GtkWidget *widget, gpointer user_data)
{
    Wska *plansza=user_data;
    char g[10];
    if(plansza->gracz==1)
    {
        strcpy(g,"A");
    }
    else
    {
        strcpy(g,"B");
    }
    if(plansza->tura==1)
    {
        int x,y;
        for(int i=1; i<12; i++)
        {
            for(int j=1; j<12; j++)
            {
                if(plansza->t[i][j]==plansza->gracz+1)
                {
                    y=i;
                    x=j;
                }
            }
        }
        int ek=0;
        int pp=0;
        int j=0;
        GtkWidget *dialog;
        switch(plansza->t[y][x+1])
        {
        case 0:
            plansza->t[y][x]=0;
            plansza->t[y][x+1]=plansza->gracz+1;
            break;
        case 1:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==600)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y][x+1]=0;
                plansza->ekwipunek[j]=0;
            }
            else{
            return 0;
            }
            break;
        case 11:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                plansza->ekwipunek[ek]=11;
            }
            plansza->t[y][x]=0;
            plansza->t[y][x+1]=plansza->gracz+1;
            plansza->t[y][x]=0;
            plansza->t[y][x+1]=plansza->gracz+1;
            break;
        case 100:
            plansza->t[y][x+1]=101;
            if(plansza->t[5][9]==0)
            {
                plansza->t[5][9]=1;
            }
            break;
        case 101:
            plansza->t[y][x+1]=100;
            plansza->t[5][9]=0;
            break;
        case 203:
        case 202:
        case 201:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==300)
                {
                    j=i;
                    pp++;
                }
            }
            if(pp>0)
            {
                plansza->t[y][x+1]=201;
            }
            plansza->t[y][x+1]=plansza->t[y][x+1]-1;
            if(plansza->t[y][x+1]==200)
            {
                plansza->t[y][x+1]=0;
            }
            break;
        case 10:
            for(int i=0; i<4; i++)
            {
                if(plansza->ekwipunek[i]==11)
                {
                    ek++;
                }
            }
            if(ek>0)
            {
                plansza->t[y][x]=0;
                plansza->t[y][x+1]=plansza->gracz+1;
            }
            break;

        case 1000:
            plansza->t[y][x+1]=0;
            przepiszslowo(plansza);
            sendStringToPipe(potoki,plansza->slowo);
            dialog = gtk_message_dialog_new(GTK_WINDOW(plansza->window),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Wygrales");
            gtk_window_set_title(GTK_WINDOW(dialog), "Information");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
            exit(1);
            break;
        case 300:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                ;
                plansza->ekwipunek[ek]=300;

            }
            plansza->t[y][x]=0;
            plansza->t[y][x+1]=plansza->gracz+1;
            break;
        case 600:
            while(plansza->ekwipunek[ek]!=0)
            {
                ek++;
            }
            if(ek>3)
            {
                break;
            }
            else
            {
                ;
                plansza->ekwipunek[ek]=600;

            }
            plansza->t[y][x]=0;
            plansza->t[y][x+1]=plansza->gracz+1;
            break;
        case 400:
            plansza->t[y][x]=0;
            plansza->t[y][x+1]=0;
            srand(time(0));
            x=rand()%12;
            y=rand()%12;
            while(plansza->t[y][x]!=0)
            {
                x=rand()%12;
                y=rand()%12;
            }
            printf("%d,%d",x,y);
            plansza->t[y][x]=plansza->gracz+1;
            for(int i=-1; i<2; i++)
            {
                for(int j=-1; j<2; j++)
                {
                    plansza->wiodcznosc[y+i][x+j]=1;
                }
            }
        }
        plansza->tura=1;
        if(plansza->t[y][x+1]==plansza->gracz+1)
        {
            for(int i=-1; i<2; i++)
            {
                plansza->wiodcznosc[y+i][x+2]=1;
            }
        }
        przepiszslowo(plansza);
        sendStringToPipe(potoki,plansza->slowo);
        plansza->tura=0;
        wypisz(plansza);
    }
}
void wypisz(Wska *plansza)
{
    GtkWidget *image;
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(plansza->wiodcznosc[j][i]==1)
            {
                gtk_widget_destroy(plansza->pola[j][i]);
                switch(plansza->t[j][i])
                {
                case 1:
                    image=gtk_image_new_from_file("x.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 0:
                    image=gtk_image_new_from_file("pusty.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 2:
                    image=gtk_image_new_from_file("A.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 3:
                    image=gtk_image_new_from_file("B.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 10:
                    image=gtk_image_new_from_file("D.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 100:
                    image=gtk_image_new_from_file("Dz1.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 101:
                    image=gtk_image_new_from_file("Dz2.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 11:
                    image=gtk_image_new_from_file("K.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 203:
                    image=gtk_image_new_from_file("St.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 202:
                    image=gtk_image_new_from_file("St1.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 201:
                    image=gtk_image_new_from_file("St2.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 1000:
                    image=gtk_image_new_from_file("Sk.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 300:
                    image=gtk_image_new_from_file("M.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 400:
                    image=gtk_image_new_from_file("Du.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                case 600:
                    image=gtk_image_new_from_file("Ki.jpg");
                    plansza->pola[j][i]=image;
                    gtk_grid_attach(GTK_GRID(plansza->grid),plansza->pola[j][i], i, j, 1, 1);
                    break;
                }
            }
        }
        gtk_widget_show_all(plansza->grid);
    }
    for(int z=0; z<4; z++)
    {
        gtk_widget_destroy(plansza->ek[z]);
        switch(plansza->ekwipunek[z])
        {
        case 0:
            image=gtk_image_new_from_file("pustek.jpg");
            plansza->ek[z]=image;
            gtk_grid_attach(GTK_GRID(plansza->gridek),plansza->ek[z], z, 1, 1, 1);
            break;
        case 11:
            image=gtk_image_new_from_file("Kek.jpg");
            plansza->ek[z]=image;
            gtk_grid_attach(GTK_GRID(plansza->gridek),plansza->ek[z], z, 1, 1, 1);
            break;
        case 300:
            image=gtk_image_new_from_file("Mek.jpg");
            plansza->ek[z]=image;
            gtk_grid_attach(GTK_GRID(plansza->gridek),plansza->ek[z], z, 1, 1, 1);
            break;
        case 600:
            image=gtk_image_new_from_file("Kiek.jpg");
            plansza->ek[z]=image;
            gtk_grid_attach(GTK_GRID(plansza->gridek),plansza->ek[z], z, 1, 1, 1);
            break;
        }
    }
    if(plansza->gracz==1){
        if(plansza->tura==1){
                gtk_widget_destroy(plansza->tu);
                    image=gtk_image_new_from_file("tr.jpg");
                    plansza->tu=image;
                    gtk_grid_attach(GTK_GRID(plansza->gridt),plansza->tu, 0, 0, 1, 1);
                    }else{
                        gtk_widget_destroy(plansza->tu);
                    image=gtk_image_new_from_file("t.jpg");
                    plansza->tu=image;
                    gtk_grid_attach(GTK_GRID(plansza->gridt),plansza->tu, 0, 0, 1, 1);
                    }
    }else{
    if(plansza->tura==1){
            gtk_widget_destroy(plansza->tu);
                    image=gtk_image_new_from_file("tb.jpg");
                    plansza->tu=image;
                    gtk_grid_attach(GTK_GRID(plansza->gridt),plansza->tu, 0, 0, 1, 1);
                    }else{
                        gtk_widget_destroy(plansza->tu);
                    image=gtk_image_new_from_file("t.jpg");
                    plansza->tu=image;
                    gtk_grid_attach(GTK_GRID(plansza->gridt),plansza->tu, 0, 0, 1, 1);
                    }}
    gtk_widget_show_all(plansza->gridek);
    gtk_widget_show_all(plansza->gridt);
}
void zakoncz(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

gboolean pobierz_tekst(gpointer data)
{
    Wska *plansza=data;
    gchar wejscie[MAKS_DL_TEKSTU];
    if (getStringFromPipe(potoki,wejscie,MAKS_DL_TEKSTU))
    {
        strcpy(plansza->slowo,wejscie);
        wypiszslowo(plansza);
        if(plansza->t[1][5]!=1000)
        {
            GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(plansza->window),
                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                GTK_MESSAGE_INFO,
                                GTK_BUTTONS_OK,
                                "Przeciwnik Wygral");
            gtk_window_set_title(GTK_WINDOW(dialog), "Information");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
            exit(1);
        }
        plansza->tura=1;
        wypisz(plansza);
    }
    return TRUE;
}
void on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    switch (event->keyval)
    {
    case 'w':
        button_clickedu(widget,user_data);
        break;
    case 's':
        button_clickedd(widget,user_data);
        break;
    case 'a':
        button_clickedl(widget,user_data);
        break;
    case 'd':
        button_clickedr(widget,user_data);
        break;
    }
}
