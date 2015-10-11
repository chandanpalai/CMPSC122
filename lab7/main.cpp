// Progbrammer: Yizhou Wang
// Section:		2
// Lab:			7
// Date:		Feb. 21, 2014
// Description: A test driver for the implementation of a class bankAccount

#include "bankAccount.h"
#include <iostream>

int main()
{
	bankAccount account1;			// create default bankAccount object account1
	bankAccount account2;			// create default bankAccount object account2
	
	// deposite a different amount in each account
	account1.deposit(200);
	account2.deposit(300);
	
	// print how much money is in each account
	cout << "The balance of account1:" << endl;
	cout <<  "$" <<  account1.getBalance() << endl;
	
	cout << "The balance of account2:" << endl;
	cout << "$" << account2.getBalance() << endl;
	
	account1.withdraw(122);				// withdraw $122 from account1
	cout << "The remaining balance of account1 after withdrawal of $122:" << endl;
	cout << "$" << account1.getBalance();		// print out the remaining balance of account1
}