using Collections.Algorithms;

namespace MyNamespace
{
	internal class Program
	{
		private static void Main()
		{
			Console.WriteLine("Program Running...");

			DoubleLinkedList doubleLinked = new();
			doubleLinked.AskQuestion();
			
			Console.WriteLine("Program Ended...");
		}
	}
}