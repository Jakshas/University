import time

def sudan(n, x, y):
    if n == 0:
        return x + y
    if y == 0:
        return x
    return sudan(n-1, sudan(n, x, y-1), sudan(n, x, y-1) + y + 1)



def sudans(n, x, y):
    memory = {}
    return sudanspom(n, x, y, memory)
    
def sudanspom(n, x, y, tablica):
    if (n,x,y) in tablica :
        return tablica[(n,x,y)]
    if n == 0:
        tablica[(n,x,y)] = x + y
        return x + y
    if y == 0:
        tablica[(n,x,y)] = x
        return x
    tablica[(n,x,y)] = sudanspom(n-1, sudanspom(n, x, y-1, tablica), sudanspom(n, x, y-1, tablica) + y + 1, tablica)
    return tablica[(n,x,y)]

start = time.time()
print(sudans(2,2,3))
end = time.time()
print(end - start)

start = time.time()
print(sudan(2,2,3))
end = time.time()
print(end - start)

# gdy n jest równe 2 róznice widac przy x > 6 a przy y > 1 widac ogromna róznice 7.033348083496094e-05 do 121.06526589393616