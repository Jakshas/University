import timeit

def pierwsze_imperatywna(n):
    l = []
    for r in range(2,n):
        if(is_prime(r)):
            l.append(r)
    return l

def pierwsze_skladana(n):
    return [r for r in range(2,n) if is_prime(r)]

def pierwsze_funkcyjna(n):
    l = [r for r in range(2,n)]
    return list(filter(is_prime,l))

def is_prime(num):
    flag = True
    if num > 1:
        for i in range(2, num):
            if (num % i) == 0:
                flag = False
                break
    return flag

# print(pierwsze_imperatywna(1000))
# print(pierwsze_skladana(1000))
# print(pierwsze_funkcyjna(1000))

print(timeit.timeit("pierwsze_imperatywna(10)", setup="from __main__ import pierwsze_imperatywna")) # 1.8855398999999124
print(timeit.timeit("pierwsze_skladana(10)", setup="from __main__ import pierwsze_skladana")) # 1.879261900000074
print(timeit.timeit("pierwsze_funkcyjna(10)", setup="from __main__ import pierwsze_funkcyjna")) # 2.107227899999998
