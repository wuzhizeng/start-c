
查找学生所有选课的总学分并按升序排好的学生的名字

select student.stu_name,sum(course_credit) as sum_credit
from course,sc,student
where course.course_id=sc.course_id and
      sc.stu_id=student.stu_id
group by sc.stu_id,student.stu_name
order by sum_credit asc

------------------------
|stu_name   |sum_credit |
|刘晨       |        	6 |
|李勇       |        	10|
------------------------

查找选了数据且是计算机系的学生的学生名字

select stu_name
from student
where stu_dept='cs' and
      stu_id in
	         (select stu_id
			  from sc
			  where course_id in
			                  (select course_id
							   from course
							   where course_name='数据库'
							   )
			  )

----------
|stu_name |
|李勇     |
----------
