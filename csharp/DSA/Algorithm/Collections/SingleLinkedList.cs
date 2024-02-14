using BaseNamespace;

namespace Collections.Algorithms
{
	public class Node
	{
		public int Data { get; set; }
		public Node? Next { get; set; }
	}

	public static class SingleLinkedListExtension
	{
		public static void Sort(this SingleLinkedList singleLinkedList)
		{
			if (singleLinkedList != null)
			{
				Console.WriteLine("method called...");
				for (int Index = 0; Index < singleLinkedList.Count - 1; Index++)
				{
					for (int subIndex = 0; subIndex < singleLinkedList.Count - 1; subIndex++)
					{
						if (singleLinkedList[subIndex] > singleLinkedList[subIndex + 1])
						{
							(singleLinkedList[subIndex + 1], singleLinkedList[subIndex]) = (singleLinkedList[subIndex], singleLinkedList[subIndex + 1]);
						}
					}
				}
			}
		}
	}
	public class SingleLinkedList : IBluePrint
	{
		public Node? Header { get; set; }
		public int Count { get; set; }

		public SingleLinkedList()
		{
			Header = null;
		}

		// add to begin
		public void AddBegin()
		{
			Console.WriteLine("Enter the value: ");
			int data = Convert.ToInt32(Console.ReadLine());

			Node newNode = new()
			{
				Data = data,
				Next = Header
			};

			Header = newNode;
			Count += 1;
		}
		// add to middle
		public void AddMiddle()
		{
			Console.WriteLine("Enter the index: ");
			int index = Convert.ToInt32(Console.ReadLine());
			if (Header == null || index >= Count)
			{
				Console.WriteLine("Index Out of Range...");
			}
			else
			{
				Console.WriteLine("Enter the value: ");
				int data = Convert.ToInt32(Console.ReadLine());

				int currentIndex = 0;
				Node? currentNode = Header;

				while (currentIndex < index - 1)
				{
					currentNode = currentNode?.Next;
					currentIndex += 1;
				}
				if (currentNode != null)
				{
					Node newNode = new()
					{
						Data = data,
						Next = currentNode.Next
					};
					currentNode.Next = newNode;

					Count += 1;
				}
			}
		}
		// add to end
		public void AddEnd(int? Value)
		{
			int data;
			if (Value != null)
			{
				data = (int)Value;
			}
			else
			{
				Console.WriteLine("Enter the value: ");
				data = Convert.ToInt32(Console.ReadLine());
			}

			Node newNode = new()
			{
				Data = data,
				Next = null
			};

			if (Header == null)
			{
				Header = newNode;
			}
			else
			{
				Node currentNode = Header;

				while (currentNode.Next != null)
				{
					currentNode = currentNode.Next;
				}
				currentNode.Next = newNode;
			}
			Count += 1;
		}
		// display
		public void Display()
		{
			Node? currentNode = Header;

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
			int index = Convert.ToInt32(Console.ReadLine());

			int NodeIndex = 0;
			Node? currentNode = Header;
			while (NodeIndex < index && currentNode != null)
			{
				currentNode = currentNode.Next;
				NodeIndex += 1;
			}

			if (currentNode != null)
			{
				Console.WriteLine("Enter the Value: ");
				currentNode.Data = Convert.ToInt32(Console.ReadLine());
			}
		}
		// update by value
		public void UpdateValue()
		{
			Console.WriteLine("Enter the Old Value: ");
			int OldValue = Convert.ToInt32(Console.ReadLine());

			Console.WriteLine("Enter the New Value: ");
			int NewValue = Convert.ToInt32(Console.ReadLine());

			Node? currentNode = Header;

			while (currentNode != null)
			{
				if (currentNode.Data == OldValue)
				{
					currentNode.Data = NewValue;
				}
				currentNode = currentNode.Next;
			}
		}
		// remove first
		public void RemoveFirst()
		{
			if (Header != null)
			{
				Header = Header.Next;
				Count -= 1;
			}
			else
			{
				Console.WriteLine("List is Empty...");
			}
		}

		// remove middle
		public void RemoveMiddle()
		{
			Console.WriteLine("Enter the Index: ");
			int index = Convert.ToInt32(Console.ReadLine());

			Node? currentNode = Header;
			int NodeIndex = 0;
			while (NodeIndex < index - 1)
			{
				currentNode = currentNode?.Next;
				NodeIndex += 1;
			}

			if (currentNode != null && currentNode.Next != null)
			{
				currentNode.Next = currentNode.Next.Next;
				Count -= 1;
			}
		}

		// remove last
		public void RemoveLast()
		{
			Node? currentNode = Header;

			while (currentNode?.Next?.Next != null)
			{
				currentNode = currentNode.Next;
			}

			if (currentNode != null)
			{
				currentNode.Next = null;
				Count -= 1;
			}
		}

		public void RemoveValue()
		{
			Node? currentNode = Header;

			Console.WriteLine("Enter the Value: ");
			int Value = Convert.ToInt32(Console.ReadLine());

			while (currentNode != null)
			{
				if (currentNode.Next != null && currentNode.Next.Data == Value)
				{
					currentNode.Next = currentNode.Next.Next;
				}
				currentNode = currentNode.Next;
			}
		}
		// to check value present or not
		public bool Contains(int? Data)
		{
			int Value;

			if (Data != null)
			{
				Value = (int)Data;
			}
			else
			{
				Console.WriteLine("Enter the value: ");
				Value = Convert.ToInt32(Console.ReadLine());
			}

			Node? currentNode = Header;
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
			Console.WriteLine("Enter the value: ");
			int Value = Convert.ToInt32(Console.ReadLine());
			int index = 0;

			Node? currentNode = Header;

			while (currentNode != null)
			{
				if (currentNode.Data == Value)
				{
					break;
				}
				index += 1;
				currentNode = currentNode.Next;
			}
			return index;
		}

		public int this[int Index]
		{
			get
			{
				Node? currentNode = Header;

				int NodeIndex = 0;
				while (currentNode != null && NodeIndex < Count)
				{
					if (Index == NodeIndex)
					{
						return currentNode.Data;
					}
					NodeIndex += 1;
					currentNode = currentNode.Next;
				}

				throw new IndexOutOfRangeException("Index Out of Range");
			}

			set
			{
				Node? currentNode = Header;

				int NodeIndex = 0;
				while (currentNode != null && NodeIndex < Count)
				{
					if (Index == NodeIndex)
					{
						currentNode.Data = value;
						return;
					}
					NodeIndex += 1;
					currentNode = currentNode.Next;
				}

				throw new IndexOutOfRangeException("Index Out of Range");
			}
		}

		public void AskQuestion()
		{
			SingleLinkedList linkedList = new();
			while (true)
			{
				Console.WriteLine("Enter the choice: ");
				string? choice = Console.ReadLine();
				if (choice == "addbeg")
				{
					linkedList.AddBegin();
				}
				else if (choice == "addmid")
				{
					linkedList.AddMiddle();
				}
				else if (choice == "addend")
				{
					linkedList.AddEnd(null);
				}
				else if (choice == "dis")
				{
					linkedList.Display();
				}
				else if (choice == "upin")
				{
					linkedList.UpdateIndex();
				}
				else if (choice == "upva")
				{
					linkedList.UpdateValue();
				}
				else if (choice == "remf")
				{
					linkedList.RemoveFirst();
				}
				else if (choice == "remm")
				{
					linkedList.RemoveMiddle();
				}
				else if (choice == "reml")
				{
					linkedList.RemoveLast();
				}
				else if (choice == "len")
				{
					Console.WriteLine($"Length: {linkedList.Count}");
				}
				else if (choice == "con")
				{
					if (linkedList.Contains(null))
					{
						Console.WriteLine("Value Found...");
					}
					else
					{
						Console.WriteLine("Value Not Found...");
					}
				}
				else if (choice == "find")
				{
					Console.WriteLine($"Index: {linkedList.FindIndex()}");
				}
				else if (choice == "getval")
				{
					Console.WriteLine("Enter the Index: ");
					Console.WriteLine(linkedList[Convert.ToInt32(Console.ReadLine())]);
				}
				else if (choice == "sort")
				{
					linkedList.Sort();
				}
				else if (choice == "exit")
				{
					break;
				}
				else
				{
					Console.WriteLine("Enter the correct choice");
				}
			}
		}
	}
}