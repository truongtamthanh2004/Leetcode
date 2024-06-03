# Write your MySQL query statement below
select user_id as buyer_id, join_date, count(case when year(order_date)=2019 then 1 else null end) as orders_in_2019
from Orders o
right join Users u on u.user_id = o.buyer_id
group by user_id