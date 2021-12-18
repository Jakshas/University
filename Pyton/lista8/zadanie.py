from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Table, Column, Integer,ForeignKey, String, DateTime
from sqlalchemy import create_engine
from sqlalchemy.orm import relationship, sessionmaker
import sys
from sqlalchemy.sql.expression import table

Base = declarative_base()

# działa to tak że jesli chce sie dodac albo wypisac to pisze sie najpierw co chce sie dodac/wypisac i potem opcje jakie opisuja to co sie dodaje
# przy wyporzyczeniu i zwruceniu pomija sie co i op opcji --wyporzycz wpisuje sie dane ksiazki i osoby wyporzyczajacej

class Osoba(Base):
    __tablename__ = 'Osoba'
    id = Column(Integer, primary_key=True)
    imie = Column(String(20), nullable=False)
    email = Column(String)
    nazwisko = Column(String(20), nullable=False)
    ksiazki = relationship('Ksiazka')

class Ksiazka(Base):
    __tablename__ = "Ksiazka"
    id = Column(Integer, primary_key=True)
    tytul = Column(String(20), nullable=False)
    autor = Column(String(40), nullable=False)
    rok = Column(Integer)
    wyporzycza = Column(Integer, ForeignKey("Osoba.id"))

if __name__ == '__main__':
    
    engine = create_engine('sqlite:///wyklad.db', echo=True)
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    sesja = Session()
    if len(sys.argv) > 2:
        if sys.argv[2] == "--wypisz":
            if sys.argv[1] == "osoba":
                lista = sesja.query(Osoba)
                for l in lista:
                    print(l.imie + " "+ l.nazwisko + " " + l.email)
            if sys.argv[1] == "ksiazka":
                lista = sesja.query(Ksiazka)
                for l in lista:
                    if l.wyporzycza!= None:
                        listao = sesja.query(Osoba).filter(Osoba.id == l.wyporzycza).all()
                        print(l.tytul + " "+ l.autor + " " + str(l.rok) + " "+ listao[0].imie)
                    else:
                        print(l.tytul + " "+ l.autor + " " + str(l.rok))
        if sys.argv[2] == "--dodaj":
            for i in range(3,len(sys.argv)):
                tab = sys.argv[i].split("=")
                tab[0] = tab[0].replace("-","")
                if tab[0] == "imie":
                    imie = tab[1]
                if tab[0] == "nazwisko":
                    nazwisko = tab[1]
                if tab[0] == "email":
                    email = tab[1]
                if tab[0] == "tytul":
                    tytul = tab[1]
                if tab[0] == "autor":
                    autor = tab[1]
                if tab[0] == "rok":
                    rok = tab[1]
                if tab[0] == "wyporzycza":
                    wyporzycza = tab[1]
            if sys.argv[1] == "osoba":
                o = Osoba(imie=imie,nazwisko=nazwisko,email=email)
                sesja.add(o)
            if sys.argv[1] == "ksiazka":
                k = Ksiazka(tytul=tytul,autor=autor,rok=rok)
                sesja.add(k)
            sesja.commit()
        if sys.argv[1] == "--wyporzycz":
            for i in range(2,len(sys.argv)):
                tab = sys.argv[i].split("=")
                tab[0] = tab[0].replace("-","")
                if tab[0] == "imie":
                    imie = tab[1]
                if tab[0] == "nazwisko":
                    nazwisko = tab[1]
                if tab[0] == "email":
                    email = tab[1]
                if tab[0] == "tytul":
                    tytul = tab[1]
                if tab[0] == "autor":
                    autor = tab[1]
                if tab[0] == "rok":
                    rok = tab[1]
            listao = sesja.query(Osoba).filter(Osoba.imie == imie,Osoba.nazwisko == nazwisko,Osoba.email == email).all()
            listak = sesja.query(Ksiazka).filter(Ksiazka.tytul == tytul,Ksiazka.autor == autor,Ksiazka.rok == rok).all()
            listak[0].wyporzycza = listao[0].id
            sesja.commit()
        if sys.argv[1] == "--zwroc":
            for i in range(2,len(sys.argv)):
                tab = sys.argv[i].split("=")
                tab[0] = tab[0].replace("-","")
                if tab[0] == "imie":
                    imie = tab[1]
                if tab[0] == "nazwisko":
                    nazwisko = tab[1]
                if tab[0] == "email":
                    email = tab[1]
                if tab[0] == "tytul":
                    tytul = tab[1]
                if tab[0] == "autor":
                    autor = tab[1]
                if tab[0] == "rok":
                    rok = tab[1]
            listao = sesja.query(Osoba).filter(Osoba.imie == imie,Osoba.nazwisko == nazwisko,Osoba.email == email).all()
            listak = sesja.query(Ksiazka).filter(Ksiazka.tytul == tytul,Ksiazka.autor == autor,Ksiazka.rok == rok).all()
            if listak[0].wyporzycza == listao[0].id:
                listak[0].wyporzycza = None
            sesja.commit()
