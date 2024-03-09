/* Write your T-SQL query statement below */
-- select st.student_id, count(e.subject_name) as attended_exams
-- -- select *
-- from Students as st
-- left join examinations as e ON st.student_id=e.student_id 
-- full outer join subjects as sub ON e.subject_name = sub.subject_name
-- group by sub.subject_name, st.student_id



-- select st.student_id, sub.subject_name, count(e.subject_name) as attended_exams
-- from examinations as e
-- left outer join subjects as sub on sub.subject_name=e.subject_name
-- right outer join students as st ON e.student_id=st.student_id
-- group by  sub.subject_name, st.student_id


select st.student_id, st.student_name, sub.subject_name, count(e.subject_name) as attended_exams
from students as st
cross join subjects as sub
left join examinations as e ON st.student_id=e.student_id and sub.subject_name=e.subject_name
group by  sub.subject_name, st.student_id, st.student_name
order by student_id, subject_name
 









-- select sub.subject_name, count(e.student_id) as attended_exams
-- from subjects as sub
-- left join examinations as e ON sub.subject_name=e.subject_name
-- right join students as st ON st.student_id=sub.student_id
-- group by sub.subject_name