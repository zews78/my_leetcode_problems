/* Write your T-SQL query statement below */
select e.name, b.bonus
from employee as e
left join bonus as b ON e.empId=b.empId
where bonus<1000 or bonus is null