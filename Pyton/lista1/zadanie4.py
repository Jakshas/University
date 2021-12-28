import random

def check_throws(ile):
    liczniklosowan = 0
    licznikseri = 0
    ostatni = 0
    while True:
        r = random.randint(1,2)
        if r == ostatni:
            licznikseri=licznikseri+1
        else:
            licznikseri = 1
            ostatni = r
        liczniklosowan = liczniklosowan + 1
        if ile <= licznikseri:
            return liczniklosowan

def experyment(pruby, ile):
    suma = 0
    for i in range(pruby):
        p = check_throws(ile)
        suma = suma + p
    suma = suma/pruby
    return suma

a = input("podaj liczbe testów: ")
b = input("podaj długośc seri: ")
print("średnia to ",end ="")
print(experyment(int(a),int(b)))
