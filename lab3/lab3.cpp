// Programmer:  Yizhou Wang
// Section:     2
// Lab:         3
// Date:        Jan 29, 2014
// Description: A program of pointer exercise

#include <iostream>

using namespace std;

int main ()
{
	//DATA DICTIONARY
	double x;                               //a double varialbe named x
	double y;                               //a double varialbe name y
	double *p1;                             //a pointer named p1
	double *p2;                             //a pointer named p2
	
	//STEP 1
	p1 = &x;                                            //the first pointer points to the first
                                                        //  double variable x
	*p1 = 1.25;                                         //the pointee x is initialized
                                                        //  to the value of 1.25
	cout << "step 1" << "\n";
	cout << "value of p1 is " << p1 << "\n";
	cout << "value of p1's pointee is " << *p1 << "\n";
	cout << "x is "<< x << "\n\n";
	
	//STEP 2
	y = 2.5;                                            //initialize second double variable y to 2.5
	p1 = &y;                                            //the first pointer points to the variable
                                                        //  2 now
	cout << "step 2" << "\n";
	cout << "value of p1 after is " << p1 << "\n";
	cout << "value of p1's pointee is " << *p1 << "\n";
	cout << "y is "<< y << "\n\n";

	//STEP 3
	p2 = new double;                                    //make the second pointer point to a
                                                        //  different unnamed location in memory
	*p2 = 10;                                           //make the value of the second pointer's
                                                        //  pointee 10
	cout << "step 3" << "\n";
	cout << "value of p2 after is " << p2 << "\n";
	cout << "value of p1's pointee is " << *p2 << "\n";
	cout << "x is "<< x << "\n";
	cout << "y is "<< y << "\n\n";
	
	//STEP 4
	delete p2;                                          //delete p2's pointee
	p2 = new double;                                    //make the second pointer point to another
                                                        //  different unamed location in memory
	*p2 = 2 * (*p1);                                    //make the pointee of the second pointer to
                                                        //  the value twice of the pointee of the
                                                        //  first pointer
	cout << "step 4" << "\n";
	cout << "value of p2 is " << p2 << "\n";
	cout << "value of p2's pointee is " << *p2 << "\n";
	cout << "x is " << x << "\n";
	cout << "y is " << y << "\n\n";
	
	//STEP 5
	cout << "product of p1 and p2 is " << (*p1) * (*p2) << "\n";
	
	return 0;
}