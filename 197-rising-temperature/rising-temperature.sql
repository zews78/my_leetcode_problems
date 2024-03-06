/* Write your T-SQL query statement below */
select b.id
from weather a
inner join weather b 
on DATEDIFF(day, a.recordDate, b.recordDate) = 1 and b.temperature>a.temperature

-- select a.id
-- from weather a, weather b
-- where DATEDIFF(day, a.recordDate, b.recordDate) = 1

-- select w2.id from weather w1 
-- inner join weather w2
-- on DATEDIFF(day, w1.recordDate, w2.recordDate ) = 1