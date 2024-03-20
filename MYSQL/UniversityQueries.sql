
-- QUESTION 1
	USE university;
	SELECT fname AS 'first_name', lname AS 'last_name'
					,DATE_FORMAT( DOB, "%M %e, %Y") AS 'Sept Birthdays'
	FROM student
	WHERE MONTH(DOB) = 9
	ORDER BY lname;
      
-- QUESTION 2
	SELECT lname AS 'first_name'
                , fname AS 'last_name' 
                ,FLOOR(DATEDIFF('2017-01-05', dob )/365) AS 'Years' 
				,DATEDIFF('2017-01-05', dob) MOD 365 AS 'Days'
				,CONCAT(FLOOR(DATEDIFF('2017-01-05', dob )/365), " - Years, " 
				,DATEDIFF('2017-01-05', dob) MOD 365, "- Days") as "Years and Days"
	FROM student
	ORDER BY years DESC;
      
-- QUESTION 3 
	SELECT st.fname, st.lname 
	FROM student st
	JOIN enrolment en
		ON st. student_id = en. student_id
	JOIN section se 
		 ON en. section_id = se. section_id
	JOIN faculty fac 
		ON se.fac_id = fac.fac_id
	WHERE fac.lname = "Jensen" and fac.fname = "John"
	ORDER BY st.fname;
            
-- QUESTION 4
    SELECT fac.fname, fac.lname
	FROM faculty fac
	JOIN section se 
		ON fac.fac_id = se.fac_id
	JOIN enrolment en 
		ON en.section_id = se.section_id
	JOIN student st
		ON en.student_id = st.student_id
	JOIN term te 
	    ON se.term_id = te.term_id
	WHERE st.fname = "Bryce" AND (te.term = 'WINTER' AND te.year = 2018)
	ORDER BY fac.lname;
          
-- QUESTION 5
	SELECT fname AS 'first_name', lname AS 'last_name'
	FROM student st
	JOIN enrolment en 
		ON st. student_id = en. student_id
	JOIN section se 
		ON en.section_id = se.section_id
	JOIN term te 
		ON se.term_id = te.term_id
	JOIN course co 
	    ON co.course_id = se.course_id
	WHERE co.course_name = 'econometrics' AND (te.term = 'FALL' AND te.year = 2019)
	ORDER BY st.lname;
             
-- QUESTION 6
	SELECT dep_code, co.course_id, course_name
	FROM course co
	JOIN section se 
		ON co.course_id = se.course_id
	JOIN term te 
		ON se.term_id = se.term_id
	JOIN enrolment en
		ON se.section_id =en.section_id
	JOIN student st 
		ON st.student_id = en.student_id
	WHERE (st.fname = 'Bryce' AND st.lname = 'Carlson') AND te.term = 'WINTER'
	ORDER BY co.course_name;
                
-- QUESTION 7
  SELECT term, year, COUNT( DISTINCT st.student_id) as 'enrollment'
  FROM student st 
  JOIN enrolment en 
	 ON st.student_id = en.student_id
 JOIN section se 
	ON se.section_id = en.section_id
JOIN term te 
	ON se.term_id = te.term_id
WHERE te.term = 'FALL' and te.year = 2019 
GROUP BY term, year;

              
-- QUESTION 8 
SELECT college_name, COUNT(course_name) AS 'courses'
FROM college col 
JOIN department dep 
	ON col.college_id = dep.college_id
JOIN course co 
	ON co.dep_code = dep.dep_code
GROUP BY college_name
HAVING courses
ORDER BY courses DESC;
                
-- QUESTION 9
SELECT fac.fname, fac.lname, SUM(capacity) AS 'TeachingCapacity' 
FROM faculty fac
JOIN section se
   ON fac.fac_id = se.fac_id 
JOIN term TE 
   ON te.term_id = se.term_id 
WHERE te.term = 'WINTER' AND te.year = 2018
GROUP BY fac.fac_id   
HAVING TeachingCapacity
ORDER BY TeachingCapacity;
                   
-- QUESTION 10
SELECT lname, fname, SUM(credits) AS 'Credits'
FROM student st 
JOIN enrolment en 
   ON st.student_id = en.student_id
 JOIN section se 
   ON se.section_id = en.section_id
 JOIN course co 
   ON co.course_id = se.course_id
 JOIN term te 
   ON te.term_id = se.term_id
 WHERE te.year= 2019 AND te.term = "FALL" 
 GROUP BY st.student_id
 HAVING Credits > 3
 ORDER BY Credits DESC;

              

