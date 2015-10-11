// Programmer:  Yizhou Wang
// Section:     2  
// Lab:         4
// Date:        Feb. 05, 2014
// Description: Linked List Implementation -- a collection of methods that manipulate a 
// linked list to store integers: insertion, searching, concatenation traversing and deletion

#include <iostream>
using namespace std;

struct NodeType;						//Define a new data type NodeType
typedef NodeType* NodePtr;				//Give the type an alias

//The fields of each node of linked list
struct NodeType
{
	int data;
	NodePtr next;
};

void insertion_head(NodePtr head, int datapoint)
//PRE:	head is initialized and points to the first node of a linked list, if the linked list 
//		 exists
//		datapoint is initialized and it is the point that will be inserted into a linked list 
//		 starting with head
//POST:	A datapoint is inserted to the first position of a linked list
{
	
}

void insertion_tail(NodePtr head, int datapoint)
//PRE:	head is initialized and points to the first node of a linked list, if the linked list 
//		 exists
//		datapoint is initialized and it is the point that will be inserted into a linked list
//		 starting with head
//POST:	A datapoint is inserted to the last position of a linked list
{
	
}

void searching(NodePtr head, int k)
//PRE:	head is initialized and points to the first node of a linked list, if the linked list 
//		 exists
//		Integer k is initialized and is the value that is being checked if is available in the 
//		 list
//POST:	FCTVAL == true when key is found in the list which head points to, and FCTVAL == false ow
{
	
}

void concatenation(NodePtr head1, NodePtr head2)
//PRE:	head1 is initialized and points to the first node of a linked list, if the linked list 
//		 exists
//		head2 is initialized and points to the first node of another linked list, if the linked 
//		 list exists
//POST:	A linked list pointed by head1 is concatenated by a link list pointed by head2, 
//		 FCTVAL == a new linked list
{
	
}

void traverse(NodePtr head)
//PRE:	head is initialized and points to the first node of a linked list, if the linked list 
//		 exists
//POST: A linked list starting with head will be printed. There is a space between every
//		 two neighbouring elements
{
	
}

void delete(NodePtr head, int k)
//PRE:	head is initialized and points to the first node of a linked list
//		Integer k is initialized and is the value of a datapoint that is being deleted
//POST:	If a linked list has a datapoint k, k is deleted; ow, a linked list remains the same


int main()
{
	
};
