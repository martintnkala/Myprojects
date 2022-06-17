using System;
namespace ScreeningRubric
{
	public class Run
	{
		public static void Main(String[] args)
		{
			Application John = new Application();

			// I created my 
			John.setrequiredDocuments(5);
			John.setgrade(6);
			John.setdocumentOrg(6);
			John.setworkExp(6);
			John.setworkExpRelated(7);


			Console.Write("---------------- This is John's scores and overall score for the Application part----------------\n\n");

			Console.WriteLine("Required Documents grade score: " + John.getrequiredDoc() + " " + " Class grade score: " + John.getgrade()
				+ " Documentation organization Score: " + John.getdocumentOrg() + " Work experience: " + John.getworkExperience() +
				" Work experience related to the Job: " + John.getworkExperienceRel() + "\n");

			// Finding John's Overall score

			int results = John.getrequiredDoc() + John.getgrade() + John.getdocumentOrg() + John.getworkExperience() + John.getworkExperienceRel();
			float finallResult = (float)results / 5;
			Console.WriteLine("Overall Score for John: " + finallResult);

			Console.WriteLine("-------------------------------------------------------------------------");

			if (finallResult < 5)
			{
				Console.WriteLine("Failed. Please don't hire.");
			}
			else if (finallResult >= 5 && finallResult <= 5.9)
			{
				Console.WriteLine("Moderate score, you could hire if you don't have candidates with score above 5.9");
			}

			else
			{
				Console.WriteLine("Good candidate please hire.");
			}

		}

	}

}

