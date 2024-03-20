-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema university
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `university` ;

-- -----------------------------------------------------
-- Schema university
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `university` DEFAULT CHARACTER SET utf8mb3 ;
USE `university` ;

-- -----------------------------------------------------
-- Table `university`.`college`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`college` ;

CREATE TABLE IF NOT EXISTS `university`.`college` (
  `college_id` INT NOT NULL,
  `college_name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`college_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `university`.`student`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`student` ;

CREATE TABLE IF NOT EXISTS `university`.`student` (
  `student_id` INT NOT NULL,
  `fname` VARCHAR(30) NOT NULL,
  `lname` VARCHAR(30) NULL DEFAULT NULL,
  `gender` ENUM('M', 'F') NOT NULL,
  `city` VARCHAR(20) NOT NULL,
  `state` VARCHAR(25) NOT NULL,
  `dob` DATE NOT NULL,
  PRIMARY KEY (`student_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `university`.`term`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`term` ;

CREATE TABLE IF NOT EXISTS `university`.`term` (
  `term_id` INT NOT NULL,
  `term` ENUM('WINTER', 'SPRING', 'SUMMER', 'FALL') NOT NULL,
  `year` INT NOT NULL,
  PRIMARY KEY (`term_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `university`.`department`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`department` ;

CREATE TABLE IF NOT EXISTS `university`.`department` (
  `dep_code` VARCHAR(6) NOT NULL,
  `dep_name` VARCHAR(50) NOT NULL,
  `college_id` INT NOT NULL,
  PRIMARY KEY (`dep_code`),
  INDEX `fk_department_College1_idx` (`college_id` ASC) VISIBLE,
  CONSTRAINT `fk_department_College1`
    FOREIGN KEY (`college_id`)
    REFERENCES `university`.`college` (`college_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `university`.`course`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`course` ;

CREATE TABLE IF NOT EXISTS `university`.`course` (
  `course_id` INT NOT NULL,
  `course_name` VARCHAR(50) NOT NULL,
  `credits` INT NOT NULL,
  `dep_code` VARCHAR(6) NOT NULL,
  PRIMARY KEY (`course_id`),
  INDEX `fk_course_department1_idx` (`dep_code` ASC) VISIBLE,
  CONSTRAINT `fk_course_department1`
    FOREIGN KEY (`dep_code`)
    REFERENCES `university`.`department` (`dep_code`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `university`.`faculty`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`faculty` ;

CREATE TABLE IF NOT EXISTS `university`.`faculty` (
  `fac_id` INT NOT NULL,
  `fname` VARCHAR(20) NOT NULL,
  `lname` VARCHAR(20) NOT NULL,
  PRIMARY KEY (`fac_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `university`.`section`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`section` ;

CREATE TABLE IF NOT EXISTS `university`.`section` (
  `section_id` INT NOT NULL,
  `section_num` INT NOT NULL,
  `capacity` INT NOT NULL,
  `term_id` INT NOT NULL,
  `fac_id` INT NOT NULL,
  `course_id` INT NOT NULL,
  PRIMARY KEY (`section_id`),
  INDEX `fk_section_Term1_idx` (`term_id` ASC) VISIBLE,
  INDEX `fk_section_faculty1_idx` (`fac_id` ASC) VISIBLE,
  INDEX `fk_section_course1_idx` (`course_id` ASC) VISIBLE,
  CONSTRAINT `fk_section_course1`
    FOREIGN KEY (`course_id`)
    REFERENCES `university`.`course` (`course_id`),
  CONSTRAINT `fk_section_faculty1`
    FOREIGN KEY (`fac_id`)
    REFERENCES `university`.`faculty` (`fac_id`),
  CONSTRAINT `fk_section_Term1`
    FOREIGN KEY (`term_id`)
    REFERENCES `university`.`term` (`term_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `university`.`enrolment`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `university`.`enrolment` ;

CREATE TABLE IF NOT EXISTS `university`.`enrolment` (
  `student_id` INT NOT NULL,
  `section_id` INT NOT NULL,
  PRIMARY KEY (`student_id`, `section_id`),
  INDEX `fk_Students_has_section_section1_idx` (`section_id` ASC) VISIBLE,
  INDEX `fk_Students_has_section_Students1_idx` (`student_id` ASC) VISIBLE,
  CONSTRAINT `fk_Students_has_section_section1`
    FOREIGN KEY (`section_id`)
    REFERENCES `university`.`section` (`section_id`),
  CONSTRAINT `fk_Students_has_section_Students1`
    FOREIGN KEY (`student_id`)
    REFERENCES `university`.`student` (`student_id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;



-- INSERT STATEMENTS FOR STUDENTS TABLE
INSERT INTO student VALUES (1, 'Paul', 'Miller', 'M', 'Dallas', 'TX', '1996-02-22')
                            ,(2, 'Katie ', 'Smith', 'F', 'Provo', 'UT', '1995-07-22')
							,(3, 'Kelly', 'Jones', 'F', 'Provo', 'UT', '1998-06-22')
                            ,(4, 'Devon', 'Merrill', 'M', 'Mesa', 'AZ', '2000-07-22')
							,(5, 'Mandy', 'Murdock', 'F', 'Topeka', 'KS', '1996-11-22')
                            ,(6, 'Alece', 'Adams', 'F', 'Rigby', 'ID', '1997-05-22')
							,(7, 'Bryce', 'Carlson', 'M', 'Bozeman', 'MT', '1997-11-22')
							,(8, 'Preston', 'Carlson', 'M', 'Decatur', 'TN', '1996-09-22')
							,(9, 'Julia', 'Madsen', 'F', 'Rexburg', 'ID', '1998-09-22')
                            ,(10, 'Susan', 'Sorensen', 'F', 'Mesa', 'AZ', '1998-08-09');

-- INSERT STATEMENTS FOR COLLEGE TABLE
INSERT INTO college VALUES (1, 'College of Physical Science and engineering')
                           ,(2, 'College of Business and Communication')
						   ,(3, 'College of Language and Letters');

-- INSERT STATEMENTS FOR TERM
INSERT INTO term VALUES (1, 'Fall', 2019)
                       ,(2, 'Winter', 2018);

-- INSERT STATEMENTS FOR FACULTY
INSERT INTO faculty VALUES (1, 'Marty', 'Morring')
						  ,(2, 'Nate', 'Nathan')
                          ,(3, 'Ben', 'Barrus')
                          ,(4, 'John', 'Jensen')
						  ,(5, 'Bill', 'Barney');


-- INSERT STATEMENTS FOR THE DEPARTMENT
INSERT INTO department VALUES('CIT','Computer Information Technology', 1)
                             ,('ECON','Economics', 2)
                             ,('HUM','Humanities and Philosophy', 3);

-- INSERT STATEMENTS FOR COURSE
INSERT INTO course VALUES (111, 'Intro to databases', 3, 'CIT')
                          ,(388, 'Econometrics', 4, 'ECON')
						  ,(150, 'Micro Economics', 3, 'ECON')
						  ,(376, 'Classical Heritage', 2, 'HUM');

-- INSERT STATEMENTS FOR SECTION
INSERT INTO section VALUES (1, 1, 30, 1, 1, 111)
						  ,(2, 1, 50, 1, 2, 150)
                          ,(3, 2, 50, 1, 2, 150)
                          ,(4, 1, 35,1, 3, 388)
                          ,(5, 1, 30, 1, 4,376)
                          ,(6, 2, 30, 2, 1, 111)
                          ,(7, 3, 35, 2, 5, 111)
						  ,(8, 1, 50, 2, 2, 150)
                          ,(9, 2, 50, 2, 2, 150)
						  ,(10, 1, 30, 2, 4, 376);


-- INSERT STATEMENTS FOR ENROLMENT
INSERT INTO enrolment VALUES (6, 7)
                            ,(7, 6)
                            ,(7, 8)
							,(7, 10)
                            ,(4, 5)
						    ,(9,9)
                            ,(2, 4)
							,(3,4)
                            ,(5,4)
                            ,(5, 5)
							,(1, 1)
                            ,(1, 3)
							,(8, 9)
                            ,(10, 6);
