using System;
namespace ScreeningRubric
{
	/*This is the first part of the screening. We use the following Criteria to check to see if the student has met the following:

	1) They had all required documents
	2) They have the required grade and class prerequisites
	3) Their application documents were organized and professional
	4) Work Experience
	5) Work Experience directly related to the job (tutoring and TA experience).

	We grade using these ranges: 7- Excellent	6 - Good	5- Average	4- Below average	3 - Fail

	EXCELLENT:

	Q1. cover letter, resume, transcript, answered all application questions
	Q2. They have taken the required class online, or on campus at BYUI and have exceeded the required grade.
	Q3. Grammar was correct. It was organized in a professional manner, with more content, than flashy colors or clip art. Easy to follow their work experience. Used relevant details when desribing their past work. For example: demonstrates dependability, and good work ethic by the details of what they write about their work and volunteer experience, instead of just saying, " I am dependable and work hard" and basic phrases like that.
	Q4. They have worked in a a lot of capacities that involve communicating with others and show a level of responsibility that requires a high level of initiative. Have experience related to the subject matter of the course they are applying.
	Q5. Has had  TA/Tutoring experience, Or experience that involves educating others in any capacity


	


	GOOD:

	Q1. must have cover letter 
	Q2. They have taken the required class online, or on campus at BYUI and have met the required grade requirements. Or have taken an advanced version of the class, but not the class they are applying for.
	Q3.	Grammar was ok. Could have written in a more concise and specific way, but was able to get a clear picture of their work experience that is relevant to the position they are applying for.
	Q4.	They have had good work experience with a variety of jobs which take initaive and working with others.
	Q5.	Has had some TA/Tutoring experience, Or experience that involves educating others in any capacity

	
	 
	 

	AVERAGE:

	Q1. If they send a transcript after we ask them to, give them a score of 5 in this category: did not include a cover letter
	Q2. Has taken the equivilant of the class from another school and have met the grade requirements. Or AP class in High school. If they send a transcript after we ask them to, give them a score of 5 in this category. 
	Q3. Vague but readable. Can see that they have work experience. A little bombastic.
	Q4. Resume has had some work experience with some jobs requiring working with others on some level, or taking some initiative
	Q5. Has had little TA/Tutoring experience, Or experience that involves educating others in any capacity



	BELOW AVERAGE:

	Q1. if they did not include a transcript, but switcth to a socre of 5 when the do send it.
	Q2. Have taken the equivalent class from another school and barely met grade requirements. Grade in Progres: The score can be changed for these when they send us a transcript. 
	Q3. Some grammar and spelling errors. Disorganized, or overly bombastic.
	Q4. Havn't worked much. Or jobs they have had do not require working with others, or taking initiative
	Q5. Has had no TA/Tutoring experience, Or experience that involves educating others in any capacity


	FAIL:

	Q1. No resume. NOTE: If they did not include transcript, email them or call them to send it to us. If they have not included a resume, they fail the screening process.
	Q2. Has not taken the class - If they have not taken the class they fail the entire screening process no matter how well they have done in other areas
	Q3. Riddled with grammar and spelling errors, Can't get an accurate picture of what they have done for work.  Confusing or unprofessional in language or presentation. Unprofessional = no standard resume formatting.
	Q4. Have not worked at all in any capacity, or very little. No job that requires working with others, or taking initiative.
	Q5. No experience related to Teaching Assisting, or Tutoring
	 */


	// The anatomy of  Class: it has Data(represented by fields) and Behavior(represented by methods / functions)
	public class Application
	{
		private int RequiredDocuments; // They had all required documents.
		private int Grade; // They have the required grade and class prerequisites.
		private int DocumentOrganization; // Their application documents were organized and professional.
		private int WorkExperience; // Any work experience.
		private int WorkExperienceRelated; // Work experience directly related to the Job(TA or Tutor experience.


		public void setrequiredDocuments(int documents)
		{
			this.RequiredDocuments = documents;

		}
		public void setgrade(int grade)
		{
			this.Grade = grade;
		}
		public void setdocumentOrg(int docOrganization)
		{
			this.DocumentOrganization = docOrganization;
		}
		public void setworkExp(int experience)
		{
			this.WorkExperience = experience;
		}
		public void setworkExpRelated(int experiencerelated)
		{
			this.WorkExperienceRelated = experiencerelated;
		}


		public int getrequiredDoc()
		{
			return this.RequiredDocuments;
		}

		public int getgrade()
		{
			return this.Grade;
		}

		public int getdocumentOrg()
		{
			return this.DocumentOrganization;
		}
		public int getworkExperience()
		{
			return this.WorkExperience;
		}

		public int getworkExperienceRel()
		{
			return this.WorkExperienceRelated;
		}

	}
}

