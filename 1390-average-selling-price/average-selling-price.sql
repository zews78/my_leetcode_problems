/* Write your T-SQL query statement below */
-- select u.product_id,ROUND(CAST(SUM(p.price*u.units)as float)/CAST(SUM(u.units) as Float),2) as average_price
-- insert into mytest
select p.product_id, isNull(Round(cast(SUM(p.price*u.units) as float)/cast(sum(u.units) as float), 2),0) as average_price
from prices p
left join unitssold u on u.product_id=p.product_id and purchase_date between start_date and end_date
group by p.product_id

-- update mytest
-- set average_price = 0
-- where average_price is not null

