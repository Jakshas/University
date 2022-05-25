DROP TABLE IF EXISTS Bufor
CREATE TABLE Bufor (ID int,AdresUrl varchar(50),OstatnieWejscie Date)

DROP TABLE IF EXISTS Historia
CREATE TABLE Historia (ID int,AdresUrl varchar(50),OstatnieWejscie Date)

DROP TABLE IF EXISTS Parametry
CREATE TABLE Parametry (nazwa varchar(50), wartosc varchar(50))

DROP TRIGGER IF exists z3
GO

CREATE TRIGGER z3 ON Bufor AFTER INSERT
AS
BEGIN
  DECLARE @adres varchar(50)
  DECLARE @data DATETIME
  DECLARE @ID INT
  SELECT TOP 1 @adres = AdresUrl, @ID=ID, @data=OstatnieWejscie FROM Bufor ORDER BY OstatnieWejscie DESC

  DECLARE @wystapienia int
  SET @wystapienia = (SELECT COUNT(*) FROM Bufor WHERE AdresUrl = @adres)
  
  IF @wystapienia = 2
	BEGIN
		DELETE FROM Bufor WHERE ID = @ID
		UPDATE Bufor SET OstatnieWejscie = @data WHERE ID=@ID
	END

  ELSE
	BEGIN
		DECLARE @cache_size INT
		SET @cache_size = (SELECT wartosc FROM Parametry WHERE nazwa = 'max_cache')
		
		DECLARE @wszystkie_wystapienia int
		SET @wszystkie_wystapienia = (SELECT COUNT(*) FROM Bufor)

		IF @wszystkie_wystapienia > @cache_size
			BEGIN
				SELECT TOP 1 @adres = AdresUrl, @ID=ID, @data=OstatnieWejscie FROM Bufor ORDER BY OstatnieWejscie
				SET @wystapienia = (SELECT COUNT(*) FROM Historia WHERE AdresUrl = @adres)

				IF @wystapienia = 1
					BEGIN
						UPDATE Historia SET OstatnieWejscie = @data WHERE @adres = AdresUrl
					END
				ELSE
					BEGIN
						INSERT INTO Historia VALUES (@ID, @adres, @data)
					END
				DELETE FROM Bufor WHERE ID = @ID
			END
	END
END
GO

DELETE FROM Bufor
DELETE FROM Historia
GO

INSERT INTO Bufor VALUES (1, 'www.google.com', GETDATE())
INSERT INTO Bufor VALUES (2, 'www.facebook.com', DATEADD(MINUTE,1,GETDATE()))
INSERT INTO Bufor VALUES (3, 'www.skos.com', DATEADD(MINUTE,2,GETDATE()))
INSERT INTO Bufor VALUES (4, 'www.usos.pl', DATEADD(MINUTE,3,GETDATE()))
INSERT INTO Bufor VALUES (5, 'www.facebook.com', DATEADD(MINUTE,4,GETDATE()))
INSERT INTO Bufor VALUES (6, 'www.google.com', DATEADD(MINUTE,5,GETDATE()))
INSERT INTO Bufor VALUES (7, 'www.youtube.com', DATEADD(MINUTE,6,GETDATE()))
INSERT INTO Bufor VALUES (8, 'www.usos.pl', DATEADD(MINUTE,7,GETDATE()))
INSERT INTO Bufor VALUES (9, 'www.skos.com', DATEADD(MINUTE,8,GETDATE()))
GO