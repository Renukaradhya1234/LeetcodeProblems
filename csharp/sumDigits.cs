using System;

namespace SumOfDigits
{
    public class HelloWorld
    {
        public static void Main(string[] args)
        {   
           // WAP to print sum of the digits in given string
            Console.WriteLine("Enter the number");
            int input = Convert.ToInt32(Console.ReadLine());
            int output = 0;

             while (input > 0)
              {
                   output += input % 10 ;
                   input /= 10;
              }
              Console.WriteLine($"sum of the digits is: { output }");
        }
    }
}