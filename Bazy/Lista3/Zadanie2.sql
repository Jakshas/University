DROP TABLE IF EXISTS imiona
DROP TABLE IF EXISTS nazwiska
DROP TABLE IF EXISTS dane

CREATE TABLE imiona (id INT PRIMARY KEY, imie varchar(50))
CREATE TABLE nazwiska (id INT PRIMARY KEY, nazwisko varchar(50))
CREATE TABLE dane (imie varchar(50), nazwisko varchar(50), PRIMARY KEY(imie,nazwisko))

INSERT INTO imiona VALUES(1,'Jan')
INSERT INTO imiona VALUES(2,'Tomasz')

INSERT INTO nazwiska VALUES(1,'Kowalski')
INSERT INTO nazwiska VALUES(2,'Nowak')

DROP PROCEDURE IF EXISTS zad2
GO

CREATE PROCEDURE zad2 @n int
AS
BEGIN
	DECLARE @lenN int
	DECLARE @lenI int
	SET @lenN = (SELECT COUNT(DISTINCT nazwisko) FROM nazwiska)
	SET @lenI = (SELECT COUNT(DISTINCT imie) FROM imiona)
	IF (@n > (@lenN * @lenI)/2)
	BEGIN
		;THROW 51000, 'Ponad polowa kombinacji',1;
	END

	DECLARE @rN varchar(50)
	DECLARE @rI varchar(50)

	WHILE @n > 0
	BEGIN
		SET @rN = (SELECT TOP 1 nazwisko FROM nazwiska ORDER BY NEWID())
		SET @rI = (SELECT TOP 1 imie FROM imiona ORDER BY NEWID())
		IF NOT EXISTS (SELECT * FROM dane WHERE @rN = nazwisko AND @rI = imie) 
			BEGIN
			INSERT INTO dane VALUES(@rI, @rN)
			SET @n  = @n - 1
			END
	END

END
GO

EXEC zad2 @n = 4
GO

SELECT * FROM dane