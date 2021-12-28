# Ćwiczenia 1, grupa TWi 10-12, 8 października 2020

###### tags: `so20` `ćwiczenia` `twi`

## Zadanie 1-1

:::danger
Autor: Aleksander Uniatowicz
:::
### Exeption

mechanizm przepływu sterowania używany w procesorach oraz współczesnych językach programowania do obsługi zdarzeń wyjątkowych, a w szczególności błędów, których wystąpienie zmienia prawidłowy przebieg wykonywania programu.

#### Przykłady:
 - Dzielenie przez 0 (abort)
 - Page fault (przykład powrotu do działania po zmapowaniu odpowiedniej strony wirtualnej pamięci ze stroną fizycznej pamięci.)
 - Próba dostania się do niezdefiniowanej części pamięci wirtualnej (segfault)

### Przerwanie

sygnał powodujący zmianę przepływu sterowania, niezależnie od aktualnie wykonywanego programu. Pojawienie się przerwania powoduje wstrzymanie aktualnie wykonywanego programu i wykonanie przez procesor kodu procedury obsługi przerwania (ang. interrupt handler). Procedura ta wykonuje czynności związane z obsługą przerwania i na końcu wydaje instrukcję powrotu z przerwania, która powoduje powrót do programu realizowanego przed przerwaniem.

#### Przykłady:

- obsługa dysku
- obsługa karty sieciowej
- obsługa myszki/klawiatury na złączu ps2 

### Pułapka

Celowe wyjątki, mające na celu wykonywania instrukcji w trybie jądra. Używane gdy program chce zrobić coś, do czego nie ma uprawnień z "user mode".

#### Przykłady:

 - Obsługa plików
 - Tworzenie procesów
 - Uruchomienie programu

**W jakim scenariuszu wyjątek procesora nie oznacza błędu czasu wykonania programu:**

przy faultach lub jak złapiemy exeption

**Kiedy pułapka jest generowana w wyniku prawidłowej pracy programu?:**

Zazwyczaj robimy je celowo: np. requestujemy zapis pliku. 

## Zadanie 1-2

:::danger
Autor: Kamil Galik
:::

**Wektor przerwań** - tablica zawierająca kolejne wpisy *procedur obsługi przerwań*. Każdy taki wpis jest najczęściej instrukcją skoku do pierwszej instrukcji procedury, natomiast może to być też sam adres pierwszej instrukcji (Drugie rozwiązanie jest mniej wydajne).

**procedura obsługi przerwań** - mały blok instrukcji odpowiedzialny za obsługę konkretnego przerwania.

**Tryb użytkowanika (ang. User mode)** - tryb pracy, w którym proces nie ma pełnego dostępu do zasobów komputera. Nie jest w stanie czytać ani pisać w pamięci przydzielonej innym procesom ani zarządzać sprzętem. Brak dostępu do instrukcji uprzywilejowanych.

**Tryb jądra (ang. Kernel mode)** - tryb pracy, w którym proces ma pełen dostęp do komputera. Jest w stanie wykonać wszystkie instrucje dostępne dla user mode oraz te uprzywilejowane. 

**Mechanizm obsługi przerwań:**
- Odczytanie przez procesor numeru przerwania
- Umieszczenie na stosie adresu instrukcji, która ma się wykonać po powrocie
- Umieszczenie na stosie informacji ważnych dla procesora (np. EFLAGS, %esp)
- Znalezienie odpowiedniego wpisu w wektorze przewań
- Wywołanie znalezionej procedury obsługi przerwań
- Po jej zakończeniu zdejmujemy ze stosu zachowane informacje o procesie
- Powrót do wcześniej wstrzymanego procesu, skacząc pod zachowany na stosie adres powrotu

Obsługa przerwań działa w *trybie jądra*, ponieważ wymagany jest dostęp do sprzętu oraz pamięci operacyjnej procesów.

Działa ona na osobnym stosie, ponieważ stos wstrzymanego procesu mógł być uszkodzony w trakcie wywołania przerwania, zatem użycie go mogłoby uszkodzić system operacyjny w trakcie obsługi przerwania. Dla bezpieczeństwa używany jest więc osobny stos.

## Zadanie 1-3

:::danger
Autor: Antoni Pokusiński
:::

Pliki wykonywalne formatu ELF, oprócz kodu wykonywalnego, zawierają również inne dane:
* nagłówek pliku ELF (*ELF header*) - zawiera podstawowe informacje, takie jak m. in. : kolejność bajtów, typ pliku, entry point address (położenie pierwszej instrukcji programu);
* nagłówki sekcji (*section headers*) - opisują poszególne sekcje pliku, za pomocą poniższych danych: 
```
[Nr] Name              Type             Address           Offset
     Size              EntSize          Flags  Link  Info  Align
     
(...) 
   
[ 1] .text             PROGBITS         00000000004000e8  000000e8
     0000000000000056  0000000000000000 AX       0     0     1
```
* nagłówki programu (*program headers*) - opisują, w jaki sposób poszczególne segmenty kodu zostaną zmapowane w pamięci podczas wykonywania programu:
```
Type           Offset             VirtAddr           PhysAddr
               FileSiz            MemSiz             Flags  Align
   
(...)    
   
LOAD           0x00000000000000e8 0x00000000004000e8 0x00000000004000e8
               0x0000000000000056 0x0000000000000056 R E    0x200000
```


---
### Sekcja vs segment
Sekcje to fragmenty kodu zawierające dane/metadane istotne podczas konsolidacji. Natomiast segmenty to również fragmenty kodu, które jednak zawierają informacje potrzebne już przy wykonywaniu programu. W szczególności, na segment może się składać 0 lub kilka sekcji.

## Zadanie 1-4

:::danger
Autor: Jan Wańkowicz
:::

**W jaki sposób jądro musi przygotować przestrzeń adresową procesu? Co musi znajdować się na stosie w momencie wywołania procedury «_start»? Do czego służy auxiliary vector?**

Przed uruchomieniem procesu jądro musi wyczyścić flagi wyjątków zmiennych zmiennoprzecinkowych w obu jednostkach *SSE2* i *x87* oraz odpowiednio przygotować stos, który w chwili wywołania procedury «_start» wygląda następująco:

![](https://i.imgur.com/bzBSg5E.png)

Auxiliary vector służy nam jako forma komunikacji między aplikacjami użytkownika a systemem operacyjnym. Kiedy jakiś program został wykonany, auxiliary vector otrzymuje informacje o środowisku, na którym operuje. 

**W jaki sposób wywołać funkcję jądra?** 
 
 Wywołuje ją się podobnie do normalnych funkcji z poziomu użytkownika. Używa się do tego instrukcji *syscall* ze standardowej biblioteki C.
 
**W których rejestrach należy umieścić argumenty?**

Argumenty przekazujemy w rejestrach *%rdi, %rsi, %rdx, %r10, %r8, %r9*.

**Gdzie można spodziewać się wyników i jak jądro sygnalizuje niepowodzenie wywołania systemowego?**

Wynik przekazywany jest w rejestrze *%rax*. Jeśli zwrócona wartość jest z zakresu $[-4095;-1]$, mamy do czynienia z błędem.

**Przestrzeń adresowa** – mapa możliwej do zaadresowania przez proces pamięci.
    
**Wywołanie systemowe (system call)** – stanowi interfejs między wykonywanym programem a (posiadającym zwykle wyższe uprawnienia) jądrem systemu operacyjnego. 


## Zadanie 1-5

:::danger
Autor: Paweł Zmarzły
:::

Wirtualny adres 64 bitowy składa się z:

- 16 nieużywanych bitów (przestrzeń adresowa jest 48-bitowa),
- 9 bitów wybierających tablicę translacji 1. poziomu,
- 9 bitów wybierających tablicę translacji 2. poziomu,
- 9 bitów wybierających tablicę translacji 3. poziomu,
- 9 bitów wybierających tablicę translacji 4. poziomu,
- 12 bitów offset-u.

VPO (Virtual Page Offset) = PPO (Physical Page Offset).

Tablica 1. poziomu może mieć wiele wpisów o tablicy 2. poziomu, tablica 2. poziomu może mieć wiele wpisów o tablicy 3. poziomu, itd.

TLB (translation lookaside buffer) jest małą pamięcią podręczną pozwalającą na uzyskanie fizycznego adresu w 1 cyklu procesora. Zazwyczaj może mieć maksymalnie 64 wpisy. Istnieją instrukcje procesora usuwające część lub całość zawartości TLB. Czyszczenie TLB powoduje wysoki koszt zmian kontekstu.

Lokalność czasowa przyspiesza wykonanie z powodu TLB.

Lokalność przestrzenna przyspiesza wykonanie z powodu małej ilości tablic translacji używanych w translacji adresów.

## Zadanie 1-6

:::danger
Autor:
:::

## Zadanie 1-7

:::danger
Autor:
:::
