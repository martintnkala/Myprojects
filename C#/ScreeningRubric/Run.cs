using System;
namespace ScreeningRubric
{
	public class Run
	{
		public static void Main(String[] args)
		{
			// I am creating an instance of the class(Application) Object
			Application John = new Application();

			
			John.setrequiredDocuments(5);
			John.setgrade(6);
			John.setdocumentOrg(6);
			John.setworkExp(6);
			John.setworkExpRelated(7);


			// This a second instance of the Object class(Application)

			Application Smith = new Application();


			Smith.setrequiredDocuments(5.5F);
			Smith.setgrade(5F);
			Smith.setdocumentOrg(5.5F);
			Smith.setworkExp(5F);
			Smith.setworkExpRelated(5.5F);



			Console.Write("---------------- This is John's scores and overall score for the Application part----------------\n\n");

			Console.WriteLine("Required Documents grade score: " + John.getrequiredDoc() + " " + " Class grade score: " + John.getgrade()
				+ " Documentation organization Score: " + John.getdocumentOrg() + " Work experience: " + John.getworkExperience() +
				" Work experience related to the Job: " + John.getworkExperienceRel() + "\n");

			// Finding John's Overall score

			float results = (float)(John.getrequiredDoc() + John.getgrade() + John.getdocumentOrg() + John.getworkExperience() + John.getworkExperienceRel());
			float finallResult =(results / 5);
			Console.WriteLine("Overall Score for John: " + finallResult);

			if (finallResult < 5)
			{
				Console.WriteLine("Failed. Please don't hire.");
			}
			else if (finallResult >= 5 && finallResult <= 5.9) 
			{
				Console.WriteLine("Moderate score, you could hire if you don't have candidates with score above 5.9");
			}

			else if (finallResult >= 6 && finallResult <= 7)
            {
				Console.Write("Good candidate please hire.");
            }

			else
			{
				Console.WriteLine("Grade out of range\n\n");
			}


			Console.Write("---------------- This is Smith's scores and overall score for the Application part----------------\n\n");

			Console.WriteLine("Required Documents grade score: " + Smith.getrequiredDoc() + " " + " Class grade score: " + Smith.getgrade()
				+ " Documentation organization Score: " + Smith.getdocumentOrg() + " Work experience: " + Smith.getworkExperience() +
				" Work experience related to the Job: " + Smith.getworkExperienceRel() + "\n");


			// Finding Smith's Overall score

			float myresults = (float)(Smith.getrequiredDoc() + Smith.getgrade() + Smith.getdocumentOrg() + Smith.getworkExperience() + Smith.getworkExperienceRel());
			float myfinallResult = (myresults / 5);
			Console.WriteLine("Overall Score for Smith: " + myfinallResult);

			// Conditional statement for Smith's scores

			if (myfinallResult < 5)
			{
				Console.WriteLine("Failed. Please don't hire.");
			}
			else if (myfinallResult >= 5 && myfinallResult <= 5.9)
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

