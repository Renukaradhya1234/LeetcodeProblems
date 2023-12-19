using System.Text;
using Newtonsoft.Json.Linq;

namespace MyNamespace
{
	class Program
	{
		private static void SendMessageToExtension()
		{
			string data = new JObject { { "from", "from Native Host" } }.ToString();

			byte[] responseBytes = Encoding.UTF8.GetBytes(data);
			byte[] length = BitConverter.GetBytes(responseBytes.Length);

			Console.OpenStandardOutput().Write(length);
			Console.OpenStandardOutput().Write(responseBytes);
		}

		private static string ReceiveMessageFromExtension()
		{
			byte[] receivingLength = new byte[4];
			Console.OpenStandardInput().Read(receivingLength);
			int messagLength = BitConverter.ToInt32(receivingLength);

			byte[] receivedMessage = new byte[messagLength];
			Console.OpenStandardInput().Read(receivedMessage);

			string? receivedData = Encoding.UTF8.GetString(receivedMessage);
			return receivedData ?? "";
		}

		static void Main()
		{
			try
			{
				string fileName = "sample.txt";
				File.AppendAllText(fileName, "native host running");

				SendMessageToExtension();

				while (true)
				{
					string readData = ReceiveMessageFromExtension();

					File.AppendAllText(fileName, readData);

					JObject? receivedMessage = JObject.Parse(readData);

					File.WriteAllText(fileName, (string?)receivedMessage["from"]);
				}
			}
			catch (Exception error)
			{
				string fileName = "sample.txt";
				File.AppendAllText(fileName, $"{error}");
			}
		}
	}
}