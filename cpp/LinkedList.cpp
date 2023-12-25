#include "iostream"
#include "string"

namespace LinkedList
{
	struct Node
	{
		int data;
		Node *nextNode;

		Node(int userData, Node *nextNode)
		{
			this->data = userData;
			this->nextNode = nextNode;
		}
	};

	class LinkedListClass
	{
	private:
		Node *header;

	public:
		LinkedListClass()
		{
			this->header = NULL;
		}

	public:
		void AddValue()
		{
			int userData;
			std::cout << "Enter the value: ";
			std::cin >> userData;

			Node* newNode = new Node(userData, nullptr);
			newNode->nextNode = this->header;
			this->header = newNode;
		}

	public:
		void Display()
		{
			Node *currentNode = this->header;
			while (currentNode != nullptr)
			{
				std::cout << currentNode->data << std::endl;
				currentNode = currentNode->nextNode;
			}
		}
	};
}

int main()
{
	LinkedList::LinkedListClass obj;

	while (true)
	{
		std::cout << "add. Add the value: " << std::endl;
		std::cout << "display. Display the value: " << std::endl;
		std::cout << "quit. to exit" << std::endl;

		std::string userInput;
		std::cin >> userInput;

		if (userInput == "add")
		{
			obj.AddValue();
		}
		else if (userInput == "display")
		{
			obj.Display();
		}
		else if (userInput == "quit")
		{
			break;
		}
		else
		{
			std::cout << "Enter the correct choice: " << std::endl;
		}
	}
}
