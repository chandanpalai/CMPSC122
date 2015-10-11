// Programmer:  Yizhou Wang
// Section:     2
// Lab:         15
// Date:        April 13, 2014
// Description: Chained Hash Table Implementation

#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    //test1
    cout << "***Test1: initialize a new hash table" << endl;
    hashtable table1;
    table1.drawing();

    cout << "The load factor of the current hash table is: " << setprecision(4)
         << table1.loadcalculate() << endl;
    cout << endl;
    
    //test2
    cout << "***Test2: insert integers from 1 to 8 (inclusively) "
         << "into the hash table and " << "try to find 50" << endl;
    for (int i=1; i <= 8; i++)
    {
        table1.insertion(i);
    }
    table1.drawing();
    
    cout << "The load factor of the current hash table is: "
         << table1.loadcalculate() << "." << endl;
    
    //look for 50
    cout << "Does 50 exist in this hash table?" << endl;
   
    if (table1.search(50) == -1)                            //if 50 doesn't exist in this hashtable
    {
        cout << "No, there is no 50 in the hash table.";
    }
    else                                                    //if 50 exists in this hashtable
    {
        cout << "Yes, its position in the list pointed to by slot "
             << 50 % NUMOFSLOTS << " is " << table1.search(50) << ".";
    }
    cout << endl << endl;
    
    //test3
    cout << "***Test3: insert 50, 60, 70, 80 into the hash table,"
         << " and try to find 50, 129, 2" << endl;
    
    table1.insertion(50);
    table1.insertion(60);
    table1.insertion(70);
    table1.insertion(80);

    table1.drawing();
    
    cout << "The load factor of the current hash table is: "
         << table1.loadcalculate() << "." <<endl;
    
    //look for 50
    cout << "Does 50 exist in this hash table?" << endl;
    
    if (table1.search(50) == -1)                            //if 50 doesn't exist in this hashtable
    {
        cout << "No, there is no 50 in the hash table.";
    }
    else                                                    //if 50 exists in this hashtable
    {
        cout << "Yes, its position in the list pointed to by slot "
             << 50 % NUMOFSLOTS << " is " << table1.search(50) << ".";
    }
    cout << endl << endl;
    
    //look for 129
    cout << "Does 129 exist in this hash table?" << endl;
    
    if (table1.search(129) == -1)                           //if 129 doesn't exist in this hashtable
    {
        cout << "No, there is no 129 in the hash table.";
    }
    else                                                    //if 129 exists in this hashtable
    {
        cout << "Yes, its position in the list pointed to by slot "
        << 129 % NUMOFSLOTS << " is " << table1.search(129) << ".";
    }
    cout << endl << endl;
    
    //look for 2
    cout << "Does 2 exist in this hash table?" << endl;
    
    if (table1.search(2) == -1)                             //if 2 doesn't exist in this hashtable
    {
        cout << "No, there is no 2 in the hash table.";
    }
    else                                                    //if 2 exists in this hashtable
    {
        cout << "Yes, its position in the list pointed to by slot "
        << 2 % NUMOFSLOTS << " is " << table1.search(2) << ".";
    }
    cout << endl << endl;
    
    return 0;
}

