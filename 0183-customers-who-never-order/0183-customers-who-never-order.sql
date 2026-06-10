SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerID
WHERE o.id is NULL;
