using System;
using System.Collections.Generic;

namespace MyCollection
{
    class myList
    {
        public void MyListMethod<Datatype>()
        {
            Console.WriteLine($"I am from myListMethod...{typeof(Datatype)}");

            List<Datatype> myList = new List<Datatype>();

            while (true)
            {
                Console.WriteLine($"Enter the {typeof(Datatype)} value: ");
                string? input = Console.ReadLine();
                if (input == "exit()")
                {
                    break;
                }
                Datatype? inputValue = (Datatype?)Convert.ChangeType(input, typeof(Datatype));

                if(inputValue != null)
                {
                    myList.Add(inputValue);
                }
            }

            Console.WriteLine("You entered values are: ");
            foreach (Datatype value in myList)
            {
                Console.WriteLine(value);
            }
        }

        public void myDictMethod<datatype_key, datatype_value>()
        {
            Console.WriteLine($"I am from myDictMethod... key: {typeof(datatype_key)}, value: {typeof(datatype_value)}");
            Dictionary<datatype_key, datatype_value> myDict = new Dictionary<datatype_key, datatype_value>();

            while (true)
            {
                Console.WriteLine($"Enter the key: {typeof(datatype_key)}");
                string? input = Console.ReadLine();

                if (input == "exit()")
                {
                    break;
                }

                datatype_key? inputKey = (datatype_key?)Convert.ChangeType(input, typeof(datatype_key));

                Console.WriteLine($"Enter the value: {typeof(datatype_value)}");
                datatype_value? inputValue = (datatype_value?)Convert.ChangeType(Console.ReadLine(), typeof(datatype_value));

                if(inputKey != null && inputValue != null)
                {
                    myDict.Add(inputKey, inputValue);
                }

            }

            Console.WriteLine("value and key in dictionary...");
            foreach (datatype_key key in myDict.Keys)
            {
                Console.WriteLine($"key: {key}  value: {myDict[key]}");
            }
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            myList list = new myList();
            Console.WriteLine($"this object: {list}");

            Console.WriteLine("Enter the list or Dictionary option..");
            Console.WriteLine("1. List.. \n2. Dictionary..");

            char? listDictChoice = Convert.ToChar(Console.ReadLine() ?? "");

            if (listDictChoice == '1')
            {
                Dictionary<char, Type> listUserChoice = new Dictionary<char, Type>
                {
                    { '1', typeof(int) },
                    { '2', typeof(double) },
                    { '3', typeof(char) },
                    { '4', typeof(string) }
                };

                foreach (char c in listUserChoice.Keys)
                {
                    Console.WriteLine($"key: {c}  value: {listUserChoice[c]}");
                }

                Console.WriteLine("Enter your choices: ");

                list.GetType().GetMethod("MyListMethod").MakeGenericMethod(listUserChoice[Convert.ToChar(Console.ReadLine() ?? "")]).Invoke(list, null);
            }
            else if (listDictChoice == '2')
            {
                Dictionary<char, Type> dictUserChoice = new Dictionary<char, Type>
                {
                    { '1', typeof(int) },
                    { '2', typeof(double) },
                    { '3', typeof(char) },
                    { '4', typeof(string) }
                };

                foreach (char dict_key in dictUserChoice.Keys)
                {
                    Console.WriteLine($"key: {dict_key}  value: {dictUserChoice[dict_key]}");
                }

                Console.WriteLine("Enter your key choices: ");
                Type key_value = dictUserChoice[Convert.ToChar(Console.ReadLine() ?? "")];

                Console.WriteLine("Enter your value choices: ");
                Type value_value = dictUserChoice[Convert.ToChar(Console.ReadLine() ?? "")];

                list.GetType().GetMethod("myDictMethod").MakeGenericMethod(key_value, value_value).Invoke(list, null);
            }
            Console.ReadKey();
        }
    }
}
