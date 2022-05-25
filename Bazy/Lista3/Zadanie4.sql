DROP PROCEDURE IF EXISTS z4;
GO

DROP TYPE IF EXISTS List;
GO

DROP TYPE IF EXISTS readerAndDaySum;
GO


CREATE TYPE List AS TABLE
( Identifier INT);
GO

CREATE TYPE readerAndDaySum AS TABLE (
    czytelnik_id int, 
    suma_dni int
)
GO

CREATE PROCEDURE z4 @List List READONLY
AS
BEGIN
    SELECT Czytelnik_ID, SUM(Liczba_dni)
    FROM Wypozyczenie
    INNER JOIN @List ON Identifier = Czytelnik_ID
    GROUP BY Czytelnik_ID
END
GO


DECLARE @list List
INSERT INTO @list VALUES(1)
INSERT INTO @list VALUES(2)
INSERT INTO @list VALUES(3)

DECLARE @idday readerAndDaySum

INSERT @idday 
EXEC z4 @list

SELECT * FROM @idday
GO