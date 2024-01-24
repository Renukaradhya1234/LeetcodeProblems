using BaseNamespace;

namespace Collections.Algorithms
{
	internal class SetCollection : IQueueStack
	{
		readonly DoubleLinkedList doubleLinked = new();
		public void AddValue()
		{
			Console.WriteLine("Enter the Value: ");
			int Data = Convert.ToInt32(Console.ReadLine());
			if(!doubleLinked.Contains(Data))
			{
				doubleLinked.AddEnd(Data);
			}
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
			doubleLinked.RemoveValue();
		}

		public void AskQuestion()
		{
			SetCollection set = new();
			while(true)
			{
				Console.WriteLine("Enter the Choice: ");
				string? Choice = Console.ReadLine();

				if(Choice == "add")
				{
					set.AddValue();
				}
				else if(Choice == "dis")
				{
					set.Display();
				}
				else if(Choice == "upd")
				{
					set.UpdateValue();
				}
				else if(Choice == "rem")
				{
					set.RemoveValue();
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