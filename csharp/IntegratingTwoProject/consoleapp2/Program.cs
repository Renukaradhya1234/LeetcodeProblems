// commands are used is:
// In MySolution folder - dotnet new sln --name "MySolution"

// In MySolution folder - dotnet new console --name "consoleapp1"
// In MySolution folder - dotnet new console --name "consoleapp2"

// In MySolution folder - dotnet sln add ./consoleapp1/consoleapp1.csproj
// In MySolution folder - dotnet sln add ./consoleapp2/consoleapp2.csproj

// In consoleapp2 - consoleapp2.csproj - <PropertyGroup> <OutputType>Library</OutputType> <PropertyGroup>
// In consoleapp1 - consoleapp1.csproj - <ItemGroup> <ProjectReference Include = "..\consoleapp1" /> </ItemGroup>


namespace MyNamespace 
{
	public class Program
	{
		public void MyMethod()
		{
			Console.WriteLine("this is from consoleapp2...");
		}
		static void Main()
		{
			Console.WriteLine("Hello world");
		}
	}
}
