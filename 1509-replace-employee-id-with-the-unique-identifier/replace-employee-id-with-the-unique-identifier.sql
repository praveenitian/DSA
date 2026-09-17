# Write your MySQL query statement below
select b.unique_id as unique_id,a.name
From Employees a
Left Join EmployeeUNI b
on a.id=b.id