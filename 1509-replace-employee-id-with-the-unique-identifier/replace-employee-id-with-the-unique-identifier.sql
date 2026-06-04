# Write your MySQL query statement below
select p.name,e.unique_id 
from Employees p
LEFT JOIN employeeUNI e on e.id = p.id;