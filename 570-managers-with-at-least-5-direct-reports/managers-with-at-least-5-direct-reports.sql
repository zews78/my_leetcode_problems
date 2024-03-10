/* Write your T-SQL query statement below */
-- select *
select a.name
from employee a
inner join employee b on a.id=b.managerId
group by b.managerid, a.name 
having count(b.managerId)>4

-- select id, count(managerID)
-- from employee
-- group by id

-- select name
-- from employee
-- where id in (select managerId from employee group by managerid having count(managerId)>4)

