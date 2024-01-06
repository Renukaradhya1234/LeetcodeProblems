using System;

namespace HelloWorld
{
	public static class StringExtenstion
    {
    	public static string ToFirst(this string input)
        {
        	if(input == null || input.Length == 0)
            {
            	return "";
			}
            else 
            {
            	return input[0].ToString();
            }
        }
	}
  internal class Program
  {
    static void Main()
    {
      Console.WriteLine("Program Running...");
      
      string OriginalString = "Renukaradhya";
      
      string ModifiedString = OriginalString.ToFirst();
      
      Console.WriteLine($"OriginalString: {OriginalString}");
      Console.WriteLine($"ModifiedString: {ModifiedString}");
      
      Console.WriteLine("Program Ended...");
    }
  }
}