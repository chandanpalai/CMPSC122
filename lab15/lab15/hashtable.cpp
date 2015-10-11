// Programmer:  Yizhou Wang
// Section:     2
// Lab:         15
// Date:        April 13, 2014
// Description: Chained Hash Table Implementation

#include "hashtable.h"

hashtable::hashtable()
//POST: a default hashtable object is constructed
{
    for (int i=0; i < NUMOFSLOTS; i++)          //all the slots of this hashtable are initialized
                                                //  to null
    {
        slot[i] = NULL;
    }
    
    numofElements = 0;                          //initialize the load factor of hash table
    
};

int hashtable::hashFunction(int k)
//PRE:  k is initialized, and k >= 0
//POST: FCTVAL = k mod NUMOFSLOTS
{
    return k % NUMOFSLOTS;                      //return the slot number of the slot k is going to
}

void hashtable::insertion(int new_key)
//PRE:  new_key initialized and is not in some list in this hashtable
//POST: new_key is inserted at the head of the correct list of this hashtable
{
    //DATA DICTIONARY
    NodePtr temp;                                               //a temporary NodeType pointer
                                                                //  holding new_key

    if (slot[hashFunction(new_key)] == NULL)                    //if the list of the slot is empty
    {
        slot[hashFunction(new_key)] = new NodeType;             //allocate a new NodeType node
        slot[hashFunction(new_key)] -> key = new_key;           //store new_key as the key of the
                                                                //  NodeType node
        slot[hashFunction(new_key)] -> next = NULL;             //point the pointer to NULL
    }
    else
    {
        temp = new NodeType;                                    //allocate a NodeType node holding
                                                                //  new_key
        temp -> key = new_key;
      
        //make temp the new head node of the list
        temp -> next = slot[hashFunction(new_key)];
        slot[hashFunction(new_key)] = temp;
    }
    numofElements ++;                                           //increase logical size of this
                                                                //  hashtable by 1
};

int hashtable::search(int k)
//PRE:  k is initialized
//POST: FCTVAL = the distance from head to k in the linked list pointed to by slot[hashFunction(k)],
//      if k exists in this hashtable;
//      FCTVAL = -1 if k doesn't exist in any list of this hashtable
{
    //DATA DICTIONARY
    NodePtr cur;                            //a pointer pointing to the node we are intestigating
    int count;                              //a counter counting the position of k in the list
    bool found;                             //an indicator whether k is in the list of this hashtable
    
    cur = slot[hashFunction(k)];
    count = 0;
    found = false;
    
    while (cur != NULL && found == false)   //traverse the link list to its end or intil finding k
    {
        if (cur -> key == k)
        {
            found = true;
        }
        cur = cur -> next;
        count ++;
    }
    
    if(found == true)                       //if k is found in the list of this hashtable
    {
        return count;
    }
    else                                    //if k is not found in the list of this hashtable
    {
        return -1;
    }
};

double hashtable::loadcalculate()
//POST: FCTVAL = the load factor of this hashtable with decimal digits
{
    return (numofElements * 1.0 / NUMOFSLOTS);
}

void hashtable::drawing()
//POST: this hashtable is drawn to the console in a neat fashion
{
    //DATA DICTIONARY
    NodePtr cur;                                            //a pointer pointing to the node we are
                                                            //  intestigating
    
    cout << "Here below is the hash table"
         << " you have implementated:" << endl;
    
    for (int i=0; i < NUMOFSLOTS; i++)                      //print slot[NUMOFSLOTS] and their lists
                                                            //  line by line
    {
        cout << "Slot " << setw(2) << i << ":";
        cur = slot[i];
        
        if (cur == NULL)                                    //if there is no list pointed to by the
                                                            //  slot, draw "/"
        {
            cout << "/";
        }
        else                                                //if there is a list pointed to by the
                                                            //  slot
       {
            while (cur != NULL)                             //traverse the list and print every node
                                                            //  connected by arrows
            {
                cout << " --> " << setw(3) << cur -> key;
                cur = cur -> next;
            }
           
        }
        cout << endl;
    }
};
