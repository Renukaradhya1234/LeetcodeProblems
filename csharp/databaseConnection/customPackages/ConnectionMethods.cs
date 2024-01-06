using System;
using System.Data.SQLite;

namespace DatabaseMethods
{
	class ConnectionMethod
	{
		// to connect with the database
		public SQLiteConnection MyConnection(string databaseName, bool createNewFile)
		{
			if (createNewFile)
			{
				SQLiteConnection.CreateFile(databaseName); // creating the database file if not exist
			}

			// connecting with the database using SQLiteConnection class
			SQLiteConnection connection = new SQLiteConnection($"Data Source = {databaseName}; Version = 3");
			return connection;
		}

		// to create the table in database
		public bool CreateTable(SQLiteConnection connection, string data){
			try{
				connection.Open();

				using(SQLiteCommand command = new SQLiteCommand(data, connection)){
					command.ExecuteNonQuery();
					connection.Close();
					return true;
				}
			} catch (Exception error){
				Console.WriteLine($"error: {error}");
				connection.Close();
				return false;
			}
		}

		// to insert the data to the table
		public bool InsertData(SQLiteConnection connection, string data)
		{
			try
			{
				connection.Open(); //Accessing the database file

				using (SQLiteCommand command = new SQLiteCommand(data, connection)) // giving the command to insert the data
				{
					command.ExecuteNonQuery(); // data will insert by this method
					connection.Close(); // closing the database file
					return true;
				}
			}
			catch (Exception error)
			{
				Console.WriteLine($"Something wrong: {error}");
				connection.Close();
				return false;
			}
		}

		public bool UpdateData(SQLiteConnection connection, string data)
		{
			try
			{
				connection.Open();

				using (SQLiteCommand command = new SQLiteCommand(data, connection))
				{
					command.ExecuteNonQuery();
					connection.Close();
					return true;
				}
			}
			catch (Exception error)
			{
				Console.WriteLine($"Some error: {error}");
				connection.Close();
				return false;
			}
		}

		public bool DeleteData(SQLiteConnection connection, string data)
		{
			try
			{
				connection.Open();

				using (SQLiteCommand command = new SQLiteCommand(data, connection))
				{
					command.ExecuteNonQuery();
					connection.Close();
					return true;
				}
			}
			catch (Exception error)
			{
				Console.WriteLine($"Some error: {error}");
				connection.Close();
				return false;
			}
		}

		public void ReadData(SQLiteConnection connection, string data)
		{
			try
			{
				connection.Open();

				using (SQLiteCommand command = new SQLiteCommand(data, connection))
				{
					using (SQLiteDataReader reader = command.ExecuteReader())
					{
						while (reader.Read())
						{
							Console.WriteLine($"sname: {reader.GetString(1)} age: {reader.GetInt32(2)}");
						}
					}
				}
			}
			catch (Exception error)
			{
				Console.WriteLine($"Some Error: {error}");
			}
			finally
			{
				connection.Close();
			}
		}
	}
}