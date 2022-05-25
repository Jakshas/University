SELECT M.Name, COUNT(P.ProductID)
FROM SalesLT.ProductModel M, SalesLT.Product P
WHERE M.ProductModelID = P.ProductModelID
GROUP BY M.Name
HAVING COUNT(P.ProductID) > 1