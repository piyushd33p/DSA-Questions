# Write your MySQL query statement below

SELECT tweet_id FROM Tweets WHERE LENGTH(content) > 15 GROUP BY tweet_id
