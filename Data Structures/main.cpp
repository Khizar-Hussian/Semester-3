#include<iostream>
#include "DoublyLinkedList.h"
using namespace std;


void main()
{
	dLinkedList<int> list;

	list.insertSorted(1);
	list.insertSorted(2);
	list.insertSorted(3);
	list.insertSorted(4);
	list.insertSorted(5);
	list.printList();

	list.InsertAtStart(10);
	list.printList();
	list.RemoveStart();
	list.printList();

	list.InsertEnd(10);
	list.printList();
	list.RemoveEnd();
	list.printList();

	list.Remove(3);
	list.printList();
	cin.get();
}