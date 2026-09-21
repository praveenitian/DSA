# Write your MySQL query statement below
with oneyear as (
    select product_id,year as first_year,quantity,price,
    RANK() over (partition by product_id Order by year) as ranked
    From Sales
)

select product_id,first_year,quantity,price
from oneyear
where ranked=1;
