ALTER TABLE SalesLT.Customer 
ADD CreditCardNumber varchar(10);

UPDATE SalesLT.SalesOrderHeader
SET CreditCardApprovalCode = 1234
WHERE SalesOrderID = 71774;
UPDATE SalesLT.SalesOrderHeader
SET CreditCardApprovalCode = 2345
WHERE SalesOrderID = 71776;
UPDATE SalesLT.SalesOrderHeader
SET CreditCardApprovalCode = 3456
WHERE SalesOrderID = 71780;

UPDATE SalesLT.Customer
SET CreditCardNumber='X'
FROM SalesLT.Customer
INNER JOIN SalesLT.SalesOrderHeader
ON SalesLT.Customer.CustomerID = SalesLT.SalesOrderHeader.CustomerID
WHERE SalesLT.SalesOrderHeader.CreditCardApprovalCode IS NOT NULL