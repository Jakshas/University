CREATE TABLE Test (
    ID int NOT NULL IDENTITY(1000, 10),
    Name varchar(50), 
    PRIMARY KEY (ID)
);

INSERT INTO dbo.Test (Name) VALUES('abc')

SELECT @@IDENTITY

SELECT IDENT_CURRENT ('dbo.Test')