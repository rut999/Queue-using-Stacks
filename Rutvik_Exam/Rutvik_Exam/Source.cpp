// Rutvik_Parvataneni_Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#define MAX_SIZE 1000
using namespace std;

class Stack
{
	int top;
	int stack[MAX_SIZE] = { 0 };

public:
	Stack();
	void push(int number);
	int pop();
	bool full();
	bool empty();	
	int Top();
};

//Default constructor to initialize top
Stack::Stack()
{
	top = 0;
}

//To check if the stack is Full to avoid overflow
bool Stack::full()
{
	return top == MAX_SIZE;
}

// returns the top of stackStack 
int Stack::Top()
{
	return stack[top - 1];
}
// Pushing the integer into the Stack
void Stack::push(int number)
{
	if (!full())
	{
		stack[top] = number;
		top++;
	}
	else
	{
		cout << "Overflow detected" << endl;
		return;
	}
}
// Check to see if the Stack is empty
bool Stack::empty()
{
	return top == 0;
}

// Pop the integer out of the stack
int Stack::pop()
{
	if (!empty())
	{
		int number = stack[--top];
		return number;
	}
	else
	{
		return INT_MIN;
	}
}

class Queue {

	Stack s, t;
public:
	int dequeue();
	void enqueue(int number);
};

int Queue::dequeue()
{
	if (s.empty() && t.empty())
	{
		cout << "The Queue is Empty \n";
		return -1;   //If both stacks are empty there is nothing to dequeue
	}		

	if (t.empty())
	{
		while (!s.empty())
		{
			t.push(s.Top());
			s.pop();

		}
	}

	int number = t.Top();
	t.pop();
	return number;
}

void Queue::enqueue(int number)
{
	s.push(number);
	return;
}

int main()
{
	Queue q;
	q.enqueue(5);
	q.enqueue(7);
	q.enqueue(-1);
	q.enqueue(0);
	q.enqueue(9999);

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;


	/*s.push(4);

	s.push(1);
	s.push(2);
	s.push(9);
	s.push(8);
	s.push(7);
	s.push(44);
	

	cout << s.pop() << endl;
	

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	*/
	return 0;

}

