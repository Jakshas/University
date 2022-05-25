DROP PROCEDURE IF EXISTS zad3
GO

CREATE PROCEDURE zad3 (@nazwisko varchar(30), @PESEL char(11), @dataur date) AS 
BEGIN
DECLARE @x BIT
SET @x = 1
DECLARE @dataJakoString char(8)
SET @dataJakoString = CONVERT(char(8), @dataur, 112)
IF NOT (LEN(@PESEL) = 11)
	BEGIN
	PRINT 'PESEL to 11 cyferek'
	SET @x = 0
	END
IF NOT (SUBSTRING(@nazwisko, 1, 1) = LOWER(SUBSTRING(@nazwisko, 1, 1)))
	BEGIN
	PRINT 'Nazwisko z duzej!'
	SET @x = 0
	END
IF NOT (LEN(@nazwisko) > 1)
	BEGIN
	PRINT 'Nazwisko d³ugoœæ conajmiej 2!'
	SET @x = 0
	END
IF (SUBSTRING(@dataJakoString, 3, 2) != SUBSTRING(@PESEL, 1, 2) OR SUBSTRING(@dataJakoString, 5, 2) != SUBSTRING(@PESEL, 3, 2) OR SUBSTRING(@dataJakoString, 7, 2) != SUBSTRING(@PESEL, 5, 2))
	BEGIN
	PRINT 'Data niezgodna z PESELem!'
	SET @x = 0
	END
IF(@x = 1)
	BEGIN
	INSERT INTO Czytelnik (PESEL, Nazwisko, Data_Urodzenia, Miasto) VALUES(@PESEL, @nazwisko, @dataur, 'Szczecin')
	END
END
GO

EXEC zad3 @nazwisko = 'Kowalski', @PESEL = '81010200141', @dataur = '1981-01-02'
GO