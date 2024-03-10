/* Write your T-SQL query statement below */
-- select a.name, count(b.id)
-- -- select *
-- from employee a, employee b
-- -- cross join employee b

-- where a.id <> b.managerId
-- group by a.managerid, a.name
-- -- having count(b.managerId)>=25

-- select id, count(managerID)
-- from employee
-- group by id

select name
from employee
where id in (select managerId from employee group by managerid having count(managerId)>4)

