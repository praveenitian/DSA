CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
--     DECLARE M INT;
--   SET M = N - 1;
    set n=n-1;

  RETURN (
      # Write your MySQL query statement below.
        SELECT DISTINCT salary 
      FROM Employee 
      ORDER BY salary DESC 
      LIMIT 1 OFFSET N
  );
END