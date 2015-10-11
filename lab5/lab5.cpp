// Programmer:  Yizhou Wang
// Section:     2  
// Lab:         4
// Date:        Feb. 10, 2014
// Description: Linked List Implementation -- a collection of methods that manipulate a 
// linked list to store integers: insertion, searching, concatenation traversing and deletion

#include <iostream>
using namespace std;

struct NodeType;								//Define a new data type NodeType
typedef NodeType* NodePtr;						//Give the type an alias

//The fields of each node of linked list
struct NodeType
{
	int data;
	NodePtr next;
};

NodePtr insertAtHead(NodePtr head, int datapoint)
//PRE:	head is initialized and points to a NodeType node or a NULL
//		 datapoint is initialized
//POST:	datapoint is inserted to the first position of the linked list that head points to
{
	//DATA DICTIONARY
	NodePtr temp;
	temp = new NodeType;						//A temporary pointer to hold the new node
	
	temp -> data = datapoint;					//Store the datapoint in the temp
	temp -> next = head;						//Make the temp's successor be the first node
	head = temp;								//Point head to the temp's pointee
	
	return head;
};

void insertAtTail(NodePtr head, int datapoint)
//PRE:	head is initialized and points to a NodeType node or a NULL
//		 datapoint is initialized 
//POST:	datapoint is inserted to the last position of the linked list that head points to
{
	//DATA DICTIONARY
	NodePtr tail;								//A pointer eventually will hold the last node 
	NodePtr temp;								//A temporary pointer to hold the new node
	
	tail = head;								//Set tail pointer starting at the head
	
	// Go through the linked list until the tail pointer points to the last node
	while (tail -> next != NULL)							
	{
		tail = tail -> next;
	}
	temp = new NodeType;						//Allocate the new temporary node
	temp -> data = datapoint;					//Store datapoint in the temp node
	temp -> next = NULL;						//Make temp's successor be NULL
	tail -> next = temp;						//Point tail's next to what temp points to
};

bool searching(NodePtr head, int k)
//PRE:  head is initialized and points to the first node of a linked list or a NULL
//		 k is initialized
//POST: FCTVAL == true when k is found in the list which head points to, and false ow.
{
	//DATA DICTIONARY
	bool keyInList;								//Availability of value key in the list
	NodePtr temp;								//A temporary pointer
    
	keyInList = false;
	temp = head;
    
	while(temp != NULL && keyInList == false)	//Walk list until node with value
													// key is found or there is no
													// more node                                                    
	{                                                   
		if(temp -> data == k)						//Check if key is the value of node
		{
			keyInList = true;
		}
		temp = temp -> next;						//Point temp to next node
	}

	return keyInList;
};

void concatenation(NodePtr head1, NodePtr head2)
//PRE:	head1 is initialized and points to a NodeType node or a NULL
//		head2 is initialized and points to a NodeType node or a NULL
//POST:	A linked list pointed by head1 is concatenated by a link list pointed by head2, 
//		 FCTVAL == a new linked list
{
	//DATA DICTIONARY
	NodePtr tail1;								//A pointer that will hold the last node of
												// the first linked list
	
	tail1 = head1;								//Set tail1 pointer starting at the head1
	
	// Go through head1 list until the tail1 points to the last node of head1
	while (tail1 -> next != NULL)							
	{
		tail1 = tail1 -> next;
	}
	
	tail1 -> next = head2;						//Make the tail1 points to the second list
	
};

void traverse(NodePtr head)
//PRE:	head is initialized and points to a NodeType node or a NULL
//POST: A linked list starting with head will be printed. There is a space between every
//		 two neighbouring elements
{
	//DATA DICTIONARY
	NodePtr cur;								//A temporary pointer to hold the node
												// we are going to print
	cur = head;									//Set cur started at the head of the linked list
	
	// Go through the list from the head of the tail and point every node
	while (cur != NULL)
	{
		cout << cur -> data << " ";
		cur = cur -> next;
	}
	cout << endl << endl;
}

NodePtr deleteNode(NodePtr head, int k)
//PRE:	head is initialized and points to the first node of a linked list
//		 Integer k is initialized and uniquely present in the list pointed by head
//POST:	If the linked list starting with head has a k node, k is deleted; ow, a linked list 
//		 remains the same
{
	//DATA DICTIONARY
	NodePtr pred;								//A pointer to the list node that will 
												// eventually hold the predecessor of the 
												// node to delete
	NodePtr cur;								//A pointer to a list node
	
	pred = NULL;								//Set pred pointing to NULL
	cur = head;									//Set cur starting at the head
	
	// Move the two pointer until the value k is found
	while (cur != NULL && cur -> data != k)
	{
		pred = cur;								//pred always points to the first node ahead of cur
		cur = cur -> next;
	}
	
	if(cur != NULL)                     		//The node with value k is found in the list
   {
        if(pred == NULL)                		//The k node is found at the beginning of the list
        {
            head = cur->next;					//Make the head circumvent the k node
        }
        else                            		//The found node is not the first node of list
        {
            pred->next = cur->next;				//Make the predecessor node circumvent the k node
        } 
        delete cur;                     		//Delete the node
    }    
      
    return head; 
}

int main()
{
	//DATA DICTIONARY
	NodePtr head1;                       		//Head of a linked list
	NodePtr head2;                      		//Head of another linked list
    
    //Allocate pointee for head1 and form a linked list with one node with value 1
    head1 = new NodeType;						//Allocate pointee for the head
    head1 -> data = 1;
    head1 -> next = NULL;
    cout << "1st linked list:" << endl;
    traverse(head1);
    
    //Allocate pointee for head2 and form a linked list with one node with value 100
    head2 = new NodeType;						//Allocate pointee for the head
    head2 -> data = 100;
    head2 -> next = NULL;
    cout << "2nd linked list:" << endl;
    traverse(head2);
    
    //Insert two nodes with 10 and 60 at the head of the linked list
    head1 = insertAtHead(head1, 10);
    head1 = insertAtHead(head1, 60);

    cout << "Test 1: insertion operation that inserts at the head of a list" << endl;
    cout << "1st linked list after inserting 10 and 60 at the head:" << endl;
    traverse(head1);
    
    
    //Insert two nodes with 55 and 33 at the tail of the head1
    insertAtTail(head1, 55);
	insertAtTail(head1, 33);    
    cout << "Test 2: insertion operation that inserts at the tail of a list" << endl;
    cout << "1st linked list after inserting 55 and 33 at the tail:" << endl;
    traverse(head1);
    
    
    //Check if 10 node is in the linked list
    cout << "Test 3: membership test operation that checks whether some value is in ";  
    cout << "a list or not" << endl;
    cout << "Is there any node in the list with key==10?"<< endl;
    cout << boolalpha << searching(head1, 10) << endl;
    cout << "Is there any node in the list with key==44?"<< endl;
    cout << boolalpha << searching(head1, 44) << endl;
    cout << endl;
  
    //Insert one node with 550 at the head of the linked list
    head2 = insertAtHead(head2, 550);
    cout << "2nd linked list after inserting 550 at the head:" << endl;
    traverse(head2);
    
    //Join two linked lists
    cout << "Test 4: operation that joins two lists into one" << endl;
    cout << "The new list after joining the 2nd list after the 1st list:" << endl;
    concatenation(head1, head2);
    traverse(head1);
    
    //Insert one node with 99 at the head of the new joined linked list, and insert one
    // node with 8 at the tail of the list
    head1 = insertAtHead(head1, 99);
    insertAtTail(head1, 8);
    cout << "The new linked list after inserting 99 at the head and 8 at the tail:"; 
    cout << endl;
    traverse(head1);

    //Delete three nodes from the list which are at the head, middle or tail respectively
    // of the list 
    cout << "Test 5: deletion operation that deletes a node in list" << endl;
    cout << "The new list after deleting nodes with value 99, 10, and 550:" << endl;
    head1 = deleteNode(head1, 99);
    head1 = deleteNode(head1, 10);
    head1 = deleteNode(head1, 550);
    traverse(head1);
	
	return 0;
};
