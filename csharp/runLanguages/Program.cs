using System;
using System.Diagnostics;

// Learning about ProcessStartInfo class...
namespace Practice
{
    class ProcessStart
    {
        public void startProcess(string fileName, string path)
        {
            // creating instance of the ProcessStartInfo class
            ProcessStartInfo processInfo = new ProcessStartInfo
            {
                FileName = fileName, // it decide which compiler to use Ex: if FileName = "python" it use python complier
                Arguments = path, // file full path
                RedirectStandardOutput = true, // to redirect the output printed from that file
                RedirectStandardError = true, // to redirect the error printed from that file
                UseShellExecute = false, // avoid use of the system command prompt
            };
            // creating the instance of the Process class
            Process processStart = new Process
            {
                StartInfo = processInfo,
            };

            // collecting the output printed from that file
            processStart.OutputDataReceived += (sender, result) =>
            {
                Console.WriteLine(result.Data); // printing the output 
            };

            // collecting the error thrown from that file
            processStart.ErrorDataReceived += (sender, errorResult) =>
            {
                Console.WriteLine("Error: " + errorResult.Data); // Print error data
            };


            processStart.Start(); // excuting the file 
            processStart.WaitForExit(); // waiting untill the excution of that file complete

            processStart.BeginOutputReadLine(); // this method is responseable to trigger the OutputDataReceived property..
            processStart.BeginErrorReadLine(); // this method is responseable to trigger the ErrorDataReceived property
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ProcessStart process = new ProcessStart();

            // python program
            process.startProcess("python", "C:\\Users\\Admin\\Desktop\\practice\\dotnet2\\python.py");

            // JavaScript program
            process.startProcess("node", "C:\\Users\\Admin\\Desktop\\practice\\dotnet2\\javascripts.js");
            Console.ReadKey();
        }
    }
}
