SELECT C.Name, P.Name 
FROM SalesLT.Product P, SalesLT.ProductCategory C
WHERE C.ProductCategoryID = P.ProductCategoryID AND EXISTS (
	SELECT 1 
	FROM SalesLT.ProductCategory 
	WHERE  C.ProductCategoryID = ParentProductCategoryID)