
def kompresja(tekst):
    ile = 0
    co = tekst[0]
    wyn = []
    for c in tekst[1:]:
        if c == co:
            ile = ile + 1
        else:
            wyn.append((ile + 1,co))
            co = c
            ile = 0
    wyn.append((ile + 1,co))
    return wyn

def dekompresja(tekst_skompresowany):
    wyn = ''
    for f in tekst_skompresowany:
        wyn = wyn + f[1]*f[0]
    return wyn

f = open("tadeusz.txt", "r")
text = f.read()
print(dekompresja(kompresja(text)))

# https://wolnelektury.pl/media/book/txt/pan-tadeusz.txt