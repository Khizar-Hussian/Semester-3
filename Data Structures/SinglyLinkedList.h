#pragma once
#include<iostream>
using namespace std;

// forward declaring lists
template <class Type> class sLinkedList;


template<class t>
class node
{
	t data;
	node* next;

public:
	node()
	{
		data = NULL;
		next = nullptr;
	}
	node(t data)
	{
		this->data = data;
		next = nullptr;
	}

	friend class sLinkedList<t>;
};


template<typename d>
class sLinkedList
{
	node<d> head;

public:
	sLinkedList()
	{
		head.next = nullptr;
		head.data = NULL;
	}

	~sLinkedList()
	{
		node<d>* temp=head.next;//					head  ->nullptr
		while (temp != nullptr)
		{
			head.next = temp->next;
			delete temp;
			temp = head.next;
		}
	}


	void InsertAtStart(d data)
	{
		node<d>* temp = new node<d>(data);
		temp->next = head.next;
		head.next = temp;
	}

	void RemoveAtStart()
	{
		if (head.next != nullptr)
		{
			node<d>* temp = head.next;		//head -> 1 -> 2
			head.next = temp->next;
			delete temp;
		}
	}

	void printList()
	{
		node<d>* curr = head.next;
		while (curr!=nullptr)
		{
			cout << curr->data<<" ";
			curr = curr->next;
		}
		cout << endl;
	}

	void InsertAtEnd(d data)
	{
		node<d>* temp = new node<d>(data);
		if (head.next != nullptr)
		{
			node<d>* t = head.next;
			while (t->next != nullptr)
				t = t->next;
			t->next = temp;
		}
		else
			head.next = temp;
	}

	void RemoveAtEnd()
	{
		if (head.next != nullptr)
		{
			node<d>* temp = head.next;
			while (temp->next->next != nullptr)
				temp = temp->next;
			delete temp->next;
			temp->next = nullptr;
		}
	}

	void InsertSorted(d data)
	{
		node<d>* temp = new node<d>(data);
		node<d> *prev, *curr;
		prev = &head;
		curr = prev->next;
		
		while (curr != nullptr && curr->data < data)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = temp;
		temp->next = curr;
	}

	void Remove(d data)
	{
		node<d> *prev, *curr;
		prev = &head;
		curr = prev->next;
		while (curr != nullptr && curr->data < data)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != nullptr && curr->data == data)
		{
			prev->next = curr->next;
			delete curr;
		}
	}
};