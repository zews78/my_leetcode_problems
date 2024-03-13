/* Write your T-SQL query statement below */
select LEFT(CAST(trans_date AS  nvarchar), 7) AS month, country,
count(LEFT(CAST(trans_date AS  nvarchar), 7)) as trans_count,
count(case when state='approved' then 1 else null end) as approved_count,
sum(amount) as trans_total_amount,
sum(case when state='approved' then amount else 0 end) as approved_total_amount

from transactions
group by LEFT(CAST(trans_date AS  nvarchar), 7), country
-- order by LEFT(CAST(trans_date AS  nvarchar), 7), country