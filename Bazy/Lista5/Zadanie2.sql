DROP TABLE IF EXISTS Wizyty
GO
DROP TABLE IF EXISTS Wizyty1NF
GO
DROP TABLE IF EXISTS Wizyty2NF
GO
DROP TABLE IF EXISTS Wizyty3NF
GO

CREATE TABLE Wizyty(
	[ID]					INT PRIMARY KEY,
	[Pacjent]				VARCHAR(50),
	[Adres Pacjenta]		VARCHAR(100),
	[Data i miejsce wizyty] VARCHAR(100),
	[Kwota]					MONEY,
	[Lekarz]				VARCHAR(50),
	[Pow�d wizyty]			VARCHAR(100))

INSERT INTO Wizyty VALUES
(1, 'Jan Kot',    'ul. Dolna 6, 44-444 B�r', '2029-02-01 12:30, pok. 12', 300, 'Marek Z�bek', 'Dentystyczny: za�o�enie protezy w (...)'),
(2, 'Maria Mysz', 'ul. G�rna 9, 55-555 Las', '2030-01-04 11:45, pok. 7',  150, 'Ewa Blacka',    'Dermatologiczny: ogl�dziny znamiona (...)')
GO

DROP TABLE IF EXISTS Wizyty1NF
GO

CREATE TABLE Wizyty1NF(
	[ID]					INT PRIMARY KEY,
	[Imie]					VARCHAR(50),
	[Nazwisko]				VARCHAR(50),
	[Adres]					VARCHAR(100),
	[Kod pocztowy]			VARCHAR(10),
	[Miasto]				VARCHAR(100),
	[Data]					DATE,
	[Miejsce wizyty]		INT,
	[Kwota]					MONEY,
	[Imie Lekarza]			VARCHAR(50),
	[Nazwisko Lekarza]		VARCHAR(50),
	[Typ wizyty]			VARCHAR(40),
	[Pow�d wizyty]			VARCHAR(100))

INSERT INTO Wizyty1NF VALUES
(1, 'Jan', 'Kot', 'ul. Dolna 6', '44-444', 'B�r', '2029-02-01 12:30', 12, 300, 'Marek', 'Z�bek', 'Dentystyczny',    'Za�o�enie protezy w (...)'),
(2, 'Maria', ' Mysz', 'ul. G�rna 9', '55-555', 'Las', '2030-01-04 11:45', 7,  150, 'Ewa', 'Blacka',	'Dermatologiczny', 'Ogl�dziny znamiona (...)')
GO

DROP TABLE IF EXISTS Pacjenci
GO

CREATE TABLE Pacjenci(
	[ID]					INT PRIMARY KEY,
	[Imie]					VARCHAR(50),
	[Nazwisko]				VARCHAR(50),
	[Adres]					VARCHAR(50),
	[Kod pocztowy]			VARCHAR(10),
	[Miasto]				VARCHAR(30))

INSERT INTO Pacjenci VALUES
(1, 'Jan','Kot', 'ul. Dolna 6', '44-444', 'B�r'),
(2, 'Maria', 'Mysz', 'ul. G�rna 9', '55-555', 'Las')
GO


DROP TABLE IF EXISTS Wizyty2NF
GO

DROP TABLE IF EXISTS Lekarze
GO

CREATE TABLE Lekarze(
	[ID]					INT PRIMARY KEY,
	[Imie]					VARCHAR(50),
	[Nazwisko]				VARCHAR(50))


CREATE TABLE Wizyty2NF(
	[ID]					INT PRIMARY KEY,
	[ID_Pacjenta]			INT ,
	[Data]					DATE,
	[Miejsce wizyty]		INT,
	[Kwota]					MONEY,
	[ID_Lekarza]			INT ,
	[Typ wizyty]			VARCHAR(20),
	[Pow�d wizyty]			VARCHAR(100))


INSERT INTO Wizyty2NF VALUES
(1,1, '2029-02-01 12:30', 12, 300, 1, 'Dentystyczny',    'Za�o�enie protezy w (...)'),
(2,2, '2030-01-04 11:45', 7,  150, 2,	'Dermatologiczny', 'Ogl�dziny znamiona (...)')
GO

SELECT * FROM Pacjenci JOIN Wizyty2NF ON Pacjenci.ID = Wizyty2NF.[ID_Pacjenta]
GO

DROP TABLE IF EXISTS Wizyty3NF
GO


CREATE TABLE Wizyty3NF(
	[ID_Pacjenta]			INT,
	[Data]					DATE,
	[Kwota]					MONEY,
	[ID_Lekarza]			INT,
	[Pow�d wizyty]			VARCHAR(100))


INSERT INTO Wizyty3NF VALUES
(1, '2029-02-01 12:30', 12, 300, 'Za�o�enie protezy w (...)'),
(2, '2030-01-04 11:45', 7,  150, 'Ogl�dziny znamiona (...)')
GO
