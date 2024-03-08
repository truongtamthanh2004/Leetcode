# Write your MySQL query statement below
select s.year, s.price, p.product_name
FROM Sales s LEFT JOIN Product p on s.product_id = p.product_id