import itertools

def sprawdzfiguranta(figurant):
    if 4 in figurant[0]:
        return 1
    if 3 in figurant[0] and 2 in figurant[0]:
        return 2
    if 3 in figurant[0]:
        return 5
    if licz2(figurant) == 2:
        return 6
    return 7
    
def sprawdzblotkarza(blotkarz):
    if liczpoker(blotkarz):
        return 0
    if 4 in blotkarz[0]:
        return 1
    if 3 in blotkarz[0] and 2 in blotkarz[0]:
        return 2
    if 5 in blotkarz[1]:
        return 3
    if liczstrit(blotkarz):
        return 4
    if 3 in blotkarz[0]:
        return 5
    if licz2(blotkarz) == 2:
        return 6
    if 2 in blotkarz[0]:
        return 7
    return 8

def licz2(figurant):
    dwujki = 0
    for i in figurant[0]:
        if i == 2:
            dwujki = dwujki + 1
    return dwujki

def liczstrit(blotkarz):
    wynik = 0
    i = 0
    while(blotkarz[0][i] == 0 ):
        i = i + 1
    while(blotkarz[0][i] == 1):
        wynik = wynik + 1
        i = i + 1
    return wynik == 5

def liczpoker(blotkarz):
    wynik = 0
    i = 0
    while(blotkarz[0][i] == 0 ):
        i = i + 1
    while(blotkarz[0][i] == 1):
        wynik = wynik + 1
        i = i + 1
    return wynik == 5 and (5 in blotkarz[1])

def podlicz(reka):
    kolory = []
    for i in range(0,4):
        kolory.append(0)
    figury = []
    for i in range(0,13):
        figury.append(0)
    for (i,j) in reka:
        kolory[j] = kolory[j] + 1
        figury[i-2] = figury[i-2] + 1
    return (figury,kolory)
    
    
def tworztalie(kto):
    dolosowania = []
    if kto == 'Figurant':
        for i in range(0,4):
            for j in range(11,15):
                dolosowania.append((j,i))
    else:
        for i in range(0,4):
            for j in range(2,10):
                dolosowania.append((j,i))
    return dolosowania

def sprawdz(f1, b1):
    policzonef = podlicz(f1)
    policzoneb = podlicz(b1)
    if sprawdzfiguranta(policzonef) <= sprawdzblotkarza(policzoneb):
        return 'Figurant'
    else:
        return 'Blotkarz'

def sprawdzanie():
    wb = 0
    wf = 0
    figurant = tworztalie('Figurant')
    blotkarz = tworztalie('Blotkarz')
    data1 = itertools.combinations(figurant, 5)
    f = set(data1)
    data2 = itertools.combinations(blotkarz, 5)
    b = set(data2)
    tabf = []
    tabb = []
    for rekaf in f:
        policzonef = podlicz(rekaf)
        fs = sprawdzfiguranta(policzonef)
        tabf.append(fs)
    for rekab in b:
        policzoneb = podlicz(rekab)
        bs = sprawdzblotkarza(policzoneb)
        tabb.append(bs)
    for i in range(0,len(tabf)):
        for j in range(0,len(tabb)):
            if(tabf[i] <= tabb[j]):
                wf = wf + 1
            else:
                wb = wb + 1
    return (wf/(wf+wb))

print(sprawdzanie())