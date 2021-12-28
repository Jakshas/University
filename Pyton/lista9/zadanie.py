import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Table, Column, Integer,ForeignKey, String, DateTime
from sqlalchemy import create_engine
from sqlalchemy.orm import relationship, sessionmaker
import sys
from sqlalchemy.sql.expression import table

Base = declarative_base()
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

def AddKs():
    tytul = builder.get_object("Tytul")
    autor = builder.get_object("Autor")
    rok = builder.get_object("Rok")
    k = Ksiazka(tytul=tytul.get_text(),autor=autor.get_text(),rok=int(rok.get_text()))
    sesja.add(k)
    sesja.commit()
    Wypisz()

def AddOs():
    imie = builder.get_object("Imie")
    nazwisko = builder.get_object("Nazwisko")
    email = builder.get_object("Email")
    k = Osoba(imie=imie.get_text(),nazwisko=nazwisko.get_text(),email=email.get_text())
    sesja.add(k)
    sesja.commit()
    Wypisz()

def AddWyp():
    imie = builder.get_object("Imie")
    nazwisko = builder.get_object("Nazwisko")
    email = builder.get_object("Email")
    tytul = builder.get_object("Tytul")
    autor = builder.get_object("Autor")
    rok = builder.get_object("Rok")
    listao = sesja.query(Osoba).filter(Osoba.imie == imie.get_text(),Osoba.nazwisko == nazwisko.get_text(),Osoba.email == email.get_text()).all()
    listak = sesja.query(Ksiazka).filter(Ksiazka.tytul == tytul.get_text(),Ksiazka.autor == autor.get_text(),Ksiazka.rok == int(rok.get_text())).all()
    listak[0].wyporzycza = listao[0].id
    sesja.commit()
    Wypisz()

def AddZw():
    imie = builder.get_object("Imie")
    nazwisko = builder.get_object("Nazwisko")
    email = builder.get_object("Email")
    tytul = builder.get_object("Tytul")
    autor = builder.get_object("Autor")
    rok = builder.get_object("Rok")
    listao = sesja.query(Osoba).filter(Osoba.imie == imie.get_text(),Osoba.nazwisko == nazwisko.get_text(),Osoba.email == email.get_text()).all()
    listak = sesja.query(Ksiazka).filter(Ksiazka.tytul == tytul.get_text(),Ksiazka.autor == autor.get_text(),Ksiazka.rok == int(rok.get_text())).all()
    if listak[0].wyporzycza == listao[0].id:
        listak[0].wyporzycza = None
    sesja.commit()
    Wypisz()

def Wypisz():
    lista.clear()
    l = sesja.query(Ksiazka)
    for l1 in l:
        if l1.wyporzycza == None:
            wyp = ""
        else:
            listao = sesja.query(Osoba).filter(Osoba.id == l1.wyporzycza).all()
            wyp = listao[0].imie
        lista.append([l1.tytul, wyp])
    window.show_all()

def on_tree_selection_changed(selection):
    model, treeiter = selection.get_selected()
    buf = builder.get_object("textbuffer1")
    listak = sesja.query(Ksiazka).filter(Ksiazka.tytul == model[treeiter][0]).all()
    listao = sesja.query(Osoba).filter(Osoba.id == listak[0].wyporzycza).all()
    buf.set_text("tytul: "+listak[0].tytul+"\nautor: "+listak[0].autor+"\nrok: "+str(listak[0].rok)+"\nwyporzycza: "+str(listao[0].imie))

engine = create_engine('sqlite:///wyklad.db', echo=True)
Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
sesja = Session()
builder = Gtk.Builder()
builder.add_from_file("zadanie.glade")
window = builder.get_object("Okno")
window.connect('destroy', Gtk.main_quit)
ks = builder.get_object("Ksiazka")
ks.connect("clicked",lambda x:  AddKs())
os = builder.get_object("Osoba")
os.connect("clicked",lambda x:  AddOs())
wyp = builder.get_object("Wyporzycz")
wyp.connect("clicked", lambda x: AddWyp())
zw = builder.get_object("Zwroc")
zw.connect("clicked", lambda x: AddZw())
cos = builder.get_object("Lista")
lista = builder.get_object("liststore1")
l = sesja.query(Ksiazka)
for l1 in l:
    if l1.wyporzycza == None:
        wyp = ""
    else:
        listao = sesja.query(Osoba).filter(Osoba.id == l1.wyporzycza).all()
        wyp = listao[0].imie
    lista.append([l1.tytul, wyp])
renderer = Gtk.CellRendererText()
column = Gtk.TreeViewColumn(cell_renderer=renderer, text=0)
cos.append_column(column)
column = Gtk.TreeViewColumn(cell_renderer=renderer, text=1)
cos.append_column(column)
select = cos.get_selection()
select.connect("changed", on_tree_selection_changed)
window.show_all()
Gtk.main()