from math import sqrt
import numpy as np

def wczytaj():
    zwrot = []
    zachorowania = []
    linijka = 0
    for linia in open("1.csv", encoding='utf-8'):
        linia = linia.strip('\n')
        linia = linia.replace(' ', '')
        linia.strip("\ufeff")
        linia = linia.split(';')
        if linijka == 0:
            pass
        elif linijka == 1:
            for el in range(0,len(linia),2):
                zachorowania.append(int(linia[el]))
        else:
            pom2 = []
            for element in linia:
                pom2.append(int(element))
            zwrot.append(pom2)
        linijka+=1
    return [zwrot, zachorowania]

def korewsp(x,y):
    def oczekiwana(tab): #czyli średnia, jak stoi w sprawozdaniu
        return sum(tab[i] for i in range(len(tab))) / len(tab)
    def var(a,asr):
        return sqrt(sum(((a[el]-asr)**2) for el in range(len(a))))
    def cov(a,b,asr,bsr):
        return sum((a[i]-asr)*(b[i]-bsr) for i in range(len(x)))
    xsr = oczekiwana(x); ysr = oczekiwana(y)
    return cov(x,y,xsr,ysr) / (var(x,xsr) * var(y,ysr))

def znajdz_przedzial(nr, limit, tablica, ldni): 
    suma, dzien, iterator = 0, 0, 0
    max_dzien = len(tablica)
    zwrot = [] #tablica - tu sa dane od wszystkiego
    while(suma <= limit):
        suma += tablica[iterator][nr]
        iterator += 1
        dzien += 1
    if dzien + ldni >= max_dzien:
        dzien = max_dzien - ldni
    for i in range(dzien, dzien+ldni):    #dodajemy wszystkie dni po osiagnieciu
        zwrot.append(tablica[i][nr]) #procenta liczby zachorowań
    return zwrot

def stworz_tablice(rozmiar):
    tab = []
    for i in range(rozmiar):
        pom = []
        for k in range(rozmiar):
            pom.append(0)
        tab.append(pom)
    return tab

def korelacja(ldni, procent,kraj1,kraj2):
    pom = wczytaj()
    dane = pom[0] ; sumy_zachorowan = pom[1]
    macierz = stworz_tablice(5)
    for i in range(5):
        pierwszy = znajdz_przedzial(i, sumy_zachorowan[i] * procent, dane, ldni)
        for k in range(i, 5):
            drugi = znajdz_przedzial(k, sumy_zachorowan[k] * procent, dane, ldni)
            korel = korewsp(pierwszy, drugi)
            macierz[i][k] = korel ; macierz[k][i] = korel
    return macierz[kraj1][kraj2]

for l in range(0,5,1):
    for j in range(0,5,1):
        for i in range(20,31,2):
            for k in range(3, 6):
                print("Kraj "+str(j)+" z "+"Kraj "+str(l)+" dla liczby dni = " + str(i) + " i % = " + str(k/100) + " to " + str(korelacja(i, k/100,j,l)))