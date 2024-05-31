/* Write your T-SQL query statement below */
select customer_number
from Orders
group by customer_number
having count(*) >= all (select count(*) from Orders group by customer_number)