import multiprocessing
import bs4, re ,urllib.request

pamiec = set()

def action(data):
    d = data.find_all('p')
    w = []
    for t in d:
        w.append(t.text)
    wyn = []
    for w1 in w:
        wyn = wyn + [sentence + '.' for sentence in w1.split('.') if 'wbudowane' in sentence]
    a = [ link.get('title') for link in data.find_all('a')]
    for a1 in a:
        if a1 is not None:
            wyn = wyn + [sentence + '.' for sentence in a1.split('.') if 'wbudowane' in sentence]
    return len(wyn)>0

def action2(site):
    if site not in pamiec:
        pamiec.add(site)
        try:
            with urllib.request.urlopen(site) as fd:
                dane2 = bs4.BeautifulSoup(fd.read(), 'html.parser')
                if action(dane2):
                    print(site)
                a = [ link.get('href') for link in dane2.find_all('a')]
                for i in a:
                    if i is not None and (re.search("https:",i) is not None or re.search("http:",i) is not None):
                        ...
                    else:
                        action2("https://github.com" + i)
        except:
            ...
            # print("404") 
            
def crawl(start_page, distance):
    if distance > 0:
        if start_page not in pamiec:
            pamiec.add(start_page)
            try:
                with urllib.request.urlopen(start_page) as fh:
                    dane = bs4.BeautifulSoup(fh.read(), 'html.parser')
                    tab = start_page.split("=")
                    site = tab[0]+"="+"repositories"
                    action2(site)
                    a = [ link.get('href') for link in dane.find_all('a')]
                    for i in a:
                        if i is not None and (re.search("https:",i) is not None or re.search("http:",i) is not None):
                            ...
                        else:
                            # print("https://github.com"+i)
                            # crawl("https://github.com" + i, distance-1)

                            pr = multiprocessing.Process(target=crawl, args=(i, distance-1, action))
                            pr.start()
            except:
                ...
                # print("404") 

crawl("https://github.com/madziejm?tab=followers",3)

