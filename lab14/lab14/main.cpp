// Programmer:  Yizhou Wang
// Section:     2
// Lab:         14 - Binary Search Trees
// Date:        April 8, 2014
// Description: A practice to implement binary search tree (bst) with class

#include <iostream>
#include "bst.h"
using namespace std;

void treeSort(int data[], int size)
//PRE:  b[0..size-1] is initialized and 0 <= size <= LOGICALSIZE
//POST: elements of b[] are printed inorderly to the console in one raw
{
    bst test1(data, size);
    test1.traverseBST_inorder_helper();
}

int main()
{
    //DATA DICTIONARY
    int a[8];                   //data array for test1
    
    //initilization of test1
    a[0]= 5;
    a[1]= 10;
    a[2]= 3;
    a[3]= 0;
    a[4]= 20;
    a[5]= -3;
    a[6]= 4;
    a[7]= 9;
    
    bst test1(a,8);
    
    cout << "Here below is the array data for test1: " << endl;
    for (int i=0; i<8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    //test the default constructor
    bst test2;
    
    //test the insert method
    test2.insert_helper(5);
    test2.insert_helper(8);
    test2.insert_helper(-1);
    
    
    //test the searchBST1_helper and searchBST2-helper method
    cout << "Is 9 in test1?" << endl;
    cout << boolalpha << (test1.searchBST1_helper(9));
    cout << endl;
    cout << "Here below are are the stepwise comparisons:" << endl;
    test1.searchBST2_helper(9);
    cout << endl;
    
    //test the traverseBST_inorder_helper method and traverseBST_postorder_helper
    cout << "Here below is the inorder traversal of test2" << endl;
    test2.traverseBST_inorder_helper();
    cout << endl;
    cout << "Here below is the postorder traversal of test2" << endl;
    test2.traverseBST_postorder_helper();
    cout <<endl;
    
    //test for treeSort
    cout << "Here below is the original array of test1:" << endl;
    for (int i=0; i<8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << "Here below is the array after treeSort:" << endl;
    treeSort(a, 8);

    return 0;
}


