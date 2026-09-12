# Write your MySQL query statement below
SELECT a.id
FROM Weather as a
Join Weather as b
-- on a.id=b.id
where datediff(a.recordDate,b.recordDate)=1
and a.temperature>b.temperature;