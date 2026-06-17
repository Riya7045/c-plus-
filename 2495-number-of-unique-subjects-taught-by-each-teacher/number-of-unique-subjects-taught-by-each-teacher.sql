# Write your MySQL query statement below
with cte as (
select teacher_id, subject_id from Teacher 
group by teacher_id,subject_id)

select teacher_id, count(subject_id) as cnt from cte group by teacher_id