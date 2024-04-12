# Write your MySQL query statement below
select a.employee_id, a.name, count(*) as reports_count, ROUND(avg(b.age)) as average_age
from employees a, employees b
where a.employee_id = b.reports_to 
group by a.employee_id
order by a.employee_id