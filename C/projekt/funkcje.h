#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#define MAKS_DL_TEKSTU 10000
int button_clickedu(GtkWidget *widget, gpointer user_data);
int button_clickedd(GtkWidget *widget, gpointer user_data);
int button_clickedl(GtkWidget *widget, gpointer user_data);
int button_clickedr(GtkWidget *widget, gpointer user_data);
void on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);
typedef struct ws
{
    int t[12][12];
    GtkWidget *pola[12][12];
    int gracz;
    int ekwipunek[4];
    GtkWidget *ek[4];
    int wiodcznosc[12][12];
    GtkWidget *window;
    int tura;
    GtkWidget *grid;
    GtkWidget *gridek;
    GtkWidget *tu;
    GtkWidget *gridt;
    char slowo[10000];
} Wska;
char buf[10000];

void wypisz(Wska *plansza);
void wypiszslowo(Wska *plansza);
char przepiszslowo(Wska *plansza);
typedef struct pipes *PipesPtr;

PipesPtr initPipes(int argc, char *argv[]);
void     sendStringToPipe(PipesPtr channel, const char *data);
bool     getStringFromPipe(PipesPtr channel, char *buffer, size_t size);
void     closePipes(PipesPtr channel);

static PipesPtr potoki;
gboolean pobierz_tekst(gpointer data);
void zakoncz(GtkWidget *widget, gpointer data);
