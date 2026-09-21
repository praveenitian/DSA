# Write your MySQL query statement below

with RankedEmp as (
    Select b.name as Department,a.name as Employee,a.salary as Salary,
    DENSE_RANK() over(partition by b.name Order by a.salary desc) as ranked
    From Employee a
    Join Department b
    on a.departmentId=b.id
)

select Department ,Employee,Salary
From RankedEmp
where ranked<=3


