-- -- # Write your MySQL query statement below
-- -- select round(Avg(player_id)*100,2) as fraction from activity
-- -- where event_date = min(event_date)+1    
-- -- group by player_id;

-- select distinct round((select count(distinct a1.player_id) from Activity a1
-- join Activity a2 on a1.event_date = a2.event_date - 1 and a1.player_id = a2.player_id where a1.event_date = min(a1.event_date) group by player_id) / (select count(distinct player_id) from Activity),2) as fraction from Activity;



-- select a1.player_id from Activity a1
-- join Activity a2 on a1.event_date = a2.event_date - 1 and a1.player_id = a2.player_id
-- where a1.event_date = min(a1.event_date) group by player_id
 
with cte as
(select player_id, min(event_date) as first_event_date
from activity
group by player_id),
cte2 as
(
select count(*) as riya from cte c left join activity a on c.player_id = a.player_id and datediff(a.event_date, c.first_event_date) = 1 where event_date is not null
)

select distinct round((select riya from cte2)/(select count(distinct player_id) from Activity), 2) as fraction from Activity

