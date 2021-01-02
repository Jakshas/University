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

