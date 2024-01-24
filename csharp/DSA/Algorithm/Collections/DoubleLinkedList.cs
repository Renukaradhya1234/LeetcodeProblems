using BaseNamespace;
namespace Collections.Algorithms
{
	class DDLNode
	{
		public int Data { get; set; }
		public DDLNode? Next { get; set; }
		public DDLNode? Prev { get; set; }
	}
	public class DoubleLinkedList : IBluePrint
	{
		// length
		public int Count { get; set; }
		private DDLNode? Header { get; set; }
		public DoubleLinkedList()
		{
			Header = null;
		}

		// add to begin
		public void AddBegin()
		{
			Console.WriteLine("Enter the Value: ");
			int Data = Convert.ToInt32(Console.ReadLine());

			DDLNode? currentNode = Header;

			if (currentNode != null)
			{
				DDLNode newNode = new()
				{
					Next = currentNode,
					Data = Data,
					Prev = null
				};
				currentNode.Prev = newNode;
				Header = newNode;
			}
			else
			{
				DDLNode newNode = new()
				{
					Next = null,
					Data = Data,
					Prev = null
				};
				Header = newNode;
			}
			Count += 1;
		}

		// add to middle
		public void AddMiddle()
		{
			Console.WriteLine("Enter the Index: ");
			int UserIndex = Convert.ToInt32(Console.ReadLine());

			int NodeIndex = 0;

			DDLNode? currentNode = Header;

			while (currentNode != null)
			{
				if (NodeIndex > UserIndex)
				{
					break;
				}

				if (NodeIndex == UserIndex)
				{
					Console.WriteLine("Enter the Value: ");
					int Value = Convert.ToInt32(Console.ReadLine());
					DDLNode newNode = new()
					{
						Prev = currentNode.Prev,
						Data = Value,
						Next = currentNode
					};

					if (currentNode.Prev != null)
					{
						currentNode.Prev.Next = newNode;
					}

					Count += 1;
					break;
				}

				currentNode = currentNode.Next;
				NodeIndex += 1;
			}
		}

		// add to end
		public void AddEnd(int? Value)
		{
			int Data;
			if (Value != null)
			{
				Data = (int)Value;
			}
			else
			{
				Console.WriteLine("Enter the Value: ");
				Data = Convert.ToInt32(Console.ReadLine());
			}
			DDLNode? currentNode = Header;

			while (currentNode?.Next != null)
			{
				currentNode = currentNode.Next;
			}

			DDLNode newNode = new()
			{
				Prev = currentNode,
				Data = Data,
				Next = null
			};
			if (currentNode != null)
			{
				currentNode.Next = newNode;
			}
			else
			{
				Header = newNode;
			}

			Count += 1;
		}

		// display
		public void Display()
		{
			DDLNode? currentNode = Header;
			while (currentNode != null)
			{
				Console.WriteLine(currentNode.Data);
				currentNode = currentNode.Next;
			}
		}

		// update by index
		public void UpdateIndex()
		{
			Console.WriteLine("Enter the Index: ");
			int NodeIndex = Convert.ToInt32(Console.ReadLine());

			if (NodeIndex >= Count)
			{
				Console.WriteLine("Index Out Of Range...");
			}
			else
			{
				DDLNode? currentNode = Header;

				int Index = 0;

				while (currentNode != null)
				{
					if (Index > NodeIndex)
					{
						break;
					}

					if (Index == NodeIndex)
					{
						Console.WriteLine("Enter the Value: ");
						int Value = Convert.ToInt32(Console.ReadLine());

						currentNode.Data = Value;
						break;
					}

					currentNode = currentNode.Next;
					Index += 1;
				}
			}
		}

		// update by value
		public void UpdateValue()
		{
			DDLNode? currentNode = Header;

			int oldValue = Convert.ToInt32(Console.ReadLine());
			int newValue = Convert.ToInt32(Console.ReadLine());
			while (currentNode != null)
			{
				if (currentNode.Data == oldValue)
				{
					currentNode.Data = newValue;
				}
				currentNode = currentNode.Next;
			}
		}

		// remove first
		public void RemoveFirst()
		{
			if (Header?.Next != null)
			{
				Header = Header.Next;
			}
			else
			{
				Header = null;
			}
			Count -= 1;
		}

		// remove last
		public void RemoveLast()
		{
			DDLNode? currentNode = Header;

			while (currentNode?.Next != null)
			{
				currentNode = currentNode.Next;
			}
			if (currentNode != null && currentNode.Prev != null)
			{
				currentNode.Prev.Next = null;
			}
			Count -= 1;
		}

		// remove middle
		public void RemoveMiddle()
		{
			Console.WriteLine("Enter the Index: ");
			int NodeIndex = Convert.ToInt32(Console.ReadLine());

			DDLNode? currentNode = Header;

			int Index = 0;

			while (currentNode != null)
			{
				if (Index > NodeIndex)
				{
					break;
				}

				if (Index == NodeIndex)
				{
					if (currentNode.Prev != null)
					{
						currentNode.Prev.Next = currentNode.Next;
					}
					if (currentNode.Next != null)
					{
						currentNode.Next.Prev = currentNode.Prev;
					}
					Count -= 1;
					break;
				}

				currentNode = currentNode.Next;
				Index += 1;
			}
		}

		public void RemoveValue()
		{
			DDLNode? currentNode = Header;
			Console.WriteLine("Enter the Value: ");
			int Value = Convert.ToInt32(Console.ReadLine());
			while(currentNode != null)
			{
				if(currentNode.Data == Value)
				{
					if (currentNode.Prev != null)
					{
						currentNode.Prev.Next = currentNode.Next;
					}
					if (currentNode.Next != null)
					{
						currentNode.Next.Prev = currentNode.Prev;
					}
				}
				currentNode = currentNode.Next;
			}
		}

		// to check value present or not
		public bool Contains(int? Data)
		{
			int Value; 
			if(Data != null)
			{
				Value = (int)Data;
			}
			else
			{
				Console.WriteLine("Enter the Value: ");
				Value = Convert.ToInt32(Console.ReadLine());
			}

			DDLNode? currentNode = Header;

			while (currentNode != null)
			{
				if (currentNode.Data == Value)
				{
					return true;
				}
				currentNode = currentNode.Next;
			}
			return false;
		}

		// to find the value
		public int FindIndex()
		{
			int Value = Convert.ToInt32(Console.ReadLine());
			int Index = 0;

			DDLNode? currentNode = Header;

			while (currentNode != null)
			{
				if (currentNode.Data == Value)
				{
					break;
				}
				currentNode = currentNode.Next;
				Index += 1;
			}
			return Index;
		}

		public void AskQuestion()
		{
			DoubleLinkedList linkedList = new();
			while (true)
			{
				Console.WriteLine("Enter the Choice...");
				string? Choice = Console.ReadLine();

				if (Choice == "addbeg")
				{
					linkedList.AddBegin();
				}
				else if (Choice == "addmid")
				{
					linkedList.AddMiddle();
				}
				else if (Choice == "addend")
				{
					linkedList.AddEnd(null);
				}
				else if (Choice == "dis")
				{
					linkedList.Display();
				}
				else if (Choice == "upval")
				{
					linkedList.UpdateValue();
				}
				else if (Choice == "upind")
				{
					linkedList.UpdateIndex();
				}
				else if (Choice == "remf")
				{
					linkedList.RemoveFirst();
				}
				else if (Choice == "remm")
				{
					linkedList.RemoveMiddle();
				}
				else if (Choice == "reml")
				{
					linkedList.RemoveLast();
				}
				else if(Choice == "check")
				{
					if(linkedList.Contains(null))
					{
						Console.WriteLine("Value Found...");
					}
					else 
					{
						Console.WriteLine("Value Not Found...");
					}
				}
				else if(Choice == "findInd")
				{
					Console.WriteLine($"Index: {linkedList.FindIndex()}");
				}
				else if (Choice == "quit")
				{
					break;
				}
				else
				{
					Console.WriteLine("Enter the Correct Choice: ");
				}
			}
		}
	}
}