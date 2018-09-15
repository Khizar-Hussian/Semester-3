#pragma once
#include<iostream>
using namespace std;



template<class t> class dLinkedList;



template<class t>
class node
{
	t data;
	node *prev, *next;

public:
	node()
	{
		data = NULL;
		prev = nullptr;
		next = nullptr;
	}

	node(t data)
	{
		this->data = data;
		prev = nullptr;
		next = nullptr;
	}

	friend class dLinkedList<t>;
};



template<class d>
class dLinkedList
{
	node<d> head;
	node<d> *tail;


public:
	dLinkedList()
	{
		head.data = NULL;
		head.next = nullptr;
		head.prev = nullptr;
		tail = new node<d>();
	}

	~dLinkedList()
	{
		node<d>* temp = head.next;
		while (temp != tail)
		{
			head->next = temp->next;
			delete temp;
		}

	}
	void printList()
	{
		if (head.next != empty) {
			node<d> *curr = head.next;
			while (curr != tail)
				cout << curr.data << " ";
			cout << endl;
		}
	}


	void InsertAtStart(d data)
	{
		node<d> *temp = new node<d>(data);
		head.next->prev = temp;
		temp->next = head.next;
		temp->prev = &head;
		head.next = temp;
	}

	void RemoveStart()
	{
		node<d> * temp = head.next;
		head.next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
};