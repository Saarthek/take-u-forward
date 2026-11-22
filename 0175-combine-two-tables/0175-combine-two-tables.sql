# Write your MySQL query statement below
SELECT firstname, lastname, city, state 
FROM person p LEFT JOIN Address a
ON p.personId = a.personId;