# Write your MySQL query statement below
select * FROM USERS
WHERE MAIL REGEXP'^[A-Za-z][a-zA-Z0-9._-]*@leetcode\\.com$'
AND mail LIKE BINARY '%@leetcode.com';;