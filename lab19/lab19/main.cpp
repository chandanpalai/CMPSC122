// Programmer:  Yiting Ju and Yizhou Wang
// Section:     2
// Lab:         19 - Quick Sort
// Date:        April. 25, 2014
// Description: A practice to implement quick sort

#include <iostream>
using namespace std;

void swap(int& a, int& b)
//PRE:  a and b are initialized
//POST: the value of a at the time of invocation is assigned to b
//      the value of b at the time of invocation is assigned to a
{
    //DATA DICTIONARY
    int temp;                                               //a temporary variable to hold the
                                                            //  variable getting swapped
    
    temp = b;
    b = a;
    a = temp;
}

int partition(int a[], int p, int q)
//PRE:  q >= p, and a[p..q] is initialized
//POST: a[p..FCTVAL] contains all values from a[p..q] at the time of invocation less
//      than or equal to a[q] at the time of invocation, and a[FCTVAL..q] contains all
//      values from a[p..q] at the time of invocation greater than a[q] at the time of
//      invocation
{
    //DATA DICTIONARY
    int pivot;                                              //a value used to partition the array
    int m;                                                  //index of the largest element smaller
                                                            //  than or equals to pivot
    
    pivot = a[q];                                           //set the last element in a[p..q] to be
                                                            //  the pivot
    m = p - 1;
    
    for(int i = p; i <= q-1; i++)                           //inspect every element in a[p..(q-1)],
                                                            //  and get the index that pivot belongs
                                                            //  to
    {
        if(a[i] < pivot)                                    //partition elements: ensure the elements
                                                            //  smaller than the pivot are all placed
                                                            //  left to the elements larger than
                                                            //  the pivot
        {
            m++;
            swap(a[i], a[m]);
        }
    }
    
    swap(a[m + 1], a[q]);                                   //swap to place the pivot to
                                                            //  where it belongs to
    
    return m + 1;
}

void quickSort(int a[], int p, int q)
//PRE:  q >= p, and a[p..q] is initialized
//POST: a[p..q] contains all values from a[p..q] at the time of invocation that are
//      sorted in ascending order
{
    //DATA DICTIONARY
    int pivotIndex;                                         //index of pivot which is used to
                                                            //  partition the array
    
    if(q > p)                                               //if there is element in a[p..q]
    {
        pivotIndex = partition(a, p, q);
        quickSort(a, p, pivotIndex-1);
        quickSort(a, pivotIndex+1, q);
    }
}


int main()
{
    //DATA DICTIONARY
    int a[10] = {4, 5, 6, 3, 2, 3, 6, 9, 7, 1};
    int b[10] = {222, 223, 224, 225, 226 ,227 ,228 ,229 ,230 ,231};
    int c[10] = {1001, 1000, 999, 998, 997, 996, 995, 994, 993, 992};
    
    quickSort(a, 0, 9);
    quickSort(b, 0, 9);
    quickSort(c, 0, 9);
    
    cout << "1st array before sorting: 4, 5, 6, 3, 2, 3, 6, 9, 7, 1" << endl;
    cout << "1st array after selection sort: ";
    for(int i=0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    cout << "2nd array before sorting: 222, 223, 224, 225, 226 ,227 ,228 ,229 ,230 ,";
    cout << "231" << endl;
    cout << "2nd array after selection sort: ";
    for(int i=0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    cout << "3rd array before sorting: 1001, 1000, 999, 998, 997, 996, 995, 994, 993,";
    cout << "992" << endl;
    cout << "3rd array after selection sort: ";
    for(int i=0; i < 10; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    return 0;
}