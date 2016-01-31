///////////////////////////////////////////////////////////////////////
// Class NodeSLList Implementation
// FileName:	NodeSLList.cpp
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of NodeSLList class constructors and methods
// Description - This file implements a singly linked list.
///////////////////////////////////////////////////////////////////////
#include "NodeSLList.h"


///////////////////////////////////////////////////////////////////////
// default constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList()
{ 
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// copy constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList(NodeSLList & list)
{
	IntNode *ptr1 = 0; // first pointer for current list
	IntNode *ptr2 = 0; // second pointer for source list
	
	if (list.head == 0) // empty list?
		head = 0;
	else
	{
		head = new IntNode; // create a new head node
		head->data = list.head->data; // copy first node of source to head node
		ptr1 = head; // move first pointer to head
		ptr2 = list.head->next; // move second pointer to next node of source's head node
	}

	while (ptr2 != NULL) // traverse through source's nodes
	{
		ptr1->next = new IntNode; // create new node
		ptr1 = ptr1->next;// move current head node to next node
		ptr1->data = ptr2->data; // copy data from source
		ptr2 = ptr2->next; // move source node pointer to next node
	}
	ptr1->next = NULL;
	tail = ptr1;
} 

///////////////////////////////////////////////////////////////////////
// destructor
///////////////////////////////////////////////////////////////////////
NodeSLList::~NodeSLList()
{
	// call destroyList() to remove all nodes
	// and reset linked list
	DestroyList();
}

///////////////////////////////////////////////////////////////////////
// IsEmpty
///////////////////////////////////////////////////////////////////////
bool NodeSLList::IsEmpty()
{ 
	// if head is NULL, then the list is empty, and we will return true
	// otherwise, we will return false
	return (head == 0); 
}

///////////////////////////////////////////////////////////////////////
// GetSize
///////////////////////////////////////////////////////////////////////
int NodeSLList::GetSize()
{
	// check to see if the list is empty. if 
	// so, just return 0
	if ( IsEmpty() ) return 0;

	int size = 1;
	IntNode *p = head;
	// compute the number of nodes and return
	while (p != tail)
	{
		// until we reach the tail, keep counting
		size++;
		p = p->next;
	}
	return size;
}

///////////////////////////////////////////////////////////////////////
// AddToHead
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToHead(const IntNode & node)
{
	// create a new node, and make it the head. the 
	// previous head will become head->next
	IntNode * next = head;
	head = new IntNode;
	head->next = next;
	head->data = node.data;

	// if this is the first node, make the tail the 
	// same as the head
	if (tail == 0)
		tail = head;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromHead
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromHead()
{
	IntNode temp;
	temp.data=0;
	temp.next=NULL;
	if (IsEmpty())
	{
		cout << "*****ERROR: Can't delete from head. List is Empty" << endl;
		return temp;
	}

	// get current value of node we are about to delete, 
	// so we can return it.
	temp.data = head->data;

	IntNode *tmp = head;

	// if there is only one node, set the head and pointer tails
	// to NULL (0)
	if (head == tail)
		head = tail = 0;

	// otherwise, move the head pointer to the next node 
	// in the list
	else
		head = head->next;

	// delete head node
	delete tmp;

	// return value of node that was deleted
	return temp;
}

///////////////////////////////////////////////////////////////////////
// AddToTail
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToTail(const IntNode & node)
{
	IntNode *ptr = head;
	while (ptr->next != NULL) // Traverse to the last node
	{
		ptr = ptr->next;
	}
	// create a new node and copy data to it
	ptr->next = new IntNode;
	ptr = ptr->next;
	ptr->data = node.data;
	ptr->next = NULL; // This is the last node, so next pointer will be null

	// Set this as the new tail
	tail = ptr;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromTail
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromTail()
{
	IntNode nodeData;

	// get the current data at the tail
	nodeData.data = tail->data;


	// if there is only one node, delete the only node, and set the 
	// head and tail pointers to NULL (0) 
	if (head == tail)
	{
		delete head;
		head = tail =0;
	}

	// otherwise, traverse to the tail node and delete it
	else
	{
		IntNode * temp;
		// traverse to tail pointer
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
	}

	return nodeData;
}


///////////////////////////////////////////////////////////////////////
// DeleteNode
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteNode(int nodeNum)
{
	if (nodeNum <= 0) nodeNum = 1;
	IntNode *prev=head , *temp=head;
	IntNode current;

	// traverse to the node
	for (int loop=1; loop<nodeNum; loop++)
	{
		prev=temp, temp=temp->next;
		// check for case where nodeNum is > the number of 
		// nodes in the list. if we reach the tail before
		// we traverse to the node, delete the tail 
		if ( temp == tail )
			return DeleteFromTail();
	}

	// if deleting the head just call 
	// the appropriate member function 
	// and don't repeat that logic here
	if (temp == head) return DeleteFromHead();

	// otherwise, delete the node we traversed to
	prev->next = temp->next;
	current.data = temp->data;

	delete temp;

	return current;
}

///////////////////////////////////////////////////////////////////////
// InsertNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::InsertNode(int nodeNum, const IntNode &node)
{
	IntNode *p = head; // Start from first node
	for (int i = 1; i < nodeNum-1; ++i) // Traverse till required position
		p = p->next;
	
	IntNode *curr = new IntNode; // Create new node to be inserted into list
	curr->data = node.data;
	// Make new node point to current node's next node and move
	// current node to the new node
	curr->next = p->next;
	p->next = curr;
}


///////////////////////////////////////////////////////////////////////
// UpdateNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::UpdateNode(int nodeNum, const IntNode &node)
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first. if the last node is reached, then that is the node
	// that is updated
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	tmp->data = node.data;
}

///////////////////////////////////////////////////////////////////////
// SortList
///////////////////////////////////////////////////////////////////////
void NodeSLList::SortList(unsigned int order)
{
	IntNode *curr = 0; // Pointer to keep track of currently referenced node
	IntNode *prev = 0; // Pointer to keep track of previously referenced node
	IntNode *temp = 0; // Temporary pointer for swapping
	for (int i = 0; i < GetSize(); ++i) // For all nodes in the list
	{
		curr = head; // Initialize to traverse from beginning
		prev = head;
		while (curr->next != NULL)
		{
			if (order == 1) // Ascending Order
			{
				if (curr->data > curr->next->data)
				{
					// Swap the node next to current node with
					// the current node
					temp = curr->next;
					curr->next = curr->next->next;
					temp->next = curr;

					// If current node is head, then update the pointers
					if (curr == head)
					{
						head = temp;
						prev = temp;
					}
					else
					{
						prev->next = temp; // move the previous node pointer to the swapped node
					}
					curr = temp; // Set the swapped node to the current node and move forward
				}
			}
			else if (order == 2) // Descending Order
			{
				if (curr->data < curr->next->data)
				{
					// Swap the node next to current node with
					// the current node
					temp = curr->next;
					curr->next = curr->next->next;
					temp->next = curr;

					// If current node is head, then update the pointers
					if (curr == head)
					{
						head = temp;
						prev = temp;
					}
					else
					{
						prev->next = temp;// move the previous node pointer to the swapped node
					}
					curr = temp;// Set the swapped node to the current node and move forward
				}
			} 
			prev = curr; // Increment the previous node pointer
			curr = curr->next; // Increment the current node pointer
		}
	}
}

///////////////////////////////////////////////////////////////////////
// DestroyList
///////////////////////////////////////////////////////////////////////
void NodeSLList::DestroyList()
{
	// while the list is NOT empy
	// keep removing the head node and make
	// the next node the head node
	for (IntNode *p; !IsEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// operator=
///////////////////////////////////////////////////////////////////////
NodeSLList & NodeSLList::operator=(NodeSLList & list)
{
	// Two pointers to copy data
	IntNode *ptr1 = 0; 
	IntNode *ptr2 = 0;

	// First copy the head of the list
	if (list.head == 0)
		this->head = 0;
	else
	{
		this->head = new IntNode;
		this->head->data = list.head->data;
		ptr1 = this->head;
		ptr2 = list.head->next;
	}
	 
	// Copy remaining nodes
	while (ptr2 != NULL)
	{
		ptr1->next = new IntNode;
		ptr1 = ptr1->next;
		ptr1->data = ptr2->data;
		ptr2 = ptr2->next;
	}
	ptr1->next = NULL;
	this->tail = ptr1;
	// return the pointer
	return *this;
}


///////////////////////////////////////////////////////////////////////
// operator==
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator==(NodeSLList & list)
{
		bool flag = true; // flag is true if lists are equal, false otherwise
		IntNode *ptr1 = head;
		IntNode *ptr2 = list.head;
		while (ptr1 != NULL) // Traverse through lists and if data of any two nodes are unequal, set flag to false
		{
			if (ptr1->data != ptr2->data)
			{
				
				flag = false;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return flag;
	
}

///////////////////////////////////////////////////////////////////////
// operator!=
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator!=(NodeSLList & list)
{
	return(!(*this == list)); // Return inverse of equality operator
}

///////////////////////////////////////////////////////////////////////
// operator+
///////////////////////////////////////////////////////////////////////
NodeSLList NodeSLList::operator+(NodeSLList & list)
{
	NodeSLList firstList(*this);// Create a copy of the first list
	firstList.tail->next = list.head; // Make the last node of first list point to first node of second list
	return firstList; // return the concanated list
}

///////////////////////////////////////////////////////////////////////
// RetrieveNode
// 
// Description: retrieve data from a node without removing it from 
//              the list
// Input: node number (1-N; not 0-N-1)
// Output: none
// Returns: reference to node data
///////////////////////////////////////////////////////////////////////
IntNode & NodeSLList::RetrieveNode(int nodeNum) const
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	return *tmp;
}

///////////////////////////////////////////////////////////////////////
// operator<<
///////////////////////////////////////////////////////////////////////

ostream & operator<<(ostream & output, NodeSLList & list)
{
	
	IntNode* head = list.head;
	while (head != NULL) // Traverse the list and append the contents to the ostream object
	{
		output << " " << head->data << " ";
		head = head->next;
	}

	return output; // Return the ostream object
}

