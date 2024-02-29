/* Write your T-SQL query statement below */
select employeeUNI.unique_id, employees.name
from employees
left join employeeUNI on employees.id=employeeuni.id