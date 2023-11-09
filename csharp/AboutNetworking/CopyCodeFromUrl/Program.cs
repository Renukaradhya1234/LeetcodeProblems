using System.Net;

class Program
{
    static void Main()
    {
        // Create a WebClient instance.
        WebClient webClient = new WebClient();
        

        try
        {
            // Specify the URL of the web page you want to download.
            string url = "https://www.w3schools.com/";

            // Download the content of the web page as a string.
            string pageContent = webClient.DownloadString(url);

            // Display the content in the console.
            Console.WriteLine("Content of the web page:");
            //Console.WriteLine(pageContent);

            File.WriteAllText("D:\\dotnet\\content.html", pageContent);
            Console.WriteLine("File written successfully...");
        }
        catch (WebException ex)
        {
            Console.WriteLine("An error occurred: " + ex.Message);
        }
    }
}

