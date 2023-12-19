using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Automation; // add the package Microsoft.Windows.Compatibility with version 5.0.2

// my custome namespace
using CaptureScreenNamespace;
using JsonWriterNamespace;

namespace MyNamespace
{
    internal class Program
    {
        //  Window Operating System function to know the active window.
        [DllImport("user32.dll")]
        public static extern IntPtr GetForegroundWindow();

        static void Main()
        {
            Console.WriteLine("Program started...");
            
            Stopwatch watch = new Stopwatch();
            watch.Start();

            // GetForegroundWindow function return handle attribute value which belongs to Inptr class
            IntPtr activeWindow = GetForegroundWindow();

            // get the root element from the window
            AutomationElement rootElement = AutomationElement.FromHandle(activeWindow);

            CaptureScreenClass captureScreen = new CaptureScreenClass();
            if (captureScreen.CaputureScreen(activeWindow, "screenshot.jpeg"))
            {
                Console.WriteLine("Screenshot taken successfully....");
            }
            else
            {
                Console.WriteLine("Failed to take screenshot");
            }

            Condition condition1 = new PropertyCondition(AutomationElement.IsOffscreenProperty, false);
            Condition condition2 = new PropertyCondition(AutomationElement.IsEnabledProperty, true);

            AutomationElementCollection allElement = rootElement.FindAll(TreeScope.Descendants, new AndCondition(condition1, condition2));

            Console.WriteLine($"found elements : {allElement.Count}");

            JsonWriterClass jsonWriter = new JsonWriterClass();
            if (jsonWriter.WriteJson(allElement, "elementList.json"))
            {
                Console.WriteLine("json written successfully....");
            }
            else
            {
                Console.WriteLine("Failed to write json...");
            }

            watch.Stop();

            TimeSpan ts = watch.Elapsed;

            Console.WriteLine($"Time Taken: {ts.Minutes}min {ts.Seconds}s {ts.Milliseconds/10}ms");

            Console.WriteLine("Program ended...");
        }
    }
}