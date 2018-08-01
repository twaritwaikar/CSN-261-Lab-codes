// A2_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>
#include <vector>

struct Node
{
	int m_ID;
	std::string m_Name;

	Node(const int id, const std::string name)
		:m_ID(id), m_Name(name)
	{
	}

	void printNode()
	{
		std::cout << "Added: (" << m_ID << ", " << m_Name << ")" << std::endl;
	}
};

class MagicDS
{
private:
	std::vector<Node> a1;
	std::vector<Node> a2;

public:
	void enqueue(const Node * node)
	{
		a2.push_back(*node);
	}

	int dequeue()
	{
		if(a1.empty())
		{
			if(!a2.empty())
			{
				while(!a2.empty())
				{
					// Remove all elements from a2
					// Add inversely to a1
					a1.push_back(a2.back());
					a2.pop_back();
				}

				// Now perform dequeue operation
				a1.pop_back();
			}

			return 2;
		}
		else
		{
			a1.pop_back();

			return 1;
		}
	}

	void printA1()
	{
		::std::cout << "a1: " << std::endl;

		for(auto item : a1)
		{
			item.printNode();
		}
	}

	void printA2()
	{
		::std::cout << "a2: " << std::endl;

		for(auto item : a2)
		{
			item.printNode();
		}
	}

	void print()
	{
		printA1();
		printA2();
	}
};

int main()
{
	MagicDS myDS;
	myDS.enqueue(&Node(0, "Apple"));
	myDS.enqueue(&Node(1, "Orange"));
	myDS.enqueue(&Node(2, "Guava"));
	myDS.enqueue(&Node(3, "Banana"));

	std::cout << "Enqueue 4 times" << std::endl;
	myDS.print();
	std::cin.get();

	myDS.dequeue();
	myDS.dequeue();
	std::cout << "Dequeue 2 times" << std::endl;
	std::cin.get();

	myDS.print();
	std::cin.get();

	myDS.enqueue(&Node(4, "Grape"));
	std::cout << "Enqueue 1 time" << std::endl;

	myDS.print();
	std::cin.get();

	myDS.dequeue();
	myDS.dequeue();
	myDS.dequeue();
	myDS.dequeue();
	std::cout << "Dequeue 4 times" << std::endl;

	myDS.print();
	std::cin.get();


	return 0;
}

