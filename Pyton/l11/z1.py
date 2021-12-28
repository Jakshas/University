def pierwiastek(n):
    """Zwróć pierwiastek z n zaokraglony w góre"""
    suma = 0
    liczba = 0
    while(suma < n):
        liczba = liczba + 1
        suma = suma + (2 * liczba) - 1
    return liczba


if __name__ == "__main__":
    for r in range(10000):
        pierwiastek(r)
