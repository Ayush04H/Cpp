/*
1. SQL DDL Commands (Data Definition Language)
sql
Copy
Edit
-- CREATE a new table
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    EmpName VARCHAR(50),
    Age INT
);

-- ALTER a table to add a column
ALTER TABLE Employee 
ADD Salary DECIMAL(10, 2);

-- DROP a table
DROP TABLE Employee;

-- RENAME a table
ALTER TABLE Employee
RENAME TO Staff;

-- TRUNCATE a table (delete all rows)
TRUNCATE TABLE Staff;
2. SQL DML Commands (Data Manipulation Language)
sql
Copy
Edit
-- INSERT data
INSERT INTO Employee (EmpID, EmpName, Age, Salary) 
VALUES (101, 'John Doe', 30, 50000.00);

-- UPDATE data
UPDATE Employee 
SET Salary = 60000.00 
WHERE EmpID = 101;

-- DELETE data
DELETE FROM Employee 
WHERE EmpID = 101;

-- SELECT data
SELECT * FROM Employee;
3. SQL Constraints and Keys
sql
Copy
Edit
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    OrderDate DATE NOT NULL,
    CustomerID INT UNIQUE,
    TotalAmount DECIMAL(10, 2) CHECK (TotalAmount > 0),
    ProductID INT REFERENCES Products(ProductID),
    Status VARCHAR(10) DEFAULT 'Pending'
);
Common Constraints
NOT NULL: Ensures a column cannot be null.
UNIQUE: Ensures all values in a column are different.
PRIMARY KEY: A unique identifier for each row (combines NOT NULL + UNIQUE).
FOREIGN KEY: Enforces referential integrity.
CHECK: Ensures a condition is met.
DEFAULT: Provides a default value for a column.
4. SQL Set Commands
sql
Copy
Edit
-- UNION
SELECT EmpName FROM Employee
UNION
SELECT CustomerName FROM Customers;

-- UNION ALL
SELECT EmpName FROM Employee
UNION ALL
SELECT CustomerName FROM Customers;

-- INTERSECT
SELECT EmpName FROM Employee
INTERSECT
SELECT CustomerName FROM Customers;

-- MINUS (in some databases like Oracle)
SELECT EmpName FROM Employee
MINUS
SELECT CustomerName FROM Customers;
5. SQL Joins
sql
Copy
Edit
-- INNER JOIN
SELECT e.EmpName, d.DeptName
FROM Employee e
INNER JOIN Department d ON e.DeptID = d.DeptID;

-- LEFT JOIN
SELECT e.EmpName, d.DeptName
FROM Employee e
LEFT JOIN Department d ON e.DeptID = d.DeptID;

-- RIGHT JOIN
SELECT e.EmpName, d.DeptName
FROM Employee e
RIGHT JOIN Department d ON e.DeptID = d.DeptID;

-- FULL JOIN
SELECT e.EmpName, d.DeptName
FROM Employee e
FULL JOIN Department d ON e.DeptID = d.DeptID;

-- SELF JOIN
SELECT e1.EmpName AS Manager, e2.EmpName AS Subordinate
FROM Employee e1
INNER JOIN Employee e2 ON e1.EmpID = e2.ManagerID;
6. SQL TCL Commands (Transaction Control Language)
sql
Copy
Edit
-- BEGIN TRANSACTION
BEGIN TRANSACTION;

-- Insert some data
INSERT INTO Employee (EmpID, EmpName, Age) VALUES (102, 'Alice', 28);

-- COMMIT the transaction
COMMIT;

-- ROLLBACK the transaction
ROLLBACK;
7. SQL View
sql
Copy
Edit
-- Create a view
CREATE VIEW EmployeeView AS
SELECT EmpName, Age, Salary
FROM Employee
WHERE Salary > 50000;

-- Select from the view
SELECT * FROM EmployeeView;

-- Drop a view
DROP VIEW EmployeeView;
8. SQL Triggers
sql
Copy
Edit
-- Create a trigger that logs changes to the Employee table
CREATE TRIGGER LogEmployeeChanges
AFTER UPDATE ON Employee
FOR EACH ROW
BEGIN
    INSERT INTO EmployeeLog(EmpID, OldSalary, NewSalary)
    VALUES (OLD.EmpID, OLD.Salary, NEW.Salary);
END;

-- Drop the trigger
DROP TRIGGER LogEmployeeChanges;
9. SQL Indexing
sql
Copy
Edit
-- PRIMARY Index (usually created automatically with PRIMARY KEY)
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    EmpName VARCHAR(50)
);

-- SECONDARY Index
CREATE INDEX idx_empname ON Employee(EmpName);

-- MULTILEVEL Index (Composite Index)
CREATE INDEX idx_emp_composite ON Employee(EmpName, Age);



1. GRANT Command
Used to provide privileges to users on database objects like tables, views, or schemas.

sql
Copy
Edit
-- Grant SELECT and INSERT privileges on the Employee table to user 'John'
GRANT SELECT, INSERT 
ON Employee 
TO John;

-- Grant ALL privileges on a database to a user
GRANT ALL PRIVILEGES 
ON DatabaseName.* 
TO 'John'@'localhost';

-- Grant with admin option
GRANT SELECT 
ON Employee 
TO John 
WITH GRANT OPTION;
2. REVOKE Command
Used to withdraw privileges given by the GRANT command.

sql
Copy
Edit
-- Revoke SELECT and INSERT privileges from user 'John'
REVOKE SELECT, INSERT 
ON Employee 
FROM John;

-- Revoke all privileges on the database
REVOKE ALL PRIVILEGES 
ON DatabaseName.* 
FROM 'John'@'localhost';
3. Denying Permissions (Specific Databases Support)
Some databases support more granular control using DENY (e.g., SQL Server).

sql
Copy
Edit
-- Deny DELETE permission to user 'John' in SQL Server
DENY DELETE 
ON Employee 
TO John;
*/