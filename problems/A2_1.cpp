// ----------------------------------------------------------------------------------------------------
//
// Question 1:
// This problem studies another way to represent sequential queue. In this strategy, to
// represent a queue q, we maintain internally two separate extensible arrays a1 and a2, and
// the enqueue operation is always done at the tail of array a2, while dequeue operation is
// done at the tail of a1. And if a1 is empty, we remove all elements from a2 and insert
// inversely into a1, and then the dequeue operation follows. For instance, at the beginning,
// after enqueuing element 1, 2, 3, the array a2 = [1, 2, 3], while a1 = [ ]; when dequeuing
// the queue, we find that a1 is empty, so we remove all elements from a2 and insert them
// into a1, which leaves a1 = [3, 2, 1], a2 = [ ]. And then the dequeue operation follows
// leaving a1 = [3, 2] and a2 = [ ].
// 
// a. Design a data structure to represent such kind of sequential queue and then
// implement it.
// b. How to extend and shrink array a1 and a2? Do these operations must be operated
// on a1 and a2 simultaneously, or could be done independently?
// c. Does this strategy apply to linked queue? If so, implement it.
//
// ----------------------------------------------------------------------------------------------------

// Q1>a and c part code is below

// Q1>b part
/*
	Extension of a1 and shinkage of a2--> Use a1.push_back() and a2.pop_back()
	These operations can be done simultaneously only when a1 is not empty
	because enqueue adds to the back of a2 and dequeue requires the values
	inside a2 if a1 is found to be empty. If a1 is empty, we cannot
	simultaneously carry out both of these operations.
*/

// Q1>c
/*
	Yes this strategy applies to linked queue.
	enqueue() operation and dequeue() operations will work as they are.
	Only functions needed extra are front() and back(), which have been
	already been implemented below along with the code for part a of the question.
*/
#include "stdafx.h"

#include <iostream>

#include <string>
#include <vector>

namespace A2_1
{
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
			std::cout << "(" << m_ID << ", " << m_Name << ") ";
		}

		friend std::ostream & operator<<(std::ostream & stream, Node & node);
	};

	std::ostream & operator<<(std::ostream & stream, Node & node)
	{
		node.printNode();
		return stream;
	}

	class MagicDS
	{
	private:
		std::vector<Node> a1;
		std::vector<Node> a2;

	public:
		Node & front()
		{
			if(a2.empty())
			{
				return a1.back();
			}
			else
			{
				return a2.front();
			}
		}

		Node & back()
		{
			if(a2.empty())
			{
				return a1.front();
			}
			else
			{
				return a2.back();
			}
		}

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
			for(auto item : a1)
			{
				item.printNode();
			}

			std::cout << std::endl;
		}

		void printA2()
		{
			for(auto item : a2)
			{
				item.printNode();
			}
		}

		void print()
		{
			std::cout << "a1: ";
			printA1();

			std::cout << "a2: ";
			printA2();
		}
	};
}

int mainA2_1()
{
	using namespace A2_1;

	MagicDS myDS;
	myDS.enqueue(&Node(0, "Apple"));
	myDS.enqueue(&Node(1, "Orange"));
	myDS.enqueue(&Node(2, "Guava"));

	myDS.print();

	std::cout << myDS.front();

	myDS.dequeue();
	myDS.dequeue();

	std::cout << myDS.back();

	myDS.dequeue();

	std::cin.get();
	return 0;
}

