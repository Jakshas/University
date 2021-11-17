class Wyrazenie:
    def __add__(self,arg):
        return Dodaj(self,arg)
    def __mul__(self,arg):
        return Razy(self,arg)
    def __div__(self,arg):
        return Dziel(self,arg)
    def __sub__(self,arg):
        return Odejmij(self,arg)

class Stala(Wyrazenie):
    def __init__(self, num):
        self.num = num
    def Oblicz(self,zmienne):
        return self.num
    def __str__(self) -> str:
        return str(self.num)

class Zmienna(Wyrazenie):
    def __init__(self, nazwa):
        self.nazwa = nazwa
    def Oblicz(self,zmienne):
        for v in zmienne:
            if v[0] == self.nazwa:
                return v[1]
        raise BrakZainicjalizowanejZmiennej()
    def __str__(self) -> str:
        return self.nazwa

class Dodaj(Wyrazenie):
    def __init__(self,left,right):
        self.left = left
        self.right = right
    def Oblicz(self,zmienne):
        return self.left.Oblicz(zmienne) + self.right.Oblicz(zmienne)
    def __str__(self) -> str:
        return "("+self.left.__str__() + "+" + self.right.__str__()+")"

class Odejmij(Wyrazenie):
    def __init__(self,left,right):
        self.left = left
        self.right = right
    def Oblicz(self,zmienne):
        return self.left.Oblicz(zmienne) - self.right.Oblicz(zmienne)
    def __str__(self) -> str:
        return "("+self.left.__str__() + "-" + self.right.__str__()+")"

class Dziel(Wyrazenie):
    def __init__(self,left,right):
        self.left = left
        self.right = right
    def Oblicz(self,zmienne):
        if self.right.Oblicz(zmienne) == 0:
            raise DzieleniePrzezZero()
        return self.left.Oblicz(zmienne) / self.right.Oblicz(zmienne)
    def __str__(self) -> str:
        return self.left.__str__() + "/" + self.right.__str__()

class Razy(Wyrazenie):
    def __init__(self,left,right):
        self.left = left
        self.right = right
    def Oblicz(self,zmienne):
        return self.left.Oblicz(zmienne) * self.right.Oblicz(zmienne)
    def __str__(self) -> str:
        return self.left.__str__() + "*" + self.right.__str__()

class CzyRowne(Wyrazenie):
    def __init__(self,left,right):
        self.left = left
        self.right = right
    def Oblicz(self,zmienne):
        return self.left.Oblicz(zmienne) == self.right.Oblicz(zmienne)
    def __str__(self) -> str:
        return self.left.__str__() + "==" + self.right.__str__()

class BrakZainicjalizowanejZmiennej(Exception):
    pass
class DzieleniePrzezZero(Exception):
    pass

class IF:
    def __init__(self,cond, tru, fal):
        self.cond = cond
        self.tru = tru
        self.fal  = fal
    def Wykonaj(self,zmienne):
        if self.cond.Oblicz(zmienne):
            self.tru.Wykonaj(zmienne)
        else:
            self.fal.Wykonaj(zmienne)

class Blok:
    def __init__(self, *operacje):
        self.operacje = list(operacje)
    def Wykonaj(self,zmienne):
        for o in self.operacje:
            o.Wykonaj(zmienne)

class While:
    def __init__(self, cond, *operacje):
        self.cond = cond
        self.operacje = operacje
    def Wykonaj(self,zmienne):
        while self.cond.Oblicz(zmienne):
            for o in self.operacje:
                o.Wykonaj(zmienne)

class Przypisz:
    def __init__(self,zmienna,wartosc):
        self.zmienna = zmienna
        self.wartosc = wartosc
    def Wykonaj(self,zmienne):
        czy_w = True
        for v in zmienne:
            if v[0] == self.zmienna:
                czy_w = False
                v[1] = self.wartosc.Oblicz(zmienne)
        if czy_w:
            zmienne.append([self.zmienna,self.wartosc.Oblicz(zmienne)])

zm = [['x',2],['y',3]]
print(Razy(Dodaj(Zmienna("x"), Stala(2)), Zmienna("y")).Oblicz(zm))
print(Razy(Dodaj(Zmienna("x"), Stala(2)), Zmienna("y")))
print((Zmienna("x") + Stala(2)) * Zmienna("y"))
zm = []
Blok(
    Przypisz("x",Stala(3)),
    Przypisz("y",Stala(2)),
    IF(CzyRowne(Zmienna("x"),Zmienna("y")),Przypisz("x",Zmienna("x")+Zmienna("y")),Przypisz("y",Zmienna("x")+Zmienna("y")))
    ).Wykonaj(zm)
print(zm)
