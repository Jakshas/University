def wczytaj():
    tab1 = []
    tab2 = []
    with open('zad2_outputl.txt', encoding='utf8') as f:
        for line in f:
            tab1.append(line)
    with open('real_slim_tadeusz.txt', encoding='utf-8-sig') as f:
        for line in f:
            tab2.append(line)
    wynik = 0
    for i in range(0,len(tab1)):
        if(tab1[i] == tab2[i]):
            wynik = wynik + 1
    return wynik/len(tab1)
print(wczytaj())