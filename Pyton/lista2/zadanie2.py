def pierwiastek(n):
    suma = 0
    liczba = 0
    while(suma < n):
        liczba = liczba + 1
        suma = suma + (2* liczba ) - 1
    return liczba

print(pierwiastek(4))
print(pierwiastek(16))
print(pierwiastek(225))
print(pierwiastek(10000))