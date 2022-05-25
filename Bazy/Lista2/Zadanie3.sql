SELECT A.City, COUNT(CA.CustomerID), COUNT(DISTINCT C.SalesPerson)
From SalesLT.Address A,SalesLT.CustomerAddress CA, SalesLT.Customer C
WHERE A.AddressID = CA.AddressID AND C.CustomerID = CA.AddressID
GROUP BY A.City