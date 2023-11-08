using System;

namespace DSA.DoubleLinkedList
{
    class DDLNode
    {
        public DDLNode? prev;
        public DDLNode? next;
        public int data;
        public DDLNode(int data, DDLNode? prev = null, DDLNode? next = null)
        {
            this.prev = prev;
            this.data = data;
            this.next = next;
        }
    }
    class DoubleLinkedList
    {
        public DDLNode? header;
        public DDLNode? tail;

        public DoubleLinkedList()
        {
            this.header = null;
            this.tail = null;
        }

        public void Add()
        {
            Console.WriteLine("Enter the value ");
            int data = Convert.ToInt32(Console.ReadLine());
            DDLNode new_node = new DDLNode(data);
            if (header == null)
            {
                header = new_node;
                tail = new_node;
            }
            else
            {
                DDLNode current_node = header;
                while (current_node.next != null)
                {
                    current_node = current_node.next;
                }
                current_node.next = new_node;
                new_node.prev = current_node;
                tail = new_node;
            }
        }

        public void AddBegin()
        {
            Console.WriteLine("Calling AddBegin method in Double Linked List...");

            Console.WriteLine("Enter the value: ");
            int new_value = Convert.ToInt32(Console.ReadLine());
            DDLNode new_node = new DDLNode(new_value);

            if (header == null)
            {
                header = new_node;
            }
            else
            {
                header.prev = new_node;
                new_node.next = header;
                header = new_node;
            }
        }
        public void Remove_value()
        {
            Console.WriteLine("calling remove_value method");
            Console.WriteLine("Enter the value: ");
            int value = Convert.ToInt32(Console.ReadLine());
            if (header == null)
            {
                Console.WriteLine("Linked List is empty...");
            }
            else
            {
                DDLNode? current_node = header;
                while (current_node != null)
                {
                    Console.WriteLine($"may be {current_node.data}");
                    if (current_node.data == value)
                    {
                        //Console.WriteLine($"data found: {current_node.data}");
                        // Perform operations to remove the node

                        Console.WriteLine($"prev: {current_node.prev == null}, next: {current_node.next == null} current: {current_node == null}");
                        if (current_node.prev != null)
                        {
                            current_node.prev.next = current_node.next;
                        }
                        else
                        {
                            // If current_node is the head of the list, update the header
                            header = current_node.next;
                        }

                        if (current_node.next != null)
                        {
                            current_node.next.prev = current_node.prev;
                        }
                        else
                        {
                            // If current_node is the tail of the list, update the tail
                            tail = current_node.prev;
                        }
                    }
                    current_node = current_node.next;
                }
            }
        }

        public void RemoveIndex(string? where)
        {
            Console.WriteLine("Calling RemoveIndex method in Double Linked List...");

            int index = 0;

            if (where == "")
            {
                Console.WriteLine("Enter the index: ");
                index = Convert.ToInt32(Console.ReadLine());
            }

            if (header == null)
            {
                Console.WriteLine("List is empty...");
            }
            else
            {
                if (index == 0)
                {
                    header = header.next;
                    header.prev = null;
                }
                else
                {
                    DDLNode Current_node = header;
                    int i = 0;
                    while (i < index)
                    {
                        Current_node = Current_node.next;
                        i++;
                    }
                    Current_node.prev.next = Current_node.next;
                    Current_node.next.prev = Current_node.prev;
                }
            }

        }

        public int RemoveLast()
        {
            Console.WriteLine("Calling RemoveLast method in Double Linked List...");
            int value = 0;
            if (header == null)
            {
                Console.WriteLine("List is Empty...");
                return value;
            }
            else
            {
                DDLNode current_node = header;

                while (current_node.next.next != null)
                {
                    current_node = current_node.next;
                }
                value = current_node.next.data;
                current_node.next = null;
                tail = current_node;
                return value;
            }
        }

        public void Update()
        {
            Console.WriteLine("Calling Update method in Double Linked List...");

            Console.WriteLine("Enter the old Value: ");
            int oldValue = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Enter the new Value: ");
            int newValue = Convert.ToInt32(Console.ReadLine());

            if (header != null)
            {
                DDLNode current_node = header;
                while (current_node != null)
                {
                    if (current_node.data == oldValue)
                    {
                        current_node.data = newValue;
                    }
                    current_node = current_node.next;
                }
            }
        }
        public void Display()
        {
            Console.WriteLine("calling display method from ddl...");
            DDLNode? current_node = header;
            while (current_node != null)
            {
                Console.WriteLine($"{current_node.data}");
                current_node = current_node.next;
            }
        }

        public int Length()
        {
            if (header == null)
            {
                return 0;
            }
            else
            {
                int count = 0;
                DDLNode current_node = header;
                while (current_node != null)
                {
                    count++;
                    current_node = current_node.next;
                }
                return count;
            }
        }
    }
}