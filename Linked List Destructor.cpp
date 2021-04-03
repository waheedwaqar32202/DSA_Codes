#include<iostream>
using namespace std;

class LinkedList;
class Node
{
	friend class LinkedList;
	int data;
	Node* next;

};

class LinkedList
{
	Node* head;
	Node* tail;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insert(int value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	void display()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node* temp = head;

		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void deleteNode(int value)
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}

		Node* curr = head;
		Node* prev = nullptr;

		while (curr != nullptr && curr->data != value)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr == nullptr)
		{
			cout << "Value not found" << endl;
			return;
		}
		else
		{
			if (curr == head && curr == tail)  //if(head==tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else if (curr == head)
			{
				head = head->next;
				delete curr;
				curr = nullptr;
			}
			else if (curr == tail)
			{
				tail = prev;
				tail->next = nullptr;
				delete curr;
				curr = nullptr;
			}
			else
			{
				prev->next = curr->next;
				delete curr;
				curr = nullptr;
			}
		}




	}

	bool search(int value)
	{
		if (head == nullptr)
		{
			return false;
		}

		Node* curr = head;
		while (curr != nullptr && curr->data != value)
		{

			curr = curr->next;
		}

		if (curr == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	~LinkedList()
	{
		Node* curr = head;
		Node* prev = nullptr;

		while (curr != nullptr)
		{
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = nullptr;
		tail = nullptr;
	}


};


int main()
{
	LinkedList list1;

	list1.insert(2);
	list1.insert(3);
	list1.insert(5);

	list1.display();
	cout << endl;

	list1.~LinkedList();
	list1.display();
	cout << endl;

	return 0;
}