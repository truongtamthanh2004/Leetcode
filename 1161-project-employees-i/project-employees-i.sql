/* Write your T-SQL query statement below */
SELECT p.project_id, ROUND(AVG(e.experience_years * 1.0), 2) AS average_years
FROM Project p
JOIN Employee e ON e.employee_id = p.employee_id
GROUP By p.project_id