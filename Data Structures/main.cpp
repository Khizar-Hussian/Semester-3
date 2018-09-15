#include<iostream>
#include "node.h"
using namespace std;


void main()
{
	//test main
	sLinkedList<int> list;
	list.InsertAtStart(8);
	list.InsertAtStart(4);
	list.InsertAtStart(3);
	list.InsertAtStart(2);
	list.InsertAtStart(1);
	list.InsertAtEnd(10);
	list.printList();

	list.InsertSorted(6);
	list.InsertSorted(9);
	list.printList();

	list.Remove(6);
	list.printList();


	cin.get();
}