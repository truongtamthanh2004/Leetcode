/* Write your T-SQL query statement below */
select p.product_id, product_name
from Product p
inner join Sales sa on sa.product_id = p.product_id
group by p.product_id, product_name
having min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31'