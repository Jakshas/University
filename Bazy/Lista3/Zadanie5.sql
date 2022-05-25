declare @t1 table (ID int)
insert into @t1 values(1)
select * from @t1
select * from tempdb.INFORMATION_SCHEMA.tables

DROP TABLE IF EXISTS #Tablica;
CREATE TABLE #Tablica(klucz int not null primary key, wartosc varchar(20));
select * from tempdb.#Tablica
insert into #Tablica values(1,'a')

DROP TABLE IF EXISTS ##Tablica;
CREATE TABLE ##Tablica(klucz int not null primary key, wartosc varchar(20));
insert into ##Tablica values(1,'a')
select * from tempdb.##Tablica

drop procedure if exists procedura1
go


create procedure procedura1
as 
begin
	CREATE TABLE #Tablica(klucz int not null primary key, wartosc varchar(20));
--	insert into #Tablica values(1,'a')
end
go
exec procedura1

drop procedure if exists procedura2
go
create procedure procedura2 @i int output
as 
begin
	select wartosc from tempdb.#Tablica where klucz = 1
end
go
declare @i int
exec procedura2 @i output
print @i

select * from tempdb.INFORMATION_SCHEMA.tables

-- https://www.mssqltips.com/sqlservertip/1556/differences-between-sql-server-temporary-tables-and-table-variables/