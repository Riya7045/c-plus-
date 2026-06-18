# Write your MySQL query statement below
-- select product_id, year as first_year, quantity, price 
-- from sales where (product_id, year) in (
--     select product_id, min(year)
--     from sales
--     group by product_id
-- )
with cte as (select *, dense_rank() over (partition by product_id order by year) as rnk from Sales)


select product_id, year as first_year, quantity, price from cte where rnk = 1;