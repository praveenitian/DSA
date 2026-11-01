# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums
from Logs as a
join Logs as b
on b.id-a.id=1
join Logs as c
on c.id-b.id=1
where a.num=b.num and b.num=c.num
