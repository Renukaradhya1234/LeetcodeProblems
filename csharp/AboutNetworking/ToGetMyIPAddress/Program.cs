using System;
using System.Net;

class Program
{
    static void Main()
    {
        string domainName = Dns.GetHostName(); // Replace with the domain you want to look up
        IPAddress[] ipAddresses = Dns.GetHostAddresses(domainName);

        if (ipAddresses.Length > 0)
        {
            Console.WriteLine($"IP addresses for {domainName}:");
            foreach (IPAddress ipAddress in ipAddresses)
            {
                Console.WriteLine(ipAddress.ToString());
            }
        }
        else
        {
            Console.WriteLine($"No IP addresses found for {domainName}");
        }
    }
}
