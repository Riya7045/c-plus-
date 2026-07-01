# Write your MySQL query statement below
select round(sum(tiv_2016),2) as tiv_2016 from insurance 
where tiv_2015 IN (
    select tiv_2015 from insurance 
    GROUP BY tiv_2015 
    HAVING COUNT(*) > 1
)
AND (lat,lon) IN (
    select lat,lon from insurance 
    GROUP BY lat,lon 
    HAVING COUNT(*) = 1
);