using System;
using System.IO;
using System.Text;
using Newtonsoft.Json.Linq; // rigth click on Project name, -> Manage NuGet Package -> search (Newtonsoft.Json.Linq) -> download(Remote.Linq.Newtonsoft.Json)
using System.Windows.Automation;
using System.Windows;
using System.Diagnostics;

namespace CaptureAutomationElement.Component
{
    class JsonWriter
    {
        // method to write the json file...
        public  bool MyJsonWriter(AutomationElementCollection elements, Process filenameProcess)
        {
            JArray jsonArray = new JArray(); //to store Json object in array

            // to collect all the boundRect...
            foreach (AutomationElement element in elements)
            {
                try
                {
                    if (element != null)
                    {
                        Rect boundingRect = element.Current.BoundingRectangle; // getting the element Bounding Rect

                        JObject jsonObject = new JObject(); // to store data in json object
                        jsonObject["name"] = element.Current.Name;
                        jsonObject["height"] = boundingRect.Height;
                        jsonObject["width"] = boundingRect.Width;
                        jsonObject["left"] = boundingRect.Left;
                        jsonObject["top"] = boundingRect.Top;

                        jsonArray.Add(jsonObject);
                    }
                }
                catch (ElementNotAvailableException ex)
                {
                    Console.WriteLine($"Error: Element is not available. {ex.Message}");
                    // some times element disappear before we access the element
                }
            }
            Console.WriteLine($"from jsonWriter length: {jsonArray.Count}");
            try
            {
                // Step 4: Write the JArray as a JSON string to the file
                File.WriteAllText($@"C:\Users\Admin\Desktop\practice\company_program_dotnet\Automation_Element\CaptureAutomationElement\react\src\images\{filenameProcess.ProcessName}{filenameProcess.Handle}.json", jsonArray.ToString(), Encoding.UTF8);

                Console.WriteLine("JSON data has been written to the file.");
                return true;
            }
            catch (IOException e)
            {
                Console.WriteLine("An error occurred while writing the JSON file: " + e.Message);
                return false;
            }
        }
        public void MyJsonWriter()
        {
            Console.WriteLine(" This from json wirter..");

        }
    }
}
