/* Write your T-SQL query statement below */
-- select len(content) as content_len from tweets
select tweet_id from tweets
where len(content)>15