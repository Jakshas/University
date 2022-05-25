

CREATE TABLE Kursy(Waluta VARCHAR(50) PRIMARY KEY, CenaPLN MONEY)

CREATE TABLE Towary(ID INT PRIMARY KEY, NazwaTowaru VARCHAR(50))

CREATE TABLE Ceny (TowarID int REFERENCES Towary(ID), Waluta varchar(50) REFERENCES Kursy(Waluta), Cena MONEY)

INSERT INTO Towary VALUES(1, 'jeden')
INSERT INTO Towary VALUES(2, 'dwa')
INSERT INTO Towary VALUES(3, 'trzy')

INSERT INTO Kursy VALUES('PLN', 1.00)
INSERT INTO Kursy VALUES('EUR', 4.56)
INSERT INTO Kursy VALUES('GBP', 5.63)
INSERT INTO Kursy VALUES('USD', 4.27)
INSERT INTO Kursy VALUES('JPY', 343)

DELETE FROM Ceny


INSERT INTO Ceny VALUES (1, 'PLN', 1)
INSERT INTO Ceny VALUES (1, 'USD', 1)
INSERT INTO Ceny VALUES (1, 'GBP', 1)
INSERT INTO Ceny VALUES (1, 'EUR', 1)

INSERT INTO Ceny VALUES (2, 'PLN', 20)
INSERT INTO Ceny VALUES (2, 'EUR', 100)
INSERT INTO Ceny VALUES (2, 'USD', 70)

INSERT INTO Ceny VALUES (3, 'PLN', 23)

INSERT INTO Ceny VALUES (1, 'JPY', 1000)
INSERT INTO Ceny VALUES (3, 'JPY', 200)

--https://edux.pjwstk.edu.pl/mat/118/lec/w13.html

DECLARE cenyCursor CURSOR FOR SELECT TowarID, Waluta, Cena FROM Ceny
DECLARE @cursorTowarID int, @cursorWalutaCeny varchar(50), @cursorCena smallmoney
DECLARE @cenaPLN smallmoney
DECLARE @kursPLN smallmoney
DECLARE @znanyKurs bit

OPEN cenyCursor
FETCH NEXT FROM cenyCursor INTO @cursorTowarID, @cursorWalutaCeny, @cursorCena

SET @cenaPLN = (SELECT Cena FROM Ceny WHERE TowarID = @cursorTowarID AND Waluta = 'PLN')
SET @kursPLN = (SELECT CenaPLN FROM Kursy WHERE Waluta = @cursorWalutaCeny)

WHILE @@FETCH_STATUS = 0
BEGIN 
	PRINT(@cursorWalutaCeny)
	SET @cenaPLN = (SELECT Cena FROM Ceny WHERE TowarID = @cursorTowarID AND Waluta = 'PLN')
	IF NOT EXISTS (SELECT CenaPLN FROM Kursy WHERE Waluta = @cursorWalutaCeny)
		DELETE FROM Ceny WHERE TowarID = @cursorTowarID AND Waluta = @cursorWalutaCeny
	ELSE 
		UPDATE Ceny SET Cena = @cenaPLN / (SELECT CenaPLN FROM Kursy WHERE Waluta = @cursorWalutaCeny)
		WHERE TowarID = @cursorTowarID AND Waluta = @cursorWalutaCeny
	FETCH NEXT FROM cenyCursor INTO @cursorTowarID, @cursorWalutaCeny, @cursorCena
END

CLOSE cenyCursor
DEALLOCATE cenyCursor

SELECT * FROM Ceny