# Write your MySQL query statement below
SELECT visited_on, amount, average_amount
FROM (
    SELECT visited_on,
           SUM(amount) OVER w AS amount,
           ROUND(SUM(amount) OVER w / 7, 2) AS average_amount,
           ROW_NUMBER() OVER (ORDER BY visited_on) AS rn
    FROM (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ) d
    WINDOW w AS (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW)
) t
WHERE rn >= 7;