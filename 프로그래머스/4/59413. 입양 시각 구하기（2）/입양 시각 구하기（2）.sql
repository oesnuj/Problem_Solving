WITH RECURSIVE hours AS (
    SELECT 0 AS hour
    UNION ALL
    SELECT hour + 1
    FROM hours
    WHERE hour < 23
)
SELECT 
    hs.hour AS HOUR,
    COUNT(ANIMAL_ID) as COUNT
FROM ANIMAL_OUTS ao
RIGHT JOIN hours hs ON HOUR(ao.DATETIME) = hs.hour
GROUP BY hs.hour
ORDER BY hs.hour;