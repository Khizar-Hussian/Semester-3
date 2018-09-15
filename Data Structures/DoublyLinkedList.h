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
		tail = new node<d>();
		tail->prev = &head;
		head.data = NULL;
		head.next = tail;
		head.prev = nullptr;
	}

	~dLinkedList()
	{
		node<d>* temp;
		temp = head.next;					//head -> 1   2   3  4  5 ->tail
		while (head.next!=tail)
		{
			head.next = temp->next;
			delete temp;
			temp = head.next;
		}

	}
	void printList()
	{
		if (head.next != tail) {
			node<d> *curr = head.next;
			while (curr != tail) {
				cout << curr->data << " ";
				curr = curr->next;
			}
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

	void Remove(d data)
	{
		node<d>* curr = head.next;
		while (curr != nullptr && curr->data < data)
			curr = curr->next;
		if (curr != nullptr && curr->data == data)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
		}
	}

	void Remove(node<d>* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
	}


	void InsertEnd(d data)
	{
		node<d>* temp = new node<d>(data);
		if (head.next == tail)
		{
			temp->next = head.next;
			head.next = temp;
		}
		else
		{
			temp->next = tail;
			temp->prev = tail->prev;
			tail->prev->next = temp;
			tail->prev = temp;
		}
	}

	void RemoveEnd()
	{
		if (head.next != tail)
		{
			node<d>* temp = tail->prev;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}

	void insertSorted(d data)
	{
		node<d>* temp = new node<d>(data);
		if (head.next == tail)
		{
			temp->next = head.next;
			tail->prev = temp;
			head.next = temp;
			temp->prev = &head;
		}
		else 
		{
			node<d>* curr = head.next;
			while (curr != tail && curr->data < data)
				curr = curr->next;

			curr->prev->next = temp;
			temp->prev = curr->prev;
			temp->next = curr;
			curr->prev = temp;
		}
	}
};