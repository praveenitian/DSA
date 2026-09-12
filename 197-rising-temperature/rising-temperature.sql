# Write your MySQL query statement below
SELECT a.id
FROM Weather as a
Join Weather as b
on datediff(a.recordDate,b.recordDate)=1
where a.temperature>b.temperature;