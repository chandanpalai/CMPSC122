// Programmer:  Yiting Ju
// Section:     2
// Lab:         Final Project
// Date:        April. 26, 2014
// Description: Empirical Running Time Analysis of Sorting

#include <iostream>
#include <iomanip>
#include <cstdlib>  //for random number generator
#include <ctime>    //for time method so we can seed the generator

using namespace std;

const int MAX_ARRAY_SIZE = 10000;    //maximum number of elements in array to support
//  used for Merge Sort
const int RANDOM_NUMBER_RANGE = 100;

//---Sorting Algorithm---

//---swapWords function used for Selection Sort, Bubble Sort and Quick Sort--
void swapWords(int& a, int& b)
//PRE:  a and b are initialized
//POST: a and b are swapped in the position
{
    //DATA DICTIONARY
    int temp;   //a temporary variable to hold the variable getting swapped
    
    temp = b;
    b = a;
    a = temp;
}

void selectionSort(int data[], int size)
//PRE:  size > 1, and data[0..(size-1)] is initialized
//POST: data[0..(size-1)] is sorted in ascending order
{
    //DATA DICTIONARY
    int maxIndex;   //the index of the largest element among those that have been
    //  inspected
    
    //traverse elements in data[0..(size-1)] from (size-1) to 1, swap elements to sort
    //  data[0..(size-1)] into ascending order
    for(int bottom = size - 1; bottom >= 1; bottom--)
    {
        maxIndex = 0;
        //find the largest element in data[0..bottom]
        for(int i = 1; i <= bottom; i++)
        {
            if(data[i] > data[maxIndex])    //set maxIndex to be the index of the
                //  larger element
            {
                maxIndex = i;
            }
        }
        
        swapWords(data[bottom], data[maxIndex]);
    }
}

void selectionSortR(int data[], int size)
//PRE:  size > 1, and data[0..(size-1)] is initialized
//POST: data[0..(size-1)] is sorted in descending order
{
    //DATA DICTIONARY
    int maxIndex;   //the index of the largest element among those that have been
    //  inspected
    
    //traverse elements in data[0..(size-1)] from (size-1) to 1, swap elements to sort
    //  data[0..(size-1)] into descending order
    for(int bottom = size - 1; bottom >= 1; bottom--)
    {
        maxIndex = 0;
        //find the largest element in data[0..bottom]
        for(int i = 1; i <= bottom; i++)
        {
            if(data[i] < data[maxIndex])    //set maxIndex to be the index of the
                //  larger element
            {
                maxIndex = i;
            }
        }
        
        swapWords(data[bottom], data[maxIndex]);
    }
}

void bubbleSort(int data[], int size)
//PRE:  size > 0 and data[0..(size-1)] is initialized
//POST: data[0..(size-1)] is sorted in ascending order
{
    //At the "bottom"th iteration, data[bottom+1..size-1] is the subarray that has been
    //  sorted, data[0..bottom] is the subarray to be sorted. Two consecutive elements
    //  form one comparison, we need (size-1)-1+1 = size-1 comparisons to move size-1
    //  larger elements to bottom in ascending order
    for (int bottom = size-1; bottom>=1; bottom--)
    {
        //for the ith iteration, we need (bottom-1)-i+1 = bottom-i comparisons to move
        //  the largest element in data[0..bottom-1] to the position data[bottom]
        for (int i=0; i<=bottom-1; i++)
        {
            if (data[i+1] < data[i])        //if data[i+1] < data[i], swap data[i+1]
                                            //  and data[i]
            {
                swap(data[i+1], data[i]);
            }
        }
    }
}

void bubbleSortR(int data[], int size)
//PRE:  size > 0 and data[0..(size-1)] is initialized
//POST: data[0..(size-1)] is sorted in descending order
{
    //At the "bottom"th iteration, data[bottom+1..size-1] is the subarray that has been
    //  sorted, data[0..bottom] is the subarray to be sorted. Two consecutive elements
    //  form one comparison, we need (size-1)-1+1 = size-1 comparisons to move size-1
    //  larger elements to bottom in descending order
    for (int bottom = size-1; bottom>=1; bottom--)
    {
        //for the ith iteration, we need (bottom-1)-i+1 = bottom-i comparisons to move
        //  the largest element in data[0..bottom-1] to the position data[bottom]
        for (int i=0; i<=bottom-1; i++)
        {
            if (data[i+1] > data[i])        //if data[i+1] < data[i], swap data[i+1]
                //  and data[i]
            {
                swap(data[i+1], data[i]);
            }
        }
    }
}

void insertionSort(int data[], int size)
//PRE:  size > 1, and data[0..(size-1)] is initialized
//POST: data[0..(size-1)] is sorted in ascending order, containing same values stored in
//      data[0..(size-1)] at the time of invocation
{
    //DATA DICTIONARY
    int key;    //the value of the element in the array that is being inspected
    int i;      //temporary index for the values being inspected
    
    //take each element of data[0..(size-1)] and insert it into data[0..(j-1)]
    //  where it goes
    for(int j = 1; j < size; j++)
    {
        key = data[j];
        
        i = j - 1;      //shift data[0..j-1] s.t. there is an appropriate slot
        //  in data[0..j] for key
        
        //shift every element in data[0..j-1] to following slot if it is larger
        //  than key
        while(i >= 0 && data[i] > key)
        {
            data[i+1] = data[i];
            i = i - 1;
        }
        
        data[i+1] = key;
    }
}

void insertionSortR(int data[], int size)
//PRE:  size > 1, and data[0..(size-1)] is initialized
//POST: data[0..(size-1)] is sorted in ascending order, containing same values stored in
//      data[0..(size-1)] at the time of invocation
{
    //DATA DICTIONARY
    int key;    //the value of the element in the array that is being inspected
    int i;      //temporary index for the values being inspected
    
    //take each element of data[0..(size-1)] and insert it into data[0..(j-1)]
    //  where it goes
    for(int j = 1; j < size; j++)
    {
        key = data[j];
        
        i = j - 1;      //shift data[0..j-1] s.t. there is an appropriate slot
        //  in data[0..j] for key
        
        //shift every element in data[0..j-1] to following slot if it is larger
        //  than key
        while(i >= 0 && data[i] < key)
        {
            data[i+1] = data[i];
            i = i - 1;
        }
        
        data[i+1] = key;
    }
}

//---partition function used for Quick Sort---
int partition(int a[], int p, int q)
//PRE:  q >= p, and a[p..q] is initialized
//POST: a[p..FCTVAL] contains all values from a[p..q] at the time of invocation less
//      than or equal to a[q] at the time of invocation, and a[FCTVAL..q] contains all
//      values from a[p..q] at the time of invocation greater than a[q] at the time of
//      invocation
{
    //DATA DICTIONARY
    int pivot;      //a value used to partition the array
    int m;          //index of the largest element smaller than or equals to pivot
    
    pivot = a[q];   //set the last element in a[p..q] to be the pivot
    m = p - 1;
    
    for(int i = p; i <= q-1; i++)   //inspect every element in a[p..(q-1)], and get
        // the index that pivot belongs to
    {
        if(a[i] < pivot)    //partition elements: ensure the elements smaller than the
            //  pivot are all placed left to the elements larger than
            //  the pivot
        {
            m++;
            swapWords(a[i], a[m]);
        }
    }
    
    swapWords(a[m + 1], a[q]);   //swap to place the pivot to where it belongs to
    
    return m + 1;
}

void quickSort(int a[], int p, int q)
//PRE:  q >= p, and a[p..q] is initialized
//POST: a[p..q] contains all values from a[p..q] at the time of invocation that are
//      sorted in ascending order
{
    //DATA DICTIONARY
    int pivotIndex;     //index of pivot which is used to partition the array
    
    if(q > p)
    {
        pivotIndex = partition(a, p, q);
        quickSort(a, p, pivotIndex-1);
        quickSort(a, pivotIndex+1, q);
    }
}

//---partitionR function used for Quick Sort R---
int partitionR(int a[], int p, int q)
//PRE:  q >= p, and a[p..q] is initialized
//POST: a[p..FCTVAL] contains all values from a[p..q] at the time of invocation less
//      than or equal to a[q] at the time of invocation, and a[FCTVAL..q] contains all
//      values from a[p..q] at the time of invocation greater than a[q] at the time of
//      invocation
{
    //DATA DICTIONARY
    int pivot;      //a value used to partition the array
    int m;          //index of the largest element smaller than or equals to pivot
    
    pivot = a[q];   //set the last element in a[p..q] to be the pivot
    m = p - 1;
    
    for(int i = p; i <= q-1; i++)   //inspect every element in a[p..(q-1)], and get
        // the index that pivot belongs to
    {
        if(a[i] > pivot)    //partition elements: ensure the elements smaller than the
            //  pivot are all placed left to the elements larger than
            //  the pivot
        {
            m++;
            swapWords(a[i], a[m]);
        }
    }
    
    swapWords(a[m + 1], a[q]);   //swap to place the pivot to where it belongs to
    
    return m + 1;
}

void quickSortR(int a[], int p, int q)
//PRE:  q >= p, and a[p..q] is initialized
//POST: a[p..q] contains all values from a[p..q] at the time of invocation that are
//      sorted in ascending order
{
    //DATA DICTIONARY
    int pivotIndex;     //index of pivot which is used to partition the array
    
    if(q > p)
    {
        pivotIndex = partitionR(a, p, q);
        quickSortR(a, p, pivotIndex-1);
        quickSortR(a, pivotIndex+1, q);
    }
}

//---merge function used for Merge Sort---
void merge(int a[], int lStartIndex, int lSize, int rSize)
//PRE:  lStartIndex >= 0, lSize > 0, rSize > 0, and lStartIndex + lSize + rSize
//      <= physical size of a; a[lStartIndex..(lStartIndex + lSize + lSize - 1)] is
//      initialized
//POST: a[lStartIndex..(lStartIndex + lSize + rSize - 1)] contains all elements stored
//      in a[lStartIndex..(lStartIndex + lSize + rSize - 1)] when invocation, sorted in
//      ascending order
{
    //DATA DICTIONARY
    int lIndex;                 //index of left list
    int rIndex;                 //index of right list
    int lLastIndex;             //last index of left list
    int rLastIndex;             //last index of right list
    int b[MAX_ARRAY_SIZE];      //an array to store temporary result
    int bIndex;                 //index of b
    
    lIndex = lStartIndex;
    rIndex = lStartIndex + lSize;   //initialized to the first index of right list
    lLastIndex = lStartIndex + lSize - 1;
    rLastIndex = rIndex + rSize - 1;
    bIndex = lStartIndex;
    
    //go through each elements in a[lStartIndex...lLastIndex] and
    //  a[rStartIndex...rLastIndex] until the traversal of one array reaches end, and
    //  store these elements into b[lStartIndex..rLastIndex] in ascending order
    while(lIndex <= lLastIndex && rIndex <= rLastIndex)
    {
        if(a[lIndex] <= a[rIndex])      //the element in the left list is smaller than
            //  that in the right list
        {
            b[bIndex] = a[lIndex];
            lIndex++;
        }
        else                            //the element in the right list is smaller than
            //  that in the left list
        {
            b[bIndex] = a[rIndex];
            rIndex++;
        }
        bIndex++;
    }
    
    if(lIndex <= lLastIndex)        //left list is not totally traversed
    {
        //copy all rest elements in the left list to b
        for(int i = lIndex; i <= lLastIndex; i++)
        {
            b[bIndex] = a[i];
            bIndex++;
        }
    }
    else                            //right list is not totally traversed
    {
        //copy all rest elements in the right list to b
        for(int i = rIndex; i <= rLastIndex; i++)
        {
            b[bIndex] = a[i];
            bIndex++;
        }
    }
    
    //copy all values in b[lStartIndex..(lStartIndex + lSize + rSize - 1)] to
    //  a[lStartIndex..(lStartIndex + lSize + rSize - 1)]
    for(int i = lStartIndex; i <= bIndex-1; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int firstIndex, int lastIndex)
//PRE:  firstIndex <= lastIndex, and a[firstIndex...lastIndex] is initialized
//POST: a[firstIndex..lastIndex] contains all elements in a[firstIndex...lastIndex]
//      when invocation, in ascending order
{
    //DATA DICTIONARY
    int m;      //midpoint
    
    if(firstIndex < lastIndex)      //divide when possible
    {
        m = (firstIndex + lastIndex) / 2;
        
        //divide and conquer
        mergeSort(a, firstIndex, m);
        mergeSort(a, m+1, lastIndex);
        
        //combine with sorting
        merge(a, firstIndex, m-firstIndex+1, lastIndex-m);
    }
}

//---mergeR function used for Merge Sort R---
void mergeR(int a[], int lStartIndex, int lSize, int rSize)
//PRE:  lStartIndex >= 0, lSize > 0, rSize > 0, and lStartIndex + lSize + rSize
//      <= physical size of a; a[lStartIndex..(lStartIndex + lSize + lSize - 1)] is
//      initialized
//POST: a[lStartIndex..(lStartIndex + lSize + rSize - 1)] contains all elements stored
//      in a[lStartIndex..(lStartIndex + lSize + rSize - 1)] when invocation, sorted in
//      ascending order
{
    //DATA DICTIONARY
    int lIndex;                 //index of left list
    int rIndex;                 //index of right list
    int lLastIndex;             //last index of left list
    int rLastIndex;             //last index of right list
    int b[MAX_ARRAY_SIZE];      //an array to store temporary result
    int bIndex;                 //index of b
    
    lIndex = lStartIndex;
    rIndex = lStartIndex + lSize;   //initialized to the first index of right list
    lLastIndex = lStartIndex + lSize - 1;
    rLastIndex = rIndex + rSize - 1;
    bIndex = lStartIndex;
    
    //go through each elements in a[lStartIndex...lLastIndex] and
    //  a[rStartIndex...rLastIndex] until the traversal of one array reaches end, and
    //  store these elements into b[lStartIndex..rLastIndex] in ascending order
    while(lIndex <= lLastIndex && rIndex <= rLastIndex)
    {
        if(a[lIndex] >= a[rIndex])      //the element in the left list is smaller than
            //  that in the right list
        {
            b[bIndex] = a[lIndex];
            lIndex++;
        }
        else                            //the element in the right list is smaller than
            //  that in the left list
        {
            b[bIndex] = a[rIndex];
            rIndex++;
        }
        bIndex++;
    }
    
    if(lIndex <= lLastIndex)        //left list is not totally traversed
    {
        //copy all rest elements in the left list to b
        for(int i = lIndex; i <= lLastIndex; i++)
        {
            b[bIndex] = a[i];
            bIndex++;
        }
    }
    else                            //right list is not totally traversed
    {
        //copy all rest elements in the right list to b
        for(int i = rIndex; i <= rLastIndex; i++)
        {
            b[bIndex] = a[i];
            bIndex++;
        }
    }
    
    //copy all values in b[lStartIndex..(lStartIndex + lSize + rSize - 1)] to
    //  a[lStartIndex..(lStartIndex + lSize + rSize - 1)]
    for(int i = lStartIndex; i <= bIndex-1; i++)
    {
        a[i] = b[i];
    }
}

void mergeSortR(int a[], int firstIndex, int lastIndex)
//PRE:  firstIndex <= lastIndex, and a[firstIndex...lastIndex] is initialized
//POST: a[firstIndex..lastIndex] contains all elements in a[firstIndex...lastIndex]
//      when invocation, in ascending order
{
    //DATA DICTIONARY
    int m;      //midpoint
    
    if(firstIndex < lastIndex)      //divide when possible
    {
        m = (firstIndex + lastIndex) / 2;
        
        //divide and conquer
        mergeSortR(a, firstIndex, m);
        mergeSortR(a, m+1, lastIndex);
        
        //combine with sorting
        mergeR(a, firstIndex, m-firstIndex+1, lastIndex-m);
    }
}

//---BST class to support Tree Sort---
struct TreeNodeType;
typedef TreeNodeType* TreeNodePtr;              //give the type an alias

//Node for binary trees
struct TreeNodeType
{
    int key;                //value stored in the node
    TreeNodePtr left;       //pointer pointing to the node's left child
    TreeNodePtr right;      //pointer pointing to the node's right child
};

class BST
{
public:
    BST();
    //POST: a default BST object is constructed with root set to NULL
    
    BST(int data[], int size);
    //PRE:  size > 0, and data[0..(size-1)] is initialized
    //POST: a BST object is constructed with root pointing a tree where each value of
    //      data[0..(size-1)] stores in a node
    
    void insertKey(int v);
    //PRE:  v is distinct from other values stored in the tree
    //POST: this BST object gets a new node that stores value v
    
    void traversalInorder(int sortedResult[], int maxSize);
    //PRE:  maxSize >= number of elements stored in this BST object, and sortedResult
    //       has physical size of maxSize
    //POST: sortedResult[0..maxSize] contains all values stored in this BST object in
    //      ascending order
    
    void traversalInorderR(int sortedResult[], int maxSize);
    
private:
    TreeNodePtr root;   //pointer to the root of a binary search tree
    
    void insert(TreeNodePtr& subRoot, int v);
    //PRE:  subRoot is initialized to point to a node in this BST object, and v is
    //      distinct from other values stored in this BST object
    //POST: this BST object gets a new node that stores value v in a subtree whose
    //      root is subRoot
    
    void traversalInorderPrivate(TreeNodePtr& subRoot, int sortedResult[], int& size);
    //PRE:  subRoot is initialized to point to a node in this BST object,
    //      sortedResult has physical size larger than the number of values stored
    //      in this BST object, and size >= 0
    //POST: sortedResult[0..(size-1)] contains all values in-orderly stored in the keys
    //      which are in the "children" treenodes of subRoot
    
    void traversalInorderPrivateR(TreeNodePtr& subRoot, int sortedResult[], int& size);
};

BST::BST()
//POST: a default BST object is constructed with root set to NULL
{
    root = NULL;
}

BST::BST(int data[], int size)
//PRE:  size > 0, and data[0..(size-1)] is initialized
//POST: a BST object is constructed with root pointing a tree where each value of
//      data[0..(size-1)] stores in a node
{
    //insert every value stored in data[0..(size-1)] into a node of this BST object
    root = NULL;
    for(int i = 0; i < size; i++)
    {
        insertKey(data[i]);
    }
}

void BST::insertKey(int v)
//PRE:  v is distinct from other values stored in the tree
//POST: this BST object gets a new node that stores value v
{
    insert(root, v);
}

void BST::insert(TreeNodePtr & subRoot, int v)
//PRE:  subRoot is initialized to point to a node in this BST object, and v is
//      distinct from other values stored in this BST object
//POST: this BST object gets a new node that stores value v in a subtree whose
//      root is subRoot
{
    if(subRoot == NULL)             //empty subtree
    {
        subRoot = new TreeNodeType;
        subRoot -> key = v;
        subRoot -> left = NULL;
        subRoot -> right = NULL;
    }
    else if(v >= subRoot -> key)     //v is larger than the key in the subRoot node
    {
        insert(subRoot -> right, v);
    }
    else                            //v is smaller than the key in the subRoot node
    {
        insert(subRoot -> left, v);
    }
}

void BST::traversalInorder(int sortedResult[], int maxSize)
//PRE:  maxSize >= number of elements stored in this BST object, and sortedResult has
//      physical size of maxSize
//POST: sortedResult[0..maxSize] contains all values stored in this BST object in
//      ascending order
{
    //DATA DICTIONARY
    int size = 0;       //physize of sortedResult
    
    traversalInorderPrivate(root, sortedResult, size);
}

void BST::traversalInorderPrivate(TreeNodePtr& subRoot, int sortedResult[], int& size)
//PRE:  subRoot is initialized to point to a node in this BST object, sortedResult has
//      physical size larger than the number of values stored in this BST object, and
//      size >= 0
//POST: sortedResult[0..(size-1)] contains all values in-orderly stored in the keys
//      which are in the "children" treenodes of subRoot
{
    if(subRoot != NULL)                 //Not an empty tree node
    {
        traversalInorderPrivate(subRoot -> left, sortedResult, size);
        sortedResult[size] = subRoot -> key;
        size++;
        traversalInorderPrivate(subRoot -> right, sortedResult, size);
    }
}

void treeSort(int data[], int size)
//PRE:  size > 0, and data[0..size-1] is initialized
//POST: data[0..(size-1)] contains all values from data[0..(size-1)] at the time of
//      invocation, in ascending order
{
    //DATA DICTIONARY
    int sortedData[MAX_ARRAY_SIZE];     //an array to store temporary results
    
    BST sortedTree(data, size);         //create a binary search tree
    sortedTree.traversalInorder(sortedData, MAX_ARRAY_SIZE);    //traverse the BST
    //  object in-orderly and
    //  store each traversed
    //  value into sortedData
    //  in the order of
    //  traversal
    
    //go through all values in sortedData[0..(size-1)] and copy them to
    //  data[0..(size-1)]
    for(int i=0; i<size; i++)
    {
        data[i] = sortedData[i];
    }
}

void BST::traversalInorderR(int sortedResult[], int maxSize)
//PRE:  maxSize >= number of elements stored in this BST object, and sortedResult has
//      physical size of maxSize
//POST: sortedResult[0..maxSize] contains all values stored in this BST object in
//      ascending order
{
    //DATA DICTIONARY
    int size = 0;       //physize of sortedResult
    
    traversalInorderPrivateR(root, sortedResult, size);
}

void BST::traversalInorderPrivateR(TreeNodePtr& subRoot, int sortedResult[], int& size)
//PRE:  subRoot is initialized to point to a node in this BST object, sortedResult has
//      physical size larger than the number of values stored in this BST object, and
//      size >= 0
//POST: sortedResult[0..(size-1)] contains all values in-orderly stored in the keys
//      which are in the "children" treenodes of subRoot
{
    if(subRoot != NULL)                 //Not an empty tree node
    {
        traversalInorderPrivateR(subRoot -> right, sortedResult, size);
        sortedResult[size] = subRoot -> key;
        size++;
        traversalInorderPrivateR(subRoot -> left, sortedResult, size);
    }
}

void treeSortR(int data[], int size)
//PRE:  size > 0, and data[0..size-1] is initialized
//POST: data[0..(size-1)] contains all values from data[0..(size-1)] at the time of
//      invocation, in ascending order
{
    //DATA DICTIONARY
    int sortedData[MAX_ARRAY_SIZE];     //an array to store temporary results
    
    BST sortedTree(data, size);         //create a binary search tree
    sortedTree.traversalInorderR(sortedData, MAX_ARRAY_SIZE);    //traverse the BST
    //  object in-orderly and
    //  store each traversed
    //  value into sortedData
    //  in the order of
    //  traversal
    
    //go through all values in sortedData[0..(size-1)] and copy them to
    //  data[0..(size-1)]
    for(int i=0; i<size; i++)
    {
        data[i] = sortedData[i];
    }
}



//---Random Number Generator & Timer---
double NextRandNum()
// PRE:  random number generator has been initialized with a call to srand()
// POST: FCTVAL == next random number x s.t. x >= 0 and x < 1
{
    return double(rand()%32768)/32768;     // generate "random" number
}



int main(){
    //DATA DICTIONARY
    
    
    
    //---DATA COLLECTION---
    //cout << "---DATA COLLECTION---" << endl;
    
    clock_t startTime;                      // start time for array generation in clock ticks
    clock_t finishTime;                     // finish time for array generation in clock ticks
    double  elapsedTime;                    // number of clock ticks for array generation
    
    int array[MAX_ARRAY_SIZE];              // array of random numbers
    
    
    // PROCESS
    srand( (unsigned) time(0) );                // set seed for random number generation
    
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)            // generate random numbers
    {
        array[i] = int(NextRandNum()*RANDOM_NUMBER_RANGE);
    }
    
    
    
    // CREATE SIX COPIES
    int random1[MAX_ARRAY_SIZE];
    int random2[MAX_ARRAY_SIZE];
    int random3[MAX_ARRAY_SIZE];
    int random4[MAX_ARRAY_SIZE];
    int random5[MAX_ARRAY_SIZE];
    int random6[MAX_ARRAY_SIZE];
    
    for(int i=0; i < MAX_ARRAY_SIZE; i++)
    {
        random1[i] = array[i];
        random2[i] = array[i];
        random3[i] = array[i];
        random4[i] = array[i];
        random5[i] = array[i];
        random6[i] = array[i];
    }
    
    // TIME SORTING
    
    
    startTime = clock();
    selectionSort(random1, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    bubbleSort(random2, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    insertionSort(random3, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    quickSort(random4, 0, MAX_ARRAY_SIZE-1);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    mergeSort(random5, 0, MAX_ARRAY_SIZE-1);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    treeSort(random6, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << endl;
    
    
    
    
    startTime = clock();
    selectionSort(random1, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    bubbleSort(random2, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    insertionSort(random3, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    quickSort(random4, 0, MAX_ARRAY_SIZE-1);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    mergeSort(random5, 0, MAX_ARRAY_SIZE-1);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    treeSort(random6, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << endl;
    
    
    //---TEST FOR ALL SIX SORTING ALGORITHM---
    
    
    
    
    startTime = clock();
    selectionSortR(random1, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    bubbleSortR(random2, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    insertionSortR(random3, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    quickSortR(random4, 0, MAX_ARRAY_SIZE-1);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    mergeSortR(random5, 0, MAX_ARRAY_SIZE-1);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << ",";
    
    startTime = clock();
    treeSortR(random6, MAX_ARRAY_SIZE);
    finishTime = clock();
    elapsedTime = double(finishTime - startTime);
    cout << elapsedTime << endl;;
    
    
    
    return 0;
    
}