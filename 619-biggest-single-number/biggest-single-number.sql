# Write your MySQL query statement below
-- select count(distinct num)
-- select ifnull(max(num), null) as num
select max(num) as num
from(
select *
from MyNumbers
group by num
having count(num)=1) as n

-- select num
-- from MyNumbers
-- group by num
-- having count(num)=1