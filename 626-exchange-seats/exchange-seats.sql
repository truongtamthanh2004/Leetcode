# Write your MySQL query statement below
with cte as 
    (
        select id, student, if (id % 2 = 0, id - 1, id + 1) as new_id 
        from seat
    )

select new_id as id, student 
from cte
where new_id in (select id from seat)
union
select id, student
from cte
where new_id not in (select id from seat)
order by id




