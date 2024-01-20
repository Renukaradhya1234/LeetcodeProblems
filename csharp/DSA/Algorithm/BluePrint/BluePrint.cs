namespace BaseNamespace
{
	interface IBluePrint
	{

		int Count { get; set; } // to get the length of the list
		
		
		void AddBegin(); // to add the value to beginning
		void AddMiddle(); // to add the value to middle of list
		void AddEnd(); // to add the value at the end of list


		void Display(); // to display the values present in list
		
		
		void UpdateIndex(); // to update the value by using index
		void UpdateValue(); // to update the old value by new value
		
		
		void RemoveFirst(); // to remove the first value
		void RemoveMiddle(); // to remove the middle value using index
		void RemoveLast(); // to remove the last value
		
		
		bool Contains(); // to check value present or not
		int FindIndex(); // to find the value
	}
}