from decimal import *

def vat_faktura(lista):
    suma = 0
    for l in lista:
        suma = suma + l
    suma = suma * 1.23
    return suma
def vat_paragon(lista):
    suma = 0
    for l in lista:
        suma = suma + (l * 1.23)
    return suma


zakupy = [0.2, 0.5, 4.59, 6]
print(vat_faktura(zakupy) == vat_paragon(zakupy))

def decvat_faktura(lista):
    suma = Decimal(0)
    for l in lista:
        suma = suma + Decimal(l)
    suma = suma * Decimal(1.23)
    return suma
def decvat_paragon(lista):
    suma = Decimal(0)
    for l in lista:
        suma = suma + (Decimal(l) * Decimal(1.23))
    return suma


zakupy = [0.2, 0.5, 4.59, 6]
print(decvat_faktura(zakupy) == decvat_paragon(zakupy))
# Daje róznice