# Write your MySQL query statement below
select p.product_name,sum(o.unit) as unit from products p left join orders o on p.product_id = o.product_id
where (MONTH(ORDER_DATE)=2 and year(order_date)=2020) 
GROUP BY p.product_id, p.product_name
Having sum(unit) >=100 
