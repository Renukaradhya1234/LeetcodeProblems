using Newtonsoft.Json.Linq;
using System.IO;
using System.Windows;
using System.Windows.Automation;

namespace JsonWriterNamespace
{
    public class JsonWriterClass
    {
        public bool WriteJson(AutomationElementCollection allElements, string fileName)
        {
            JArray jsonArray = new JArray();

            try
            {
                foreach (AutomationElement element in allElements)
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

                File.WriteAllText(fileName, jsonArray.ToString());
                return true;
            }
            catch (Exception error)
            {
                Console.WriteLine($"Some error: {error}...");
                return false;
            }
        }
    }
}