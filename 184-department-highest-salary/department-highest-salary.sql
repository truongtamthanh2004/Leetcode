/* Write your T-SQL query statement below */
with cte as (
    select departmentId, max(salary) as Salary 
    from Employee 
    group by departmentId
)
select d.name as Department, e.name as Employee, c.Salary
from Employee e
join cte c on c.departmentId = e.departmentId and c.Salary = e.salary
join Department d on e.departmentId = d.id
