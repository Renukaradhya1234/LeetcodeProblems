using System;
using System.Runtime.InteropServices;
using System.Windows.Automation; // right click on References, then add Presentation Core property.
using CaptureAutomationElement.Component;
using System.Diagnostics; // add System in references.

namespace CaptureAutomationElement
{
    internal class Program
    {
        // Import the GetForegroundWindow function from user32.dll
        [DllImport("user32.dll")]
        public static extern IntPtr GetForegroundWindow(); // this function return the activate window handle

        // import GetWindowThreadProcessId to get process object, it gives the process id by taking handle...
        [DllImport("user32.dll")]
        public static extern int GetWindowThreadProcessId(IntPtr hWnd, out int ProcessId);// this function return the processid, by taking the handle
        
        
        static void Main(string[] args)
        {
            // Assuming there is no activeWindow
            IntPtr previous = IntPtr.Zero;

            JsonWriter js = new JsonWriter(); // creating an object for JsonWriter class

            CaptureScreen cs = new CaptureScreen(); // creating an object for CaptureScreen class 

            int processId = 0;

            while (true)
            {
                // to get activate window...
                IntPtr foregroundWindowHandle = GetForegroundWindow();

                if (foregroundWindowHandle != IntPtr.Zero && foregroundWindowHandle != previous)
                {
                    long startTime = DateTime.Now.Ticks; //staring time

                    previous = foregroundWindowHandle;
                    AutomationElement rootElement = AutomationElement.FromHandle(foregroundWindowHandle); //this will get the root element of the window
                    // for AutomationElement class : add UIAutomationClient in references

                    GetWindowThreadProcessId(foregroundWindowHandle, out processId); 

                    Process process = Process.GetProcessById(processId); // getting the process object by using process id
                    // for Process class : add System in references

                    if (rootElement != null)
                    {
                        Console.WriteLine("Found AutomationElement for the foreground window:");
                        Console.WriteLine("Name: " + rootElement.Current.Name);

                        AutomationElementCollection children = rootElement.FindAll(TreeScope.Descendants, Condition.TrueCondition);// collecting all the UIElement by using root element
                        // TreeScope.Descendants means accessing the children , grant children and great grant children and so on except the parent element
                        // Condition.TrueCondition means true for all the element.

                        Console.WriteLine($"Number of last Children: {children.Count}");


                        if (js.MyJsonWriter(children, process))
                        {
                            Console.WriteLine("json written successfully...");
                        }
                        else
                        {
                            Console.WriteLine("json error..............");
                        }
                        Console.WriteLine("");
                        Console.WriteLine("----------------------------------------");
                    }
                    else
                    {
                        Console.WriteLine("No AutomationElement found for the given handle.");
                    }

                    if (cs.CaptureScreenShot(foregroundWindowHandle, process))
                    {
                        Console.WriteLine("Image taken sucessfully...");
                    }
                    else
                    {
                        Console.WriteLine("failed to take image...");
                    }

                    long endTime = DateTime.Now.Ticks; // time ends. 

                    Console.WriteLine($"Time span for {process.ProcessName}: {(endTime - startTime) / 10000}");

                }
            }
        }
    }
}
