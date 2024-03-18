# Write your MySQL query statement below
select ROUND(count(*)*100/(select count(distinct customer_id) from delivery), 2) as immediate_percentage
from delivery
where (customer_id, customer_pref_delivery_date ) IN (
    select customer_id, min(order_date)
    from delivery
    group by customer_id
)