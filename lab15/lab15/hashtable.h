// Programmer:  Yizhou Wang
// Section:     2
// Lab:         15
// Date:        April 13, 2014
// Description: Chained Hash Table Implementation

#include <iostream>
#include "iomanip"
using namespace std;

int const NUMOFSLOTS = 13;                  //size of this hashtable table

struct NodeType;                            //linked list structure used for chaining
typedef NodeType * NodePtr;                 //make the the pointer of a NodeType node point to the
                                            //  next NodeType node

struct NodeType
{
    int key;                                //key stored in the NodeType node
    NodePtr next;                           //the pointer of a NodeType node pointing to the
                                            //  next NodeType node
};

class hashtable
{
    public:
        hashtable();
        //POST: a default hashtable object is constructed
    
        int hashFunction(int k);
        //PRE:  k is initialized, and k >= 0
        //POST: FCTVAL = k mod NUMOFSLOTS
    
        void insertion(int new_key);
        //PRE:  new_key initialized and is not in some list in this hashtable
        //POST: new_key is inserted at the head of the correct list of this hashtable
    
        int search(int k);
        //PRE:  k is initialized
        //POST: FCTVAL = the distance from head to k in the linked list pointed to by
        //      slot[hashFunction(k)], if k exists in this hashtable;
        //      FCTVAL = -1 if k doesn't exist in any list of this hashtable
    
        double loadcalculate();
        //POST: FCTVAL = the load factor of this hashtable
    
        void drawing();
        //POST: this hashtable is drawn to the console in a neat fashion
    
    private:
        NodePtr slot[NUMOFSLOTS];                //a static array of pointers holding this hashtable
        int numofElements;                       //the logical size of this hashtable
};