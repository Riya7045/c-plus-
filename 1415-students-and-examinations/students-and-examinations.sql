# Write your MySQL query statement below
SELECT S.STUDENT_ID,
S.STUDENT_NAME, 
SB.SUBJECT_NAME,
COUNT(E.SUBJECT_NAME) AS ATTENDED_EXAMS
FROM STUDENTS S 
CROSS JOIN SUBJECTS SB
LEFT JOIN EXAMINATIONS E ON
S.STUDENT_ID = E.STUDENT_ID
AND sb.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, sb.subject_name
ORDER BY s.student_id, sb.subject_name;