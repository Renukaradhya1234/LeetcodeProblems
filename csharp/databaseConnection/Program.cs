// commands
// dotnet new console --name "projectName" // to create a project
// dotnet add package System.Data.SQLite // to add the sqlite package to project


using DatabaseMethods;
using System.Data.SQLite;
using System.Text;

namespace MyNamespace
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine($"Program started");

			string databaseName = "myDatabase.db"; // name of the database

			// object to ConnectionMethod class
			ConnectionMethod cm = new ConnectionMethod();

			// to connect with the database.
			SQLiteConnection connection = cm.MyConnection(databaseName, true);

			// table name
			Console.WriteLine("Enter the table name");
			string tableName = Console.ReadLine();

			Console.WriteLine("Enter the number of attribue:");
			int number = Convert.ToInt32(Console.ReadLine());

			string[] attributes = new string[number];
			string[] dataType = new string[number];

			for (int a = 0; a < number; a++)
			{
				Console.WriteLine($"Enter the column name ");
				attributes[a] = Console.ReadLine();

				Console.WriteLine($"Enter the datatype");
				dataType[a] = Console.ReadLine();
			}

			Console.WriteLine("Entered value: ");
			for (int index = 0; index < attributes.Length; index++)
			{
				Console.WriteLine($"column name: {attributes[index]} datatype: {dataType[index]} ");
			}

			StringBuilder createTable = new StringBuilder();
			createTable.Append($"create table {tableName} (");
			for (int index = 0; index < attributes.Length; index++)
			{
				createTable.Append($"{attributes[index]} {dataType[index]}");
				if (index != attributes.Length - 1)
				{
					createTable.Append(", ");
				}
				if (index == attributes.Length - 1)
				{
					createTable.Append(");");
				}
			}

			if (cm.CreateTable(connection, createTable.ToString()))
			{
				Console.WriteLine("table created successfully...");
			}
			else
			{
				Console.WriteLine("failed to create table...");
			}

			while (true)
			{
				Console.WriteLine("type 'add' to added the value\n" +
								  "type 'read' to view\n" +
								  "type 'update to update the value\n" +
								  "type 'delete' to delete the record\n" +
								  "type 'exit' to exit ");

				string userInput = Console.ReadLine();

				if (userInput == "exit")
				{
					break;
				}
				else if (userInput == "add")
				{
					// string buffer to store the user, entered values
					StringBuilder addString = new StringBuilder();
					addString.Append($"insert into {tableName} values (");
					for (int a = 0; a < number; a++)
					{
						Console.WriteLine($"Enter value ");
						addString.Append(Console.ReadLine());
						if (a != number - 1)
						{
							addString.Append(", ");
						}
						if (a == number - 1)
						{
							addString.Append(");");
						}
					}
					Console.WriteLine(addString.ToString());

					if (cm.InsertData(connection, addString.ToString()))
					{
						Console.WriteLine("data inserted successfully...");
					}
					else
					{
						Console.WriteLine("failed to insert the data...");
					}
				}
				else if (userInput == "update")
				{
					Console.WriteLine("Enter the query to update");
					string query = Console.ReadLine();

					if (cm.UpdateData(connection, query))
					{
						Console.WriteLine("data updated successfully...");
					}
					else
					{
						Console.WriteLine("failed to update the data");
					}
				}
				else if (userInput == "delete")
				{
					Console.WriteLine("Enter the query to delete");
					string query = Console.ReadLine();

					if (cm.DeleteData(connection, query))
					{
						Console.WriteLine("data deleted successfully...");
					}
					else
					{
						Console.WriteLine("failed to deleted the data");
					}
				}
				else if (userInput == "read")
				{
					cm.ReadData(connection, $"select * from {tableName}");
				}
				else
				{
					Console.WriteLine("Enter the correct choice");
				}


			}

			Console.WriteLine("Program ended");
		}
	}
}