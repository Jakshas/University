DROP TABLE IF EXISTS Employees
CREATE TABLE Employees (ID int, SalaryGros int)
DROP TABLE IF EXISTS SalaryHistory
CREATE TABLE SalaryHistory (ID int,EmployeeID int,Year int,Month int,SalaryNet int,  SalaryGros int)
INSERT INTO Employees VALUES(1,2000)
INSERT INTO Employees VALUES(2,2000)
INSERT INTO SalaryHistory VALUES(1,1,2021 ,4,2000,2000)
INSERT INTO SalaryHistory VALUES(2,1,2021 ,5,2000,2000)
INSERT INTO SalaryHistory VALUES(3,1,2021 ,6,2000,2000)
INSERT INTO SalaryHistory VALUES(4,1,2021 ,7,2000,2000)
INSERT INTO SalaryHistory VALUES(5,1,2021 ,8,2000,2000)
INSERT INTO SalaryHistory VALUES(6,1,2021 ,9,2000,2000)
INSERT INTO SalaryHistory VALUES(7,1,2021 ,10,2000,2000)
INSERT INTO SalaryHistory VALUES(8,1,2021 ,11,2000,2000)
INSERT INTO SalaryHistory VALUES(9,1,2021 ,12,2000,2000)
INSERT INTO SalaryHistory VALUES(10,1,2022 ,1,2000,2000)
INSERT INTO SalaryHistory VALUES(11,1,2022 ,2,2000,2000)
INSERT INTO SalaryHistory VALUES(12,1,2022 ,3,2000,2000)
INSERT INTO SalaryHistory VALUES(13,2,2022 ,3,2000,2000)

DROP PROCEDURE IF exists z2
GO

DROP TABLE IF EXISTS LOGG
GO

CREATE TABLE LOGG (ID int, wiadomnosc varchar(50))
GO

CREATE PROCEDURE z2 @nr_miesiaca int
AS
BEGIN
	DECLARE @tab AS TABLE (ID int,Salary int)
	DECLARE C1 CURSOR FOR SELECT ID , SalaryGros FROM Employees
	
	OPEN C1
	DECLARE @ID int, @Salary int
	fetch next from C1 into @ID, @Salary
	WHILE ( @@fetch_status=0 )
	BEGIN
		DECLARE @sum int = 0 , @gross int, @ile_mc int = 0
		DECLARE C2 CURSOR FOR SELECT SalaryGros FROM SalaryHistory WHERE EmployeeID = @ID AND ((SalaryHistory.Year = 2021 AND Month > @nr_miesiaca) OR SalaryHistory.Year = 2022)
		OPEN C2
		fetch next from C2 into @gross
		WHILE ( @@fetch_status=0 )
		BEGIN
			SET @ile_mc = @ile_mc + 1
			SET @sum = @sum + @gross
			fetch next from C2 into @gross
		END
		IF @ile_mc < 12
		BEGIN
			INSERT INTO LOGG VALUES(@ID, 'Za malo miesiecy')
		END
		ELSE
		BEGIN
			IF @sum < 120000
			BEGIN
				SET @sum = @Salary - ((@sum * 0.17)/12)
			END
			ELSE
			BEGIN
				SET @sum = @Salary - ((15300 + ((@sum- 120000) * 0.32))/12) 
			END
			INSERT INTO @tab VALUES(@ID, @sum)
		END
		fetch next from C1 into @ID, @Salary
		close C2
		deallocate C2
	END
	SELECT * FROM @tab
	SELECT * FROM LOGG
	close C1
	deallocate C1
END
GO

exec z2 @nr_miesiaca=3
go