using BaseNamespace;

namespace Collections.Algorithms
{
	internal class QueueCollection : IQueueStack
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
			doubleLinked.RemoveFirst();
		}

		public void AskQuestion()
		{
			QueueCollection queue = new();
			while(true)
			{
				Console.WriteLine("Enter the Choice: ");

				string? Choice = Console.ReadLine();

				if(Choice == "add")
				{
					queue.AddValue();
				}
				else if(Choice == "dis")
				{
					queue.Display();
				}
				else if(Choice == "up")
				{
					queue.UpdateValue();
				}
				else if(Choice == "rem")
				{
					queue.RemoveValue();
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