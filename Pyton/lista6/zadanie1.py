import bs4, re ,urllib.request

pamiec = set()

def crawl(start_page, distance, action):
    if distance > 0:
        if start_page not in pamiec:
            pamiec.add(start_page)
            with urllib.request.urlopen(start_page) as fh:
                dane = bs4.BeautifulSoup(fh.read(), 'html.parser')
                print(action(dane))
                a =[ link.get('href') for link in dane.find_all('a')]
                for i in a:
                    if i is not None and (re.search("https:",i) is not None or re.search("http:",i) is not None):
                        crawl(i, distance-1, action)



class Zad1iter:
    def __init__(self, start_page, distance, action):
        self.pamiec = set()
        self.stack = []
        self.start_page = start_page
        self.distance = distance
        self.action = action
    def __iter__(self):
        self.stack.append((self.start_page,self.distance))
        return self
    def __next__(self):
        item = self.stack.pop(0)
        self.distance = item[1]
        self.start_page = item[0]
        if self.distance > 0:
            while self.start_page in pamiec:
                item = self.stack.pop(0)
                self.distance = item[1]
                self.start_page = item[0]
            if self.start_page not in pamiec:
                pamiec.add(self.start_page)
                with urllib.request.urlopen(self.start_page) as fh:
                    dane = bs4.BeautifulSoup(fh.read(), 'html.parser')
                    a =[ link.get('href') for link in dane.find_all('a')]
                    for i in a:
                        if i is not None and (re.search("https:",i) is not None or re.search("http:",i) is not None):
                            self.stack.append((i, self.distance-1))
                    return (self.start_page ,self.action(dane))    
        else:
            raise StopIteration

def action(data):
    d = data.find_all('p')
    w = []
    for t in d:
        w.append(t.text)
    wyn = []
    for w1 in w:
        wyn = wyn + [sentence + '.' for sentence in w1.split('.') if 'Python' in sentence]
    return wyn

myclass = Zad1iter("https://www.w3schools.com/python/python_iterators.asp",2,action)
for x in myclass:
    print(x)

# crawl("https://www.w3schools.com/python/python_iterators.asp",2,action)