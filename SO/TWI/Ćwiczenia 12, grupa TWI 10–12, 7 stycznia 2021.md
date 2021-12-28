# Ćwiczenia 12, grupa TWI 10–12, 7 stycznia 2021

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                | 11-1  | 11-2  | 11-3 | 11-4  | 11-5 | 11-6  | 11-7  | 11-8  | 11-9 |
|:---------------------- |:-----:|:-----:|:----:|:-----:|:----:|:-----:|:-----:|:-----:|:----:|
| Kamil Banaś            |       |       |      |       |      |       |       |       |      |
| Marcin Dąbrowski       |   X   |       |      |       |  X   |   X   | ==X== |   X   |      |
| Kamil Galik            |   X   | ==X== |  X   |   X   |  X   |   X   |   X   |   X   |      |
| Bartosz Głowacki       |   X   |       |      |       |  X   |   X   |       |   X   |      |
| Jakub Kaczmarek        |       |       |      |       |      |       |       |       |      |
| Karol Machoś           |   X   |       |      |       |      |   X   |   X   |   X   |      |
| Małgorzata Maciejewska |   X   |       |      |       |  X   |       |   X   |       |      |
| Antoni Pokusiński      |   X   |   X   |      |       |  X   |       |   X   |   X   |      |
| Mateusz Reis           |   X   |       |      |       |      |   X   |   X   |   X   |      |
| Adam Turowski          |       |       |      |       |      |       |   X   |   X   |      |
| Aleksander Uniatowicz  |   X   |   X   |  X   | ==X== |  X   |   X   |   X   |   X   |  x?  |
| Jan Wańkowicz          | ==X== |       |      |       |  X   |   X   |   X   |   X   |      |
| Krzysztof Wiśniewski   |   X   |       |      |       |  X   |   X   |   X   | ==X== |      |
| Tomasz Woszczyński     |   X   |   X   |      |   X   |  X   |   X   |       |   X   |      |
| Jakub Zając            |   X   |       |      |       |  X   |       |   X   |   X   |      |
| Paweł Zmarzły          |   X   |   X   |  X   |   X   |  X   | ==X== |   X   |   X   |      |
| Adam Zyzik             |       |       |      |       |      |       |       |       |      |
:::

## Zadanie 11-1

:::danger
Autor: Jan Wańkowicz
:::

**Blok** - partycja, dysk, plik lub urządzenie blokowe sformatowane za pomocą *ext2* są podzielone na małe grupy sektorów zwane właśnie blokami. 

**Grupa bloków** - bloki są grupowane w grupy między innymi w celu zmniejszenia fragmentacji. Informacje o każdej grupie bloków są przechowywane w tablicy deskryptorów przechowywanej w bloku (blokach) bezpośrednio po superbloku.

**Tablica deskryptorów grup bloków** - przechowuje się w niej wszystkie parametry grup bloków, takie jak lokalizacje mapy bitowej i-węzłów i tablicy i-węzłów, mapy bitowej bloku, liczby wolnych bloków i i-węzłów oraz kilka innych przydatnych informacji. Tablica deskryptorów grup bloków zaczyna się w pierwszym bloku następującym po superbloku.

**Superblok** - przechowuje najważniejsze właściwości systemu plików, takie jak całkowita liczba 
i-węzłów i bloków w systemie plików oraz ile z nich jest wolnych, ile i-węzłów i bloków znajduje się w każdej grupie bloków, kiedy system plików został zamontowany, kiedy został zmodyfikowany, jaka jest wersja systemu plików i który system operacyjny go utworzył.

**Wyznacz rozmiar bloku, liczbę i-węzłów i bloków przechowywanych w grupie bloków (ang. block group), liczbę wpisów tablicy deskryptorów grup bloków (ang. block group descriptor table) na podstawie pól superbloku (ang. superblock).**

Rozmiar bloku: $1024$ << *s_log_block_size*
Liczba bloków w grupie bloków: s_blocks_per_group
Liczba i-węzłów w grupie bloków: s_inodes_per_group
Liczba wpisów tablicy deskryptorów grup bloków: $\lceil$s_blocks_count / s\_blocks\_per\_group$\rceil$

**Wymień składowe należące do grupy bloków oraz podaj ich rozmiar
w blokach.**

![](https://i.imgur.com/TSx1p8X.png)


**Które grupy bloków przechowują kopie zapasową superbloku i tablicy deskryptorów grup bloków?**

Przechowywane są one w grupach $0, 1$ oraz w potęgach $3, 5, 7$.

## Zadanie 11-2

:::danger
Autor: Kamil Galik
:::
![](https://i.imgur.com/lrZFDmb.png)

**Blok pośredni** (_indirect block_) - w inode jest używany przy dużych plikach. Blok ten zawiera wskaźniki na inne bloki pośrednie (_treble-indirect block_ oraz _doubly-indirect block_) lub na bloki danych.

**Zapisy synchroniczne** - wymuszamy czekanie na zakończenie operacji wejścia-wyjścia. Szybkość operacji ograniczona przepustowością dysku.

**Spójność systemu plików** - zgodność faktycznego stanu struktur w systemie plików z ich metadanymi.


### Dopisanie n bajtów na koniec pliku

zakładamy że się nie mieści w już zaalokowanych blockach 

- wybierz wolne blocki
- zapal bity bloków (oznacz jako używane)
- zapisz te n bajtów do bloków
- dodaj bloki do inode:
  - jeśli trzeba, stwórz nowe bloki pośrednie
  - jeśli trzeba, zmodyfikuj istniejące bloki pośrednie
  - zmodyfikuj inode (wskaźniki na bloki, size i timestamp)

### Dodanie pliku do katalogu, w którym nie ma miejsca

Zakładamy, że wpisy w katalogu są przechowywane jako lista łączona, nie używa hashowania ani drzewa binarnego.

- wybierz wolny blok X
- zapal bit: blok X używany
- umieść w bloku X 1 wpis listy łączonej (wpis pliku): ustaw inode, name, name_len i type na odpowiednie dane, a następnie rec_len na koniec bloku
- dodajemy blok X do inode katalogu, jak wyżej

## Zadanie 11-3

:::danger
Autor: Paweł Zmarzły
:::

**Atomowość** - w nowym katalogu albo będzie przeniesiony plik, albo nie, nic pomiędzy (brak uszkodzonego stanu).

Może zdarzyć się, że zarówno `old_path` i `new_path` wskazują na ten sam plik. Nie może się zdarzyć, że żaden z nich nie wskazuje.

EXDEV - Invalid cross-device link - wynika z działania rename (manipuluje tylko wpisami w katalogach, nie zmienia nru inode pliku).

Algorytm:

- podnieś i_links_count w inodzie przenoszonego pliku
- w katalogu docelowym:
    - jeśli to nowy wpis a wcześniej istniał wolny wpis: użyj go
    - jeśli to nowy wpis: dodaj do katalogu docelowego wpis przenoszonego pliku i zmodyfikuj poprzedni wpis, aby nie wskazywał na koniec bloku (wymaga to 1 operacji, bo zakładamy, że jest miejsce)
    - jeśli istniejący: podmień nr inode
- zwolnij wpis w poprzednim katalogu
- zmniejsz i_links_count w inodzie przenoszonego pliku

## Zadanie 11-4

:::danger
Autor: Aleksander Uniatowicz
:::


### usuwanie

1. usuń wpis w katalogu
2. zmiejsz link count
3. sprawdz czy link count jest większy od 0
   * tak: koniec
4. zwalniamy inode
5. zwalniamy bloki

awaria by nas nie zabolała gdybyśmy mieli journal

nie ma journala, więc jeżeli nastąpi awaria, to po kroku nr:
1. mamy zajęty inode, który nie zostanie nigdy zwolniony 
2. mamy zajęty inode, może kiedyś zostanie zwolniony
3. tak, jak w 2
4. mamy bloki które nigdy nie zostaną zwolnione

nie boli nas to co się stanie, bo tracimy tylko zasoby, ale z punktu widzenia użytkownika, nie stanie się nic "tragicznego"

### Undelete

1. (konieczny zawsze) bloki pliku nie mogły zostać nadpisane (wtedy jak mamy szczęście przywrócimy go heurystyką)
2. kiedy inode nie został nadpisany
3. ~~jeżeli jest odpowiedni wpis w journalu~~

należy jednak uważać, bo gdy zauważymy za późno, że coś złego się stało, może już nie być szans na odzyskanie

:::danger
kiedy mamy backup, zwykle nie musimy się tym tak mocno przejmować, wniosek: **zawsze miej backup**!!!
:::

### Kiedy plik jest usuwany

Plik zostanie usunięty z dysku, gdy wszystkie deskryptory plików wskazujące na ten plik, zostaną usunięte (jeżeli nie było żadnych to będzie zostanie usunięty od razu), przy czym odnosi się to tylko do inode, dane tego pliku dalej pozostaną (ale ich bloki będą  oznaczone jako wolne, więc mogą zostać nadpisane).



## Zadanie 11-5

:::danger
Autor: Bartosz Głowacki
:::

**Wyjaśnij  co  robi  system  plików ext2 przy  tworzeniu dowiązania twardego(ang.hard link) i symbolicznego(ang.symbolic link).** 

**Dowiązania symboliczne** - (ang. symbolic links) specjalny typ pliku, który w zawartości przechowuje ścieżkę do innego pliku. System nie sprawdza poprawności tej ścieżki → może powstać pętla (definicja z wykładu).

![](https://i.imgur.com/J3VXO1s.png)

Przy dowiązaniu twardym we wpisie katalogu mamy skojarzenie nazwy z odpowienim i-węzłem. W pliku do jakiego mamy dowiązanie twarde zwiększany jest reference counter, plik może zostać usunięty dopiero kiedy reference counter osiągnie 0.

**Gdzie jest przechowywana zawartość dowiązania symbolicznego?**

W przypadku dowiązania symbolicznego tworzony jest specjalny plik innego typu. W środku tego pliku znajduje się ścieżka do pliku do jakiego chcemy mieć dowiązanie. System automatycznie kiedy próbujemy wejść w dane dowiązanie zaczyna przeglądać system plikóww poszukiwaniu odpowiedniego pliku. Reference counter pliku do jakiego wskazuje dowiązanie nie jest zwiększany, w ogóle nie jest sprawdzane czy dane ścieżka/plik istnieją.


**Jak za pomocą dowiązania symbolicznego stworzyć w systemie plików pętlę?** 

aby stworzyć normalne dowiązanie symboliczne należy użyć ln(1) z flagą -s, w celu zrobienia pętli wystarczy w jakimś katalogu stworzyć dowiązanie symboliczne do katalogu wcześniejszego na ścieżce. `ln -s <directory> <target>`.


**Kiedy jądro systemu operacyjnego ją wykryje i zwróci błąd «ELOOP»?**

W celu ochrony jądra przed przepełnienie stosu, a także w celu ochrony przed atakiem typu „odmowa usługi” to ograniczenia maksymalnej głębokości rekurencji i maksymalnej liczby następnych dowiązań symbolicznych. Zwracany jest błąd ELOOP, gdy przekroczono maksimum („Zbyt wiele poziomów dowiązań symbolicznych”).

**Czemu pętli nie da się zrobić z użyciem dowiązania twardego?**

Linki symboliczne są traktowane inaczej to są pewnego rodzaju specjalne pliki które działają na innych zasadach dlatego można bez problemu traktować je inaczej i pozwolić im na robienie pętli. W przypadku linków twardych pętla byłaby nie do odróżnienia od normalnego wejścia do katalogu, tzn wchodząc do jakiegoś katagu nie dało by się w żaden sposób dowiedzieć czy chodzi się po pętli czy nie. Tworzenie hard linków do katalogów w ogóle jest zabronione bo powodowałoby to wiele problemów. Przykładowo gdzie miałoby przenosić cd $..$ w przypadku katalogu do którego hard link mają 2 inne katalogi.

## Zadanie 11-6

:::danger
Autor: Paweł Zmarzły
:::

**Fragmentacja systemu plików** - dane plików są na dysku ułożone w nieciągły sposób. Na dyskach talerzowych zmiana pozycji głowicy była bardzo kosztowna. Na dyskach półprzewodnikowych, dane wczytywane są blokami, więc również może nastąpić więcej odczytów.

**Odroczony przydział bloków** - zamiast alokować i zapisywać bloki osobno, żądania są buforowane, a następnie łączone i zapisywane jako jedno w momencie page flush. Technika ta pozwala na zmniejszenie możliwej fragmentacji, przyspieszenie zapisów oraz pozwala uniknąć niepotrzebnej alokacji bloków dla tymczasowych plików.

**Extents:**

- łącznie 12 bajtów (96 bitów)
  - 48 bitów: adres na dysku
  - 1 bit: wolny/użyty
  - 15 bitów: długość (więc max rozmiar to 2^15 \* 4KiB = 128MiB)
  - 16 bitów: adres w pliku (logical address) - pozwala na szybkie wyszukiwanie
- w inode jest nagłówek ext4_extent_header, przechowujący np. wersję
- w inode po nagłówku są max 4 adresy
- na podstawie eh_depth wiemy, czy to są adresy bloków czy indexów (węzłów drzewa)

**Czy ilość wolnych bloków może wzrosnąć po defragmentacji?**

Tak, bo użyta zostanie mniejsza liczba zakresów (extents), więc bloki używane jako wierzchołki drzewa mogą okazać się niepotrzebne.

**Najprostszy algorytm defragmentacji:**

1. Utwórz tymczasowy inode
2. Zaalokuj ciągły zakres w tymczasowym inode
3. Skopiuj dane z oryginalnego inode do tymczasowego (korzystamy z odroczonego przydziału)
4. Przestaw wskaźniki na bloki z oryginalnego inode'a do nowego

## Zadanie 11-7

:::danger
Autor: Marcin Dąbrowski
:::
`> freefrag`
 ![](https://i.imgur.com/MceryGI.png)
`> stats`
![](https://i.imgur.com/s3201ts.png)
`> extents film`
![](https://i.imgur.com/KpxA4rf.png)
`> inode_dump filmik`
![](https://i.imgur.com/pXCLdjX.png)
`> blocks film`
![](https://i.imgur.com/CpusYDV.png)
`> icheck 2584562`
![](https://i.imgur.com/VpzKBoa.png)
`> ncheck 918668`
![](https://i.imgur.com/3L22v7l.png)
`> blocks .`
![](https://i.imgur.com/7szKJBQ.png)
`> bdump 3678290`
![](https://i.imgur.com/9j856Va.png)




## Zadanie 11-8

:::danger
Autor: Krzysztof Wiśniewski
:::
![](https://i.imgur.com/Wi2TWuQ.png)

**rozszerzone atrybuty pliku** - dodatkowe informacje o pliku, przechowywane w postaci par nazwa/wartość.

**To jest krytyka z pierwszego artykułu:**
Każdy plik uniksowy to ciąg bajtów. I tyko zwykły ciąg bajtów. Ta idea jest niezwykle hermetyczna przez co Unix ma problem z obsługą plików, które nie daje się w łatwy sposób dopasować do tylko “zwykłego ciągu bajtów”. Takie pliki posiadają np. rozszerzone atrybuty, pod postacią par nazwa/wartość. Nie są obsługiwane przez operacje na plikach, które są dostępne w systemie Unix(to jest create, open, write, read, delete). Żeby spróbować jakoś temu zaradzić, trzeba byłoby korzystać z zestawu wywołań ioctl. W artyukle tu zacytuje odradzają korzystanie z tego jako, że "ioctl calls, a notoriously ugly collection of back doors into kernel space.". Unix nie posiada łatwego sposobu poradzenia sobie z tym problemem.


Plik w systemach MacOS można podzielić na data fork-i i resource fork-i.

Przy czym data fork-i będą odpowiadać ciągowi bajtów, a resource fork-i
parom nazwa/wartość, które będą w dodatkowy sposób definiowały cały plik.

Resource fork były wykorzystywane w systemach MacOS, aby przechowywać metadane plików, oraz ich zasoby(ikony).

Możemy sobie myśleć o resource fork-ach jako o mikro bazach danych plików, z których wartości będziemy uzyskiwać przy pomocy specjalnych nazw(ang. Resource identifier)

![](https://i.imgur.com/PS3f9a7.png)

Przykładowe nazwy: Code, będzie przechowywał kod maszynowy programu;
APPL, będzie przechowywał informacje o aplikacji;
snd, będzie przechowywał dźwięk używany w pliku.


getfattr -d *, pokazuje atrybuty plików w całym folderze

obliczyć md5 sum no i przypisać do atrybutu usr.md5sum

touch plik.txt
md5sum plik.txt
setfattr -n user.md5sum -v “tu ta suma” plik.txt

getfattr -d plik.txt


Chromium kiedyś zaciągało razem z plikami, pewne atrybuty.
Co mogło być pewnym naruszeniem bezpieczeństwa użytkownika.

https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=883746

## Zadanie 11-9

:::danger
Autor: Aleksander Uniatowicz
:::


![](https://i.imgur.com/vGF6FiO.png)



htree dużego katalogu
debugfs: htree_dump /var/lib/dpkg/info 