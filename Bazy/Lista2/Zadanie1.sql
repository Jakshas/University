SELECT DISTINCT a.City 
FROM SalesLT.Address a 
WHERE EXISTS (
	SELECT 1 
	FROM SalesLT.SalesOrderHeader H 
	WHERE H.ShipToAddressID = a.AddressID) 
ORDER BY City