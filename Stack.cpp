//Stack Implementation
#include<iostream>
using namespace std;

class Stack
{
	int* s;
	int maxSize;
	int top;
public:
	Stack(int size)
	{
		maxSize = size;
		s = new int[maxSize];
		top = -1;
	}
	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;

	}
	bool isFull()
	{
		if (top == maxSize - 1)
			return true;
		else
			return false;
	}

	bool push(int value)
	{
		if (isFull())
			return false;
		else
		{
			top++;
			s[top] = value;
			return true;
		}
	}
	bool pop(int& value)
	{
		if (isEmpty())
			return false;
		else
		{
			value = s[top];
			top--;
			return true;
		}
	}
	//display()
	//seeTop
};

int main()
{
	Stack s1(5);

	if (s1.push(1))
		cout << "Successfuly inserted" << endl;
	else
		cout << "Not Inserted" << endl;
	if (s1.push(2))
		cout << "Successfuly inserted" << endl;
	else
		cout << "Not Inserted" << endl;
	if (s1.push(3))
		cout << "Successfuly inserted" << endl;
	else
		cout << "Not Inserted" << endl;
	if (s1.push(4))
		cout << "Successfuly inserted" << endl;
	else
		cout << "Not Inserted" << endl;
	if (s1.push(5))
		cout << "Successfuly inserted" << endl;
	else
		cout << "Not Inserted" << endl;

	int value;
	if (s1.pop(value))
		cout << "Successfuly removed " << value << endl;
	else
		cout << "Not removed" << endl;


	if (s1.push(6))
		cout << "Successfuly inserted" << endl;
	else
		cout << "Not Inserted" << endl;

	if (s1.pop(value))
		cout << "Successfuly removed " << value << endl;
	else
		cout << "Not removed" << endl;


	return 0;
}