using System;

namespace XelomPheleom
{
    public class HelloWorld
    {
        //WAP to print the given number is xeleom number or pheleom number
        private static bool isXeleom(string input)
        {
            int outer = Convert.ToInt32(input[0].ToString()) + Convert.ToInt32(input[input.Length - 1].ToString());
            Console.WriteLine($"outer: {outer}");

            int inner = 0;
            for (int index = 1; index <= input.Length - 2; index++)
            {
                inner += Convert.ToInt32(input[index].ToString());
            }
            Console.WriteLine($"inner: {inner}");
            return inner == outer;
        }
        public static void Main(string[] args)
        {
            Console.WriteLine("Enter the number...");
            string str = Console.ReadLine();
            if (isXeleom(str))
            {
                Console.WriteLine("Given number is xeleom...");
            }
            else
            {
                Console.WriteLine("Given number is pheleom...");
            }
        }
    }
}
