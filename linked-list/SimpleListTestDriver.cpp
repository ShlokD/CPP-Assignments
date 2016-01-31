///////////////////////////////////////////////////////////////////////
// DriverProgram
// FileName:	SimpleListTestDriver.cpp
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Main function which is the entrypoint of the program 
// Description - Driver program which tests the NodeSLList class
///////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <ctime>

#include "NodeSLList.h"

void NodeSLList_Test();
void TestSort();

void main(void)
{
    NodeSLList_Test();
}

// Test the Linked List functions
void NodeSLList_Test()
{

	NodeSLList list1;
	cout << "*****************************************************************************" << endl;
	cout << "Testing default constructor" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Creating NodeSLList list1" << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl << endl;

	IntNode temp;

	IntNode n1;
	n1.data = 10;
	IntNode n2;
	n2.data = 20;
	IntNode n3;
	n3.data = 30;
	IntNode n4;
	n4.data = 40;
	IntNode n5;
	n5.data = 50;
	IntNode n6;
	n6.data = 25;
	IntNode n7;
	n7.data = 32;
	IntNode n8;
	n8.data = 2;
	IntNode n9;
	n9.data = 27;
	IntNode n10;
	n10.data = 84;

	cout << "*****************************************************************************" << endl;
	cout << "Testing AddToHead() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Adding " << n5.data << " to list1" << endl;
	list1.AddToHead(n5);
	cout << "Adding " << n4.data << " to list1" << endl;
	list1.AddToHead(n4);
	cout << "Adding " << n3.data << " to list1" << endl;
	list1.AddToHead(n3);
	cout << "Adding " << n2.data << " to list1" << endl;
	list1.AddToHead(n2);
	cout << "Adding " << n1.data << " to list1" << endl;
	list1.AddToHead(n1);
	cout << "cout << list1 " << endl;
	cout << list1 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing Copy Constructor. Creating list2 from list1" << endl;
	cout << "*****************************************************************************" << endl;
	NodeSLList list2(list1);
	cout << "cout << list2 " << endl;
	cout << list2 << endl << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing AddToTail() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Adding " << n6.data << " to list1" << endl;
	list1.AddToTail(n6);
	cout << list1 << endl;
	cout << list2 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing GetSize() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "list1 contains " << list1.GetSize() << " node(s)" << endl << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing operator= by assigning list1=list2" << endl;
	cout << "*****************************************************************************" << endl;
	list1 = list2;
	cout << list1 << endl;
	cout << list2 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing DeleteFromHead() operation" << endl;
	cout << "*****************************************************************************" << endl;
	temp = list1.DeleteFromHead();
	cout << "node retrieved " << temp.data << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl;
	cout << list2 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing equality == and inequality != operators" << endl;
	cout << "*****************************************************************************" << endl;
	if (list1 == list2) cout << "list1 == list2" << endl << endl;
	if (list1 != list2) cout << "list1 != list2" << endl << endl;

	cout << "Putting the previous node back on the head of list1. Now list1 and list2 should be equal" << endl;
	list1.AddToHead(temp);
	cout << "cout << list1 " << endl;
	cout << list1 << endl;
	cout << list2 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing equality == and inequality != operators" << endl;
	cout << "*****************************************************************************" << endl;

	if (list1 == list2){ cout << "list1 == list2" << endl << endl; }
	if (list1 != list2) cout << "list1 != list2" << endl << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing concate + operator" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Copying list1 into list3 and list2 into list4" << endl;

	NodeSLList list3 = list1;
	NodeSLList list4 = list2;
	cout << "cout<<list3" << endl;
	cout << list3 << endl;
	cout << "cout<<list4" << endl;
	cout << list4 << endl;
	cout << "cout << list3+list4 " << endl;
	cout << list3 + list4 << endl;


	cout << "*****************************************************************************" << endl;
	cout << "Testing DeleteFromTail() operation" << endl;
	cout << "*****************************************************************************" << endl;
	temp = list1.DeleteFromTail();
	cout << "node retrieved " << temp.data << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl;

	cout << endl;
	cout << "Adding " << n3.data << " to head" << endl;
	cout << "Adding " << n2.data << " to head" << endl;
	list1.AddToHead(n3);
	list1.AddToHead(n2);
	cout << "cout << list1 " << endl;
	cout << list1 << endl;


	cout << "*****************************************************************************" << endl;
	cout << "Testing DeleteNode() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Deleting node 35 (should be last node, since 35 is beyond end of list)" << endl;
	temp = list1.DeleteNode(35);
	cout << "cout << list1 " << endl;
	cout << list1 << endl;
	temp = list1.DeleteNode(3);
	cout << "Deleteing node 3 (" << temp.data << ")" << endl;
	cout << "cout << list1 " << endl;
	cout << list1 << endl;


	cout << "*****************************************************************************" << endl;
	cout << "Testing InsertNode() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Adding node with value " << n7.data << " at location 3";
	list1.InsertNode(3, n7);
	cout << list1 << endl;



	cout << "*****************************************************************************" << endl;
	cout << "Testing IsEmpty() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << (list2.IsEmpty() ? "list2 is EMPTY" : "list2 is NOT EMPTY") << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing UpdateNode() operation (updating 3rd node with 500)" << endl;
	cout << "*****************************************************************************" << endl;
	temp.data = 500;
	list1.UpdateNode(3, temp);
	cout << "cout << list1 " << endl;
	cout << list1 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing the ability to delete nodes from head." << endl;
	cout << "*****************************************************************************" << endl;
	cout << "list1 has " << list1.GetSize() << " nodes" << endl;
	int numNodesToDelete = list1.GetSize();
	for (int x = 0; x < numNodesToDelete; x++)
	{
		cout << "Deleting from head" << endl;
		temp = list1.DeleteFromHead();
		cout << "cout << list1 " << endl;
		cout << list1 << endl;
	}
	cout << "Deleting from head, after list is empty. Should receive an error." << endl;
	temp = list1.DeleteFromHead();
	cout << "cout << list1 " << endl;
	cout << list1 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Testing DestroyList() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << "calling DestoryList()" << endl;
	list2.DestroyList();
	cout << "cout << list2 " << endl;
	cout << list2 << endl;

	cout << "*****************************************************************************" << endl;
	cout << "Test IsEmpty() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << "calling list2.IsEmpty()" << endl;
	cout << (list2.IsEmpty() ? "list2 is EMPTY" : "list2 is NOT EMPTY") << endl << endl;
	TestSort();
}

// Test the sorting functions
void TestSort()
{
	NodeSLList list1;
	IntNode n5;
	n5.data = 50;
	IntNode n6;
	n6.data = 25;
	IntNode n7;
	n7.data = 32;
	IntNode n8;
	n8.data = 2;
	IntNode n9;
	n9.data = 27;
	IntNode n10;
	n10.data = 84;

	list1.AddToHead(n5);
	list1.AddToHead(n6);
	list1.AddToHead(n7);
	list1.AddToHead(n8);
	list1.AddToHead(n9);
	list1.AddToHead(n10);
	NodeSLList list2 = list1;
	cout << "*****************************************************************************" << endl;
	cout << "Testing SortList() operation, ascending" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Unsorted" << endl;
	cout << list1 << endl;
	cout << "Sorted" << endl;
	list2.SortList(1);
	cout << list2 << endl;
	
	list2 = list1;
	cout << "*****************************************************************************" << endl;
	cout << "Testing SortList() operation, descending" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Unsorted" << endl;
	cout << list1 << endl;
	cout << "Sorted" << endl;
	list2.SortList(2);
	cout << list2 << endl;
	system("pause");
}


