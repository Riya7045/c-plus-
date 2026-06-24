# Write your MySQL query statement below
with cte AS(
select person_name,weight,turn,sum(weight) over (order by turn) as t from queue)

select person_name from cte where t <= 1000 ORDER BY T DESC LIMIT 1;