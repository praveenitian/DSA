# Write your MySQL query statement below
select customer_number
from Orders
group by customer_number
Order by count(order_number) desc
limit 1;