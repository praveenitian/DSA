# Write your MySQL query statement below
-- SELECT a.id
-- FROM Weather as a
-- Join Weather as b
-- on datediff(a.recordDate,b.recordDate)=1
-- where a.temperature>b.temperature;


-- SUBQUERY METHOD
-- select id
-- from (
--     select id,recordDate,temperature,
--     lag(temperature) over(order by recordDate) as prev_temp,
--     lag(recordDate) over(order by recordDate) as prev_date
--     from Weather
-- ) as temphistory
-- where temperature>prev_temp and datediff(recordDate,prev_date)=1

with weatherhistory as (
    select id,recordDate,temperature,
    lag(temperature) over(order by recordDate) as prev_temp,
    lag(recordDate) over(order by recordDate) as prev_date
    from Weather
)

select id
from weatherhistory
where temperature>prev_temp and datediff(recordDate,prev_date)=1;