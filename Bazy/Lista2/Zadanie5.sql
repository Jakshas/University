SELECT C.FirstName, C.LastName, SUM(SalesLT.SalesOrderDetail.UnitPriceDiscount * SalesLT.SalesOrderDetail.OrderQty)
FROM SalesLT.Customer C 
INNER JOIN SalesLT.SalesOrderHeader 
ON C.CustomerID = SalesLT.SalesOrderHeader.CustomerID
INNER JOIN SalesLT.SalesOrderDetail
ON SalesLT.SalesOrderDetail.SalesOrderID = SalesLT.SalesOrderHeader.SalesOrderID
GROUP BY C.FirstName, C.LastName
HAVING NOT SUM(SalesLT.SalesOrderDetail.UnitPriceDiscount * SalesLT.SalesOrderDetail.OrderQty) = 0