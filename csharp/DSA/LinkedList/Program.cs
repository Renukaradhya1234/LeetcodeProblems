using System;
using single_linked_list;
using DSA.DoubleLinkedList;

namespace DataStructure
{
    public class Program
    {
        static void Main(string[] arguments)
        {
            while (true)
            {
                Console.WriteLine("type 'single' for single linked list\n" +
                    "type 'double' for double linked list\n" +
                    "type 'stack' for stack\n" +
                    "type 'queue' for queue\n" +
                    "type 'quit' for exit for linked list");

                string linked_choice = Console.ReadLine();

                if (linked_choice == "single")
                {
                    SingleLinked singleLinked = new();
                    while (true)
                    {
                        Console.WriteLine("type 'add' for add value\n" +
                            "Type 'addbeg' for add value to beginning\n" +
                            "type 'remove' for remove value\n" +
                            "type 'display' for display values\n" +
                            "type 'length' for display length list\n" +
                            "type 'updateval' for update value\n" +
                            "type 'updateindex' for update from index\n" +
                            "type 'remindex' for remove index\n" +
                            "type 'exit' for exit\n");
                        Console.WriteLine("Enter your choice...");
                        string userInput = Console.ReadLine();

                        if (userInput == "add")
                        {
                            Console.WriteLine("Enter the value");
                            singleLinked.Add(int.Parse(Console.ReadLine()));
                        }
                        else if (userInput == "addbeg")
                        {
                            Console.WriteLine("Enter the value");
                            singleLinked.Add_Begin(int.Parse(Console.ReadLine()));
                        }
                        else if (userInput == "display")
                        {
                            singleLinked.Display();
                        }
                        else if (userInput == "remove")
                        {
                            Console.WriteLine($"removed value: {singleLinked.Remove()}");
                        }
                        else if (userInput == "length")
                        {
                            Console.WriteLine($"Length of the list node: {singleLinked.List_length()}");
                        }
                        else if (userInput == "updateval")
                        {
                            Console.WriteLine("Enter the old value...");
                            int oldvalue = Convert.ToInt32(Console.ReadLine().ToString());

                            Console.WriteLine("Enter the new value...");
                            int newValue = Convert.ToInt32(Console.ReadLine().ToString());

                            singleLinked.Update_value(oldvalue, newValue);
                        }
                        else if (userInput == "updateindex")
                        {
                            Console.WriteLine("Enter the index...");
                            int index = Convert.ToInt32(Console.ReadLine().ToString());

                            Console.WriteLine("Enter the new value...");
                            int newValue = Convert.ToInt32(Console.ReadLine().ToString());

                            singleLinked.Update_index(index, newValue);
                        }
                        else if (userInput == "remindex")
                        {
                            Console.WriteLine("Enter the index...");
                            int index = Convert.ToInt32(Console.ReadLine());

                            Console.WriteLine($"removed value: {singleLinked.Remove_index(index)}");
                        }
                        else if (userInput == "exit")
                        {
                            break;
                        }
                    }
                }
                else if (linked_choice == "double")
                {
                    DoubleLinkedList ddl = new();

                    while (true)
                    {
                        Console.WriteLine("type 'add' for add value\n" +
                        "Type 'addbeg' for add value to beginning\n" +
                        "type 'remove' for remove value\n" +
                        "type 'display' for display values\n" +
                        "type 'length' for display length list\n" +
                        "type 'updateval' for update value\n" +
                        "type 'remindex' for remove index\n" +
                        "type 'exit' for exit\n");
                        Console.WriteLine("Enter your choice...");
                        string userInput = Console.ReadLine();
                        if (userInput == "add")
                        {
                            ddl.Add();
                        }
                        else if (userInput == "addbeg")
                        {
                            ddl.AddBegin();
                        }
                        else if (userInput == "display")
                        {
                            ddl.Display();
                        }
                        else if (userInput == "remove")
                        {
                            ddl.Remove_value();
                        }
                        else if (userInput == "remindex")
                        {
                            ddl.RemoveIndex("");
                        }
                        else if (userInput == "length")
                        {
                            Console.WriteLine($"the length of list: {ddl.Length()}");
                        }
                        else if (userInput == "updateval")
                        {
                            ddl.Update();
                        }
                        else if (userInput == "exit")
                        {
                            break;
                        }

                    }
                }
                else if (linked_choice == "stack")
                {
                    Console.WriteLine("type 'single' for single linked list\n" +
                        "type 'double' for double linked list\n");
                    string single_double_stack = Console.ReadLine();

                    if (single_double_stack == "single")
                    {
                        SingleLinked single = new();

                        while (true)
                        {
                            Console.WriteLine("Type 'add' to add\n" +
                            "Type 'remove' to remove\n" +
                            "Type 'length' for length of stack\n" +
                            "Type 'display' for display values\n" +
                            "Type 'quit' to quit");

                            String stack_userinput = Console.ReadLine();

                            if (stack_userinput == "add")
                            {
                                Console.WriteLine("Enter the value...");
                                single.Add(Convert.ToInt32(Console.ReadLine()));
                            }
                            else if (stack_userinput == "remove")
                            {
                                Console.WriteLine($"Removed value: {single.Remove()}");
                            }
                            else if (stack_userinput == "length")
                            {
                                Console.WriteLine($"Stack Length: {single.List_length()}");
                            }
                            else if (stack_userinput == "display")
                            {
                                single.Display();
                            }
                            else if (stack_userinput == "quit")
                            {
                                break;
                            }
                        }
                    }
                    else if (single_double_stack == "double")
                    {
                        DoubleLinkedList dll = new DoubleLinkedList();
                        while (true)
                        {
                            Console.WriteLine("Type 'add' to add\n" +
                            "Type 'remove' to remove\n" +
                            "Type 'length' for length of stack\n" +
                            "Type 'display' for display values\n" +
                            "Type 'quit' to quit");

                            String stack_userinput = Console.ReadLine();

                            if (stack_userinput == "add")
                            {
                                dll.Add();
                            }
                            else if (stack_userinput == "remove")
                            {
                                Console.WriteLine($"Removed value: {dll.RemoveLast()}");
                            }
                            else if (stack_userinput == "length")
                            {
                                Console.WriteLine($"Stack Length: {dll.Length()}");
                            }
                            else if (stack_userinput == "display")
                            {
                                dll.Display();
                            }
                            else if (stack_userinput == "quit")
                            {
                                break;
                            }
                        }

                    }
                }
                else if (linked_choice == "queue")
                {
                    Console.WriteLine("Enter the 'single' for single linked list" +
                        "Enter the 'double' for double linked list");

                    string single_double_queue = Console.ReadLine();

                    if (single_double_queue == "single")
                    {
                        SingleLinked single = new();

                        while (true)
                        {
                            Console.WriteLine("Type 'add' to add\n" +
                            "Type 'remove' to remove\n" +
                            "Type 'length' for length of queue\n" +
                            "Type 'display' for display values\n" +
                            "Type 'quit' to quit");

                            string queue_userinput = Console.ReadLine();

                            if (queue_userinput == "add")
                            {
                                Console.WriteLine("Enter the value...");
                                single.Add(Convert.ToInt32(Console.ReadLine()));
                            }
                            else if (queue_userinput == "remove")
                            {
                                Console.WriteLine($"Removed value: {single.Remove_index(0)}");
                            }
                            else if (queue_userinput == "length")
                            {
                                Console.WriteLine($"Queue Length: {single.List_length()}");
                            }
                            else if (queue_userinput == "display")
                            {
                                single.Display();
                            }
                            else if (queue_userinput == "quit")
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        DoubleLinkedList dll = new DoubleLinkedList();
                        while (true)
                        {
                            Console.WriteLine("Type 'add' to add\n" +
                            "Type 'remove' to remove\n" +
                            "Type 'length' for length of queue\n" +
                            "Type 'display' for display values\n" +
                            "Type 'quit' to quit");

                            string queue_userinput = Console.ReadLine();

                            if (queue_userinput == "add")
                            {
                                dll.Add();
                            }
                            else if (queue_userinput == "remove")
                            {
                                dll.RemoveIndex("queue");
                            }
                            else if (queue_userinput == "length")
                            {
                                Console.WriteLine($"Queue Length: {dll.Length()}");
                            }
                            else if (queue_userinput == "display")
                            {
                                dll.Display();
                            }
                            else if (queue_userinput == "quit")
                            {
                                break;
                            }
                        }

                    }
                }
                else if (linked_choice == "quit")
                {
                    break;
                }
            }
        }
    }
}