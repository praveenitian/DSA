# Write your MySQL query statement below
SELECT email as Email
FROM Person
GROUP BY email
Having count(id)>1;