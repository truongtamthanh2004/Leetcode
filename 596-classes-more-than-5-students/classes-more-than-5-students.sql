# Write your MySQL query statement below
select class
from Courses
GROUP BY class
having count(student) >= 5