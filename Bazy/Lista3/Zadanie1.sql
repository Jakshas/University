drop function if exists return_books
go

create function return_books(@max_dni int) returns table
	return select PESEL, Count(Liczba_Dni) as Egzemplarze 
	from dbo.Wypozyczenie INNER JOIN Czytelnik ON Czytelnik.Czytelnik_ID=Wypozyczenie.Czytelnik_ID 
	where Liczba_Dni > @max_dni 
	group by PESEL 
go

select * from dbo.return_books(5)
go
