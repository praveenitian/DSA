# Write your MySQL query statement below
with ranked1 as (
    select *,
    row_number() over(partition by product_id Order by change_date desc) as rnk
    from Products
    where change_date <='2019-08-16'
),
ranked2 as (
    select *,
    row_number() over(partition by product_id Order by change_date desc) as rnk
    from Products
    where change_date >'2019-08-16'
    AND product_id NOT IN (SELECT product_id FROM ranked1)
)
select product_id,new_price as price
from ranked1
where rnk=1

UNION

select product_id,10 as price
from ranked2
where rnk=1;
