# Write your MySQL query statement below
SELECT round(cast(count(*) as float)/(select count(distinct player_id) from activity), 2) as fraction
FROM activity
where (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) in(
    select player_id, min(event_date)
    from activity
    group by player_id
)




