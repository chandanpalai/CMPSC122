// Programmer:  Yizhou Wang
// Section:     2
// Lab:         14 - Binary Search Trees
// Date:        April 8, 2014
// Description: A practice to implement binary search tree (bst) with class

#include <iostream>
using namespace std;

const int LOGICALSIZE = 100;                    //the maximum number of nodes a bst can have

struct TreeNodeType;                            //a new data type TreeNodeType
typedef TreeNodeType * TreeNodePtr;             //the type of what TreeNodePtr points to is
                                                //  TreeNodeType

struct TreeNodeType
{
    int key;                                    //value stored in this node
    TreeNodePtr left;                           //pointer pointing to the left child of the node
    TreeNodePtr right;                          //pointer pointing to the right child of the node;
};

class bst
{
    public:
        bst();
        //POST: a default bst object is constructed with subroot = NULL
    
        bst(int a[], int size);
        //PRE:  a[0..size-1] is initialized, all members of a[0..size] are unique
        //      0 <= size <= LOGICALSIZE
        //POST: a bst object is constructed from a[]
    
        void insert_helper(int value);
        //PRE:  value is initialized and distinct from other values stored in this bst
        //POST: value is inserted into this bst at the right place
    
        bool searchBST1_helper(int value);
        //PRE:  value is initialized
        //POST: FCTVAL = true if value is found in this bst
        //      FCTVAL = false if value cann't be found in this bst
    
        void searchBST2_helper(int value);
        //PRE:  value is initialized
        //POST: the process of searching is printed to the console in a stepwise fashion,
        //      the result of the search is printed to the last line
    
        void traverseBST_inorder_helper();
        //POST: an inorder traversal of this bst is printed to the console
    
        void traverseBST_postorder_helper();
        //POST: a postorder traversal of this bst is printed to the console
    
    private:
        TreeNodePtr subroot;                       //a pointer to the subroot of this bst
    
        void insert(TreeNodePtr & subroot,int value);
        //PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys
        //      or is a NULL, value is initialized and distinct from other values stored in this bst
        //POST: value is inserted into this bst at the right place

        bool searchBST1(TreeNodePtr subroot, int value);
        //PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys
        //      or is a NULL, value is initialized
        //POST: FCTVAL = true if value is found in this bst
        //      FCTVAL = false if value cann't be found in this bst
    
        void searchBST2(TreeNodePtr subroot, int value);
        //PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys
        //      or is a NULL, value is initialized
        //POST: the process of searching is printed to the console in a stepwise fashion
        //      the result of the search is printed to the last line
    
        void traverseBST_inorder(TreeNodePtr subroot);
        //PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys
        //      or is a NULL
        //POST: an inorder traversal of this bst is printed to the console
    
        void traverseBST_postorder(TreeNodePtr subroot);
        //PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys
        //      or is a NULL
        //POST: a postorder traversal of this bst is printed to the console

};


