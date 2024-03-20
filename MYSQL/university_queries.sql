
-- QUESTION 1

SELECT FNAME, LNAME, date_format( DOB, "%M %e, %Y") AS 'Sept Birthdays'
      from STUDENTS
      WHERE date_format( DOB, "%M %e, %Y") LIKE 'SEPTEMBER%'
      ORDER BY LNAME;
      
-- QUESTION 2

SELECT lname, fname, floor (datediff('2017-01-05', dob )/365) AS 'Years', DATEDIFF('2017-01-05', dob) MOD 365 AS 'Days',
      concat(floor (datediff('2017-01-05', dob )/365), " - Years, " , DATEDIFF('2017-01-05', dob) MOD 365, "- Days") as "Years and Days"
      FROM STUDENTS
	  ORDER BY YEARS desc;
      
-- QUESTION 3 

SELECT st.fname, st.lname 
      FROM STUDENTS ST
           JOIN enrolment EN
			ON ST. student_id = EN. student_id
             JOIN SECTION SE 
             ON EN. section_id = SE. section_id
			JOIN faculty fac 
			ON SE.fac_id = fac. fac_id
			where fac.LNAME = "Jensen" and fac.FNAME = "JOHN"
            ORDER BY FNAME;
            
-- QUESTION 4

    SELECT FAC.FNAME, FAC.LNAME
          FROM faculty fac
          JOIN SECTION SE 
		  ON fac.fac_id = SE.fac_id
		  JOIN enrolment EN 
		  ON EN.section_id = SE.SECTION_ID
          JOIN students ST
          ON EN.student_id = ST.student_id
         -- JOIN term TE 
         -- ON SE.term_id = TE.term_id
          where ST.fname = "BRYCE" 
          ORDER BY FAC.LNAME;
          
-- QUESTION 5

       SELECT FNAME, LNAME
             FROM students ST
             JOIN enrolment EN 
             ON ST. student_id = EN. student_id
             JOIN section SE 
             ON EN.section_id = SE.section_id
             JOIN term TE 
             ON SE.term_id = TE.term_id
             JOIN COURSE CO 
             ON CO.course_id = SE.course_id
             WHERE CO.course_name = 'econometrics' and TE.term = 'FALL' AND TE.year = 2019
             ORDER BY ST.LNAME;
             
-- QUESTION 6

           SELECT DEP_CODE, CO.COURSE_ID, COURSE_NAME
                FROM course CO
                JOIN section SE 
                ON CO.course_id = SE.course_id
                JOIN TERM TE 
                ON SE.term_id = TE.term_id
                JOIN enrolment EN
                ON SE.section_id =EN.section_id
                JOIN students ST 
                ON ST.student_id = EN.student_id
                WHERE ST.fname = 'BRYCE' 
                ORDER BY CO.course_name;
                
-- QUESTION 7
        
        SELECT term, year, COUNT(*) as 'enrollment'
               from students ST 
               JOIN enrolment EN 
               ON ST.student_id = EN.student_id
               JOIN section SE 
               ON SE.section_id = EN.section_id
               JOIN term TE 
               ON SE.term_id = TE.term_id
			   WHERE TE.term = 'fall' and TE.year = 2019 
               HAVING COUNT(*);
              
-- QUESTION 8 
     
          SELECT college_name, COUNT(COURSE_NAME) AS 'courses'
                 from college COL 
                 JOIN department DEP 
                 ON COL.college_id = DEP.college_id
                 JOIN COURSE CO 
                 ON CO.dep_code = DEP.dep_code
				 GROUP BY COLLEGE_NAME
				HAVING COUNT(COURSE_NAME)
                ORDER BY COUNT(COURSE_NAME) DESC;
                
-- QUESTION 9
 
              SELECT FAC.fname, FAC.lname, SUM(capacity) AS 'TeachingCapacity' 
				   FROM faculty FAC 
                   JOIN section SE
                   ON FAC.fac_id = SE.fac_id 
                   JOIN term TE 
                   ON TE.term_id = SE.term_id 
                   WHERE TE.term = 'WINTER' AND TE.year = 2018
                   GROUP BY FAC.fac_id   
                   HAVING sum( capacity)
                   ORDER BY TeachingCapacity;
                   
-- QUESTION 10

             SELECT lname, fname, SUM(CREDITS) AS 'Credits'
                 from students ST 
                 JOIN enrolment EN 
                 ON ST.student_id = EN.student_id
                 JOIN SECTION SE 
                 ON SE.section_id = EN.section_id
                 JOIN course CO 
                 ON CO.course_id = SE.course_id
                 JOIN term TE 
                 ON TE.term_id = SE.term_id
                 WHERE TE.year= 2019 AND TE.term = "FALL" 
                 GROUP BY ST.student_id
                 HAVING SUM(CREDITS) > 3
                 ORDER BY credits DESC;

              

