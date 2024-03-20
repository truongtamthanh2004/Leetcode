# Write your MySQL query statement below
-- select st.student_id, st.student_name, su.subject_name, count(e.subject_name) as attended_exams
-- from  Students st
-- left join Examinations e on e.student_id = st.student_id
-- join Subjects su on e.subject_name = su.subject_name
-- group by st.student_id, st.student_name, su.subject_name
-- order by st.student_id, e.subject_name
select st.student_id, st.student_name, su.subject_name, count(e.subject_name) as attended_exams 
from students st 
cross join subjects su 
left join Examinations e on st.student_id =  e.student_id and e.subject_name = su.subject_name
group by st.student_id, st.student_name, su.subject_name
order by st.student_id, su.subject_name