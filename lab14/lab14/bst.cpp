// Programmer:  Yizhou Wang
// Section:     2
// Lab:         14 - Binary Search Trees
// Date:        April 8, 2014
// Description: A practice to implement binary search tree (bst) with class

#include "bst.h"

bst::bst()
//POST: a default bst object is constructed with subroot = NULL
{
    //initialize the subroot
    subroot = NULL;
}

bst::bst(int a[], int size)
//PRE:  a[0..size-1] is initialized, all members of a[0..size] are unique
//      0 <= size <= LOGICALSIZE
//POST: a bst object is constructed from a[]

{
    //initialize the subroot
    subroot = NULL;
    
    for (int i=0;i<size;i++)             //insert all the elements of a[] into this bst
    {
        insert_helper(a[i]);
    }
}

void bst::insert_helper(int value)
//PRE:  value is initialized and distinct from other values stored in this bst
//POST: value is inserted into this bst at the right place
{
    insert(subroot, value);
}

void bst::insert(TreeNodePtr & subroot, int value)
//PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys or is a
//      NULL, value is initialized and distinct from other values stored in this bst
//POST: value is inserted into this bst at the right place
{
    
    if (subroot == NULL)              //if subroot is NULL, initialize the subroot node of this bst
                                      //  with key = value, left = NULL and right = NULL
    {
        subroot = new TreeNodeType;
        subroot->key = value;
        subroot->left = NULL;
        subroot->right = NULL;
    }
    else if (value < subroot->key)    //if value is smaller than key of the current node of this bst,
                                      //  go to the left branch
    {
        insert(subroot->left, value);
    }
    else                              //if value is greater than key of the current node of this bst,
                                      //  go to the right branch
    {
        insert(subroot->right, value);
    }
}

bool bst::searchBST1_helper(int value)
//PRE:  value is initialized
//POST: FCTVAL = true if value is found in this bst
//      FCTVAL = false if value cann't be found in this bst
{
    return searchBST1(subroot, value);
}

bool bst::searchBST1(TreeNodePtr subroot, int value)
//PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys or is
//      a NULL, value is initialized
//POST: FCTVAL = true if value is found in this bst
//      FCTVAL = false if value cann't be found in this bst
{
    if (subroot == NULL)                                //if this bst is NULL or value is not found
                                                        //  in this bst
    {
        return false;
    }
    else if (subroot->key == value)                     //if value is found at the current node of
                                                        //  of this bst
    {
        return true;
    }
    else if (value < subroot->key)                      //if value is smaller than the current node
                                                        //  of this bst
    {
        return searchBST1(subroot->left, value);
    }
    else                                                //if value is greater than the current node
                                                        //  of this bst
    {
        return searchBST1(subroot->right, value);
    }
}

void bst::searchBST2_helper(int value)
//PRE:  value is initialized
//POST: the process of searching is printed to the console in a stepwise fashion,
//      the result of the search is printed to the last line
{
    return searchBST2(subroot, value);
}

void bst::searchBST2(TreeNodePtr subroot, int value)
//PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys or is
//      a NULL, value is initialized
//POST: the process of searching is printed to the console in a stepwise fashion
//      the result of the search is printed to the last line
{
    if (subroot == NULL)                                //if this bst is NULL or value is not found
                                                        //  in this bst
    {
        cout << value <<" does not exist in the BST."
             <<" Try a different value." << endl;
    }
    else if (subroot->key == value)                     //if value is found at the current node of
                                                        //  of this bst
    {
        cout << "Checking " << subroot->key << " node."
             << "Does match " << value
             << ". So we find the key." << endl;
    }
    else if (value < subroot->key)                      //if value is smaller than the current node
                                                        //  of this bst
    {
        cout << "Checking " << subroot->key << " node."
             << "Does not match " << value << ". "
             << value << " < " << subroot->key
             << ". So go left" << endl;
        
        searchBST2(subroot->left, value);
    }
    else                                                //if value is greater than the current node
                                                        //  of this bst
    {
        cout << "Checking " << subroot->key << " node."
             << "Does not match " << value << ". "
             << value << " > " << subroot->key
             << ". So go right" << endl;
        
        searchBST2(subroot->right, value);
    }
}

void bst::traverseBST_inorder_helper()
//POST: an inorder traversal of this bst is printed to the console
{
    cout << "Inorder Traversal of the binary search tree: " << endl;
    traverseBST_inorder(subroot);
    cout << endl;
}


void bst::traverseBST_inorder(TreeNodePtr subroot)
//PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys or is
//      a NULL
//POST: an inorder traversal of this bst is printed to the console
{
    if(subroot != NULL)                        //Not an empty tree node
    {
        traverseBST_inorder(subroot -> left);
        cout << subroot -> key << " ";
        traverseBST_inorder(subroot -> right);
    }
}

void bst::traverseBST_postorder_helper()
//POST: a postorder traversal of this bst is printed to the console
{
    cout << "Postorder Traversal of the binary search tree:" << endl;
    traverseBST_postorder(subroot);
    cout << endl;
}

void bst::traverseBST_postorder(TreeNodePtr subroot)
//PRE:  subroot points to the subroot node of a subtree of this bst containing unique keys or is
//      a NULL
//POST: a postorder traversal of this bst is printed to the console
{
    if(subroot != NULL)
    {
        traverseBST_postorder(subroot->left);
        traverseBST_postorder(subroot->right);
        cout << subroot -> key << " ";
    }
}




