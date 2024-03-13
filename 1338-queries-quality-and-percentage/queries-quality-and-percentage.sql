/* Write your T-SQL query statement below */
select query_name, round(sum(cast(rating as float)/position)/count(*),2) as quality, round(cast(count(case when rating<3 then 1 else null end) as float)*100/count(*), 2) as poor_query_percentage 
from queries
where query_name is not null
group by query_name