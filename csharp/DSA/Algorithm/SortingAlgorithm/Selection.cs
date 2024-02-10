using Collections.Algorithms;

namespace Sorting.Algorithms
{
    public class SelectionClass
    {
        public static void Sort()
        {
            int[] ints = { 0, 9, 8, 7, 6, 6, 5, 4, 3};

            for(int index = 0; index < ints.Length; index++)
            {
                int minIndex = index;
                for(int subIndex = index + 1; subIndex < ints.Length; subIndex++)
                {
                    if(ints[subIndex] < ints[minIndex])
                    {
                        minIndex = subIndex;
                    }
                }
                int temp = ints[minIndex];
                ints[minIndex] = ints[index];
                ints[index] = temp;
            }

            Console.WriteLine("After Sorting...");

            foreach(int value in ints)
            {
                Console.WriteLine(value);
            }
        }


        public static void Sort(DDLNode? Header)
        {
            DDLNode? currentNode = Header;

            while(currentNode != null)
            {
                int minValue = currentNode.Data;

                while(currentNode != null)
                {
                    // need to implement...
                }
            }
        }
    }
}