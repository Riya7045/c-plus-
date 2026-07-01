# Write your MySQL query statement below
(select u.name as results from Users u left join MovieRating r on  u.user_id = r.user_id 
group by u.user_id
order by count(rating) desc,name asc limit 1)

UNION ALL

(select m.title as results from movies m left join MovieRating r on m.movie_id = r.movie_id 
where month(created_at)=2 AND Year(created_at)=2020
group by m.movie_id
order by avg(rating) desc, title asc limit 1);