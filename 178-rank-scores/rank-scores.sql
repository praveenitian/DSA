# Write your MySQL query statement below
Select score ,
DENSE_RANK() Over(Order By score desc) as 'rank'
From Scores;