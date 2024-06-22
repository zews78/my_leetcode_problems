# Write your MySQL query statement below
WITH CTE as (select product_id, max(CASE WHEN change_date<='2019-08-16' THEN change_date
ELSE NULL END) as max_date 
from products
group by product_id)
select c.product_id, IFNULL(new_price, 10) as price
-- select *
from products p
RIGHT join CTE c on c.product_id = p.product_id and c.max_date = p.change_date