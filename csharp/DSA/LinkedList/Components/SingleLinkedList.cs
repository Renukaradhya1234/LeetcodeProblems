using System;
namespace single_linked_list
{
    public class Node
    {
        public int data;
        public Node? next;
        public Node(int data, Node? next = null)
        {
            this.data = data;
            this.next = next;
        }
    }

    public class SingleLinked
    {
        private Node? header;
        public SingleLinked()
        {
            this.header = null;
        }

        public void Add(int data)
        {
            Console.WriteLine("calling add method");
            Node obj = new(data);

            if (header == null)
            {
                header = obj;
            }
            else
            {
                Node current_node = header;
                while (current_node.next != null)
                {
                    current_node = current_node.next;
                }
                current_node.next = obj;
            }
        }

        public void Add_Begin(int data)
        {
            Console.WriteLine("calling add begin method...");
            Node obj = new(data);
            if (header == null)
            {
                header = obj;
            }
            else
            {
                obj.next = header;
                header = obj;
            }
        }

        public void Display()
        {
            Console.WriteLine("calling display method");

            Node? current_node = header;
            while (current_node != null)
            {
                Console.WriteLine(current_node.data);
                current_node = current_node.next;
            }
        }

        public int Remove()
        {
            Console.WriteLine("calling remove method");

            if (header == null)
            {
                Console.WriteLine("list is empty...");
                return 0;
            }
            else
            {
                int value;
                Node? current_node = header;
                while (current_node.next.next != null)
                {
                    current_node = current_node.next;
                }
                value = current_node.next.data;
                current_node.next = null;
                return value;
            }
        }

        public int List_length()
        {
            if (header == null)
            {
                return 0;
            }
            else
            {
                Node? current_node = header;
                int count = 0;
                while (current_node != null)
                {
                    count++;
                    current_node = current_node.next;
                }
                return count;
            }
        }

        public void Update_value(int value, int newValue)
        {
            Console.WriteLine("Update value method called...");
            if (header == null)
            {
                Console.WriteLine("List is empty...");
            }
            else
            {
                Node? current_node = header;
                while (current_node != null)
                {
                    if (current_node.data == value)
                    {
                        current_node.data = newValue;
                    }
                    current_node = current_node.next;
                }
            }
        }

        public void Update_index(int index, int newValue)
        {
            Console.WriteLine("Update index method called...");

            if (header == null)
            {
                Console.WriteLine("List is empty...");
            }
            else
            {
                Node? current_node = header;
                int temp_index = 0;

                while (current_node != null)
                {
                    if (temp_index == index)
                    {
                        break;
                    }
                    temp_index++;
                    current_node = current_node.next;
                }
                current_node.data = newValue;
            }
        }

        public int Remove_index(int index)
        {
            Console.WriteLine("Remove index method called...");
            int value = -1;

            if (header == null)
            {
                return value;
            }
            else
            {
                if (index == 0)
                {
                    value = header.data;
                    header = header.next;
                    return value;
                }
                else
                {
                    Node? current_node = header;
                    int temp_index = 0;

                    while (current_node != null)
                    {
                        if (temp_index == index - 1)
                        {
                            break;
                        }
                        temp_index++;
                        current_node = current_node.next;
                    }
                    value = current_node.next.data;
                    current_node.next = current_node.next.next;
                    return value;
                }
            }
        }
    }
}
