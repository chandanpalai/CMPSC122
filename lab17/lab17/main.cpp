// Programmer:  Yizhou Wang
// Section:     2
// Lab:         17
// Date:        Apr. 21, 2014
// Description: Implementation of insertion sort


#include <iostream>
using namespace std;

void insertion_sort (int A[], int n)
//PRE:  n > 0 and A[0..n-1] is initialized
//POST: A[0..n-1] contains all elements from A[0..n-1] at the time of invocation and
//      is sorted in ascending order and
{
    //DATA DICTIONARY
    int key;                                    //the value of A[j] which is to be inserted
    int i;                                      //the index of iteration representing the
                                                //  position of the element whose value is being
                                                //  inspected
    
    //Before the iteration indexed j, A[0..j-1] contains values from A[0..j-1] at time of invocation,
    //  now sorted in ascending order
    for (int j=1; j<=n-1; j++)                      //take each element of A[0..n-1] and insert it
                                                    //  into A[0..j-1] where it goes
    {
        //initialization
        key = A[j];
        i = j-1;                                    //shift A[0..j-1] s.t. there is an appropriate
                                                    //  slot in A[0..j] for key
    
        //For the iteration indexed i, we compare A[i] with key. If A[i] is greater than key, we
        //  shift A[i] to A[i+1]. We keep doing this with i-1 iteratively until we find the right
        //  position to insert key (the position of A[i+1] such that A[i] =< key and A[i+1] > key or
        //  the position of A[0])
        while (i>-1 && A[i]>key)
        {
            A[i+1] = A[i];                          //shift A[i] to A[i+1]
            i = i-1;
        }
        
        A[i+1] = key;                               //insert key at A[i+1]
    }
}

void insertion_sort_reverse (int A[], int n)
{
    int key;
    int i;
    
    for (int j = n-2; j>= 0; j--)
    {
        key = A[j];
        i = j+1;
        while (i < n && A[i] > key)
        {
            A[i-1] = A[i];
            i = i+1;
        }
        A[i-1] = key;
    }
}



void traversal(int A[], int n)
//PRE:  n > 0 and A[0..n-1] is initialized
//POST: all the elements of A[0..n-1] are printed to the console in a sequential order with a space
//      in between
{
    for (int i = 0; i < n; i ++)                    //traverse the array A[0..n-1] and print
                                                    //  elements spaced by a whitespace
    {
        cout << A[i] << "  ";
    }
    cout << endl;
}

int main()
{
    //DATA DICTIONARY
    int array1[8];
    int array2[10];
    int array3[15];
    
    //initialization
    array1[0] = 5;
    array1[1] = 3;
    array1[2] = 7;
    array1[3] = 9;
    array1[4] = 25;
    array1[5] = 42;
    array1[6] = 99;
    array1[7] = 35;
    
    array2[0] = 5;
    array2[1] = 10;
    array2[2] = 35;
    array2[3] = 50;
    
    array3[0] = 500;
    array3[1] = 400;
    array3[2] = 300;
    array3[3] = 200;
    array3[4] = 100;
    
    //Test1
    cout << "***Test1: The original array1 (mixed order) is:" << endl;
    traversal(array1, 8);
    
    insertion_sort(array1, 8);
    
    cout << "After insertion sort, the array1 turns into:" << endl;
    traversal(array1, 8);
    
    cout << endl;
    
    //Test2
    cout << "***Test2: The original array2 (ascending order) is:" << endl;
    traversal(array2, 4);
    
    insertion_sort(array2, 4);
    
    cout << "After insertion sort, the array2 turns into:" << endl;
    traversal(array2, 4);
    
    cout << endl;
    
    //Test3
    cout << "***Test3: The original array3 (descending order) is:" << endl;
    traversal(array3, 5);
    
    insertion_sort(array3, 5);
    
    cout << "After insertion sort, the array3 turns into:" << endl;
    traversal(array3, 5);
    
    cout << endl;
    
    
    
    
    return 0;
}

