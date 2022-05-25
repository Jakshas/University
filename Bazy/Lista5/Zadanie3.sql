SET STATISTICS TIME ON

SELECT DISTINCT c.PESEL, c.Nazwisko
FROM Egzemplarz e
JOIN Ksiazka k ON e.Ksiazka_ID=k.Ksiazka_ID
JOIN Wypozyczenie w ON e.Egzemplarz_ID=w.Egzemplarz_ID
JOIN Czytelnik c ON c.Czytelnik_ID = w.Czytelnik_ID
GO

SET STATISTICS TIME ON
SELECT c.PESEL, c.Nazwisko
FROM Czytelnik c WHERE c.Czytelnik_ID IN
    (SELECT w.Czytelnik_ID FROM Wypozyczenie w
    JOIN Egzemplarz e ON e.Egzemplarz_ID=w.Egzemplarz_ID
    JOIN Ksiazka k ON e.Ksiazka_ID=k.Ksiazka_ID)
GO

SET STATISTICS TIME ON
SELECT c.PESEL, c.Nazwisko
FROM Czytelnik c WHERE c.Czytelnik_ID IN
    (SELECT w.Czytelnik_ID FROM Wypozyczenie w
    WHERE w.Egzemplarz_ID IN
        (SELECT e.Egzemplarz_ID FROM Egzemplarz e
        JOIN Ksiazka k ON e.Ksiazka_ID=k.Ksiazka_ID))
SET STATISTICS TIME OFF

DELETE FROM Egzemplarz
DELETE FROM Wypozyczenie
DELETE FROM Czytelnik
DELETE FROM Ksiazka

declare @i int
set @i = 0
while (@i < 5000) begin
    insert into Czytelnik (PESEL, Nazwisko, Czytelnik_ID) values (@i, @i, @i)
    insert into Ksiazka (Ksiazka_ID, ISBN) values (@i, @i)
    insert into Egzemplarz (Sygnatura, Ksiazka_ID, Egzemplarz_ID) values (convert(char(8), @i), @i, @i)
    insert into Wypozyczenie (Czytelnik_ID, Egzemplarz_ID) values (@i, @i)
    set @i=@i+1
end

select * from Egzemplarz