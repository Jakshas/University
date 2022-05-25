select * from tempdb.INFORMATION_SCHEMA.tables

CREATE TABLE #Tablica(klucz int not null primary key, wartosc varchar(20));
select * from tempdb.#Tablica

select * from tempdb.##Tablica