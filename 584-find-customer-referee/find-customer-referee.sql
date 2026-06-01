# Write your MySQL query statement below
Select name 
From Customer
where (referee_id!=2 OR referee_id IS NULL);