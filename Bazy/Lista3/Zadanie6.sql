DROP PROCEDURE IF EXISTS z6;
GO

DROP TYPE IF EXISTS List;
GO

CREATE TYPE List AS TABLE
( Identifier INT);
GO

CREATE PROCEDURE z6 @List List READONLY, @DesiredDate DATE
AS
BEGIN
    DECLARE @ifnull INT
    SET @ifnull = (SELECT COUNT(DiscontinuedDate)
                    FROM SalesLT.Product
                    INNER JOIN @List ON SalesLT.Product.ProductID = Identifier
                    WHERE DiscontinuedDate IS NOT NULL)
    IF (@ifnull > 0)
        PRINT 'Date not null'
    ELSE
        BEGIN
            UPDATE SalesLT.Product
            SET DiscontinuedDate = @DesiredDate
            FROM SalesLT.Product
            INNER JOIN @List ON SalesLT.Product.ProductID = Identifier
        END
END
GO

DECLARE @d DATETIME
SET @d = GETDATE()

DECLARE @list List
INSERT INTO @list VALUES(680)
EXEC z6 @list, @d
GO