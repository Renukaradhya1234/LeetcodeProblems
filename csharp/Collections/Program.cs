using System;
using System.Collections.Generic;

namespace MyCollection
{
    class myList
    {
        public void MyListMethod<datatype>()
        {
            Console.WriteLine($"I am from myListMethod...{typeof(datatype)}");

            List<datatype> myList = new List<datatype>();

            while (true)
            {
                Console.WriteLine($"Enter the {typeof(datatype)} value: ");
                string input = Console.ReadLine();
                if (input == "exit()")
                {
                    break;
                }
                datatype inputValue = (datatype)Convert.ChangeType(input, typeof(datatype));

                myList.Add(inputValue);
            }

            Console.WriteLine("You entered values are: ");
            foreach (datatype value in myList)
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
                string input = Console.ReadLine();

                if (input == "exit()")
                {
                    break;
                }

                datatype_key inputKey = (datatype_key)Convert.ChangeType(input, typeof(datatype_key));

                Console.WriteLine($"Enter the value: {typeof(datatype_value)}");
                datatype_value inputValue = (datatype_value)Convert.ChangeType(Console.ReadLine(), typeof(datatype_value));

                myDict.Add(inputKey, inputValue);

            }

            Console.WriteLine("value and key in dictionary...");
            foreach (datatype_key key in myDict.Keys)
            {
                Console.WriteLine($"key: {key}  value: {myDict[key]}");
            }
        }

        public void myObjectMethod()
        {
            List<object> myListObject = new List<object>();

            while (true)
            {
                Console.WriteLine($"Enter the value: ");

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

            char listDictChoice = Convert.ToChar(Console.ReadLine());

            if (listDictChoice == '1')
            {
                Dictionary<char, Type> listUserChoice = new Dictionary<char, Type>();

                listUserChoice.Add('1', typeof(int));
                listUserChoice.Add('2', typeof(double));
                listUserChoice.Add('3', typeof(char));
                listUserChoice.Add('4', typeof(string));

                foreach (char c in listUserChoice.Keys)
                {
                    Console.WriteLine($"key: {c}  value: {listUserChoice[c]}");
                }

                Console.WriteLine("Enter your choices: ");

                list.GetType().GetMethod("MyListMethod").MakeGenericMethod(listUserChoice[Convert.ToChar(Console.ReadLine())]).Invoke(list, null);
            }
            else if (listDictChoice == '2')
            {
                Dictionary<char, Type> dictUserChoice = new Dictionary<char, Type>();

                dictUserChoice.Add('1', typeof(int));
                dictUserChoice.Add('2', typeof(double));
                dictUserChoice.Add('3', typeof(char));
                dictUserChoice.Add('4', typeof(string));

                foreach (char dict_key in dictUserChoice.Keys)
                {
                    Console.WriteLine($"key: {dict_key}  value: {dictUserChoice[dict_key]}");
                }

                Console.WriteLine("Enter your key choices: ");
                Type key_value = dictUserChoice[Convert.ToChar(Console.ReadLine())];

                Console.WriteLine("Enter your value choices: ");
                Type value_value = dictUserChoice[Convert.ToChar(Console.ReadLine())];

                list.GetType().GetMethod("myDictMethod").MakeGenericMethod(key_value, value_value).Invoke(list, null);
            }
            Console.ReadKey();
        }
    }
}
