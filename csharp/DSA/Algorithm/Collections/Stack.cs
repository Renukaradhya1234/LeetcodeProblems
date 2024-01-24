using BaseNamespace;

namespace Collections.Algorithms
{
	internal class StackCollection : IQueueStack
	{
        readonly DoubleLinkedList doubleLinked = new();
		public void AddValue()
		{
			doubleLinked.AddEnd(null);
		}

		public void Display()
		{
			doubleLinked.Display();
		}

		public void UpdateValue()
		{
			doubleLinked.UpdateValue();
		}

		public void RemoveValue()
		{
			doubleLinked.RemoveLast();
		}

		public void AskQuestion()
		{
			StackCollection stack = new();
			while(true)
			{
				Console.WriteLine("Enter the Choice: ");

				string? Choice = Console.ReadLine();

				if(Choice == "add")
				{
					stack.AddValue();
				}
				else if(Choice == "dis")
				{
					stack.Display();
				}
				else if(Choice == "up")
				{
					stack.UpdateValue();
				}
				else if(Choice == "rem")
				{
					stack.RemoveValue();
				}
				else if(Choice == "quit")
				{
					break;
				}
				else 
				{
					Console.WriteLine("Enter the Correct Choice");
				}
			}
		}
	}

}