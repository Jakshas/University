import timeit

def doskonale_imperatywna(n):
    l = []
    for r in range(2,n):
        if(is_doskonale(r)):
            l.append(r)
    return l

def doskonale_skladana(n):
    return [r for r in range(2,n) if is_doskonale(r)]

def doskonale_funkcyjna(n):
    l = [r for r in range(2,n)]
    return list(filter(is_doskonale,l))

def is_doskonale(n):
    sum = 0
    for x in range(1, n):
        if n % x == 0:
            sum += x
    return sum == n

# print(doskonale_imperatywna(1000))
# print(doskonale_skladana(1000))
# print(doskonale_funkcyjna(1000))

print(timeit.timeit("doskonale_imperatywna(10)", setup="from __main__ import doskonale_imperatywna")) # 2.5560788000002503
print(timeit.timeit("doskonale_skladana(10)", setup="from __main__ import doskonale_skladana")) # 2.647265099999913
print(timeit.timeit("doskonale_funkcyjna(10)", setup="from __main__ import doskonale_funkcyjna")) # 2.8066313999997874