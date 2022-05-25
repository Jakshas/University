-- zgrupowane - wed³ug niego s¹ przechowywane dane (clustered table)
-- niezgrupowane - powstaje pomocnicza struktura ze wskaŸnikami (row locator)

-- w tabelach jest primary key wiec zgrupowane

select count(distinct e.Sygnatura) from Egzemplarz e
join Ksiazka k on k.Ksiazka_ID = e.Ksiazka_ID
where k.Cena > 50

alter table Egzemplarz drop constraint Egzemplarz_FK;
alter table Ksiazka drop constraint ksiazka_pk;
alter table Wypozyczenie drop constraint Wypozyczenie_FK_Egzemplarz;
alter table Egzemplarz drop constraint egzemplarz_pk;

alter table Ksiazka add constraint Ksiazka_PK primary key NONCLUSTERED (ksiazka_id);
alter table Egzemplarz add constraint Egzemplarz_FK foreign key (Ksiazka_ID) references Ksiazka (Ksiazka_ID);
alter table Egzemplarz add constraint Egzemplarz_PK primary key NONCLUSTERED (egzemplarz_id);
alter table Wypozyczenie add constraint Wypozyczenie_FK_Egzemplarz foreign key (Egzemplarz_ID) references Egzemplarz (Egzemplarz_ID);

drop index if exists Ksiazka.I_NC_Cena;
CREATE NONCLUSTERED INDEX I_NC_Cena on Ksiazka (Ksiazka_ID, Cena);
