using System.Diagnostics;
using System.Runtime.InteropServices;

namespace myNamespace
{
	internal class Program
	{

		[DllImport("C:\\Users\\Admin\\Desktop\\practice\\git_programs\\program-inventys-company\\csharp\\addmydll\\cppCode\\myFirstDll.dll")]
		private extern static void PrintNumber();

		static void Main()
		{
			Stopwatch watch = new Stopwatch();

			watch.Start();

			PrintNumber();

			watch.Stop();
			TimeSpan dllTime = watch.Elapsed;

			watch.Reset();

			watch.Start();
			for (int num1 = 0; num1 < 10; num1++)
			{
				Console.WriteLine(num1);
			}
			watch.Stop();

			TimeSpan dotnetTime = watch.Elapsed;

			Console.WriteLine($"dll: {dllTime} dotnet: {dotnetTime}");

			if (dotnetTime.CompareTo(dllTime) < 0)
			{
				Console.WriteLine("dotnet is faster...");
			}
			else
			{
				Console.WriteLine("dll is faster...");
			}
		}
	}
}