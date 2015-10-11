// Programmer:  Yizhou Wang
// Section:     2
// Lab:         Random variables
// Date:        Apr 30, 2014
// Description: Implementation of a PDF from the example in class for the number of inhabitants
//              in a household

#include <iostream>
using namespace std;

double PDF()
//POST: The probability of PDF == 1 is 25%
//      The probability of PDF == 2 is 32%
//      The probability of PDF == 3 is 17%
//      The probability of PDF == 4 is 15%
//      The probability of PDF == 5 is 7%
//      The probability of PDF == 6 is 3%
//      The probability of PDF == 7 is 1%
{
    //DATA DICTIONARY
    int random;                         //a random integer
    int people;                         //number of inhabitants in a household
    
    people = 7;
    random = rand()%100+1;
    
    if (random <= 99)                    //if [random] falls into the CDF of [people] <= 6
    {
        people--;
    }
    
    if (random <= 96)                    //if [random] falls into the CDF of [people] <= 5
    {
        people--;
    }
    
    if (random <= 89)                    //if [random] falls into the CDF of [people] <= 4
    {
        people--;
    }
    
    if (random <= 74)                    //if [random] falls into the CDF of [people] <= 3
    {
        people--;
    }
    
    if (random <= 57)                    //if [random] falls into the CDF of [people] <= 2
    {
        people--;
    }
    
    if (random <= 25)                    //if [random] falls into the CDF of [people] == 1
    {
        people--;
    }
        
    return people;
}

int main()
{
    //DATA DICTIONARY
    int ctr_1;
    int ctr_2;
    int ctr_3;
    int ctr_4;
    int ctr_5;
    int ctr_6;
    int ctr_7;
    int probability;
    
    ctr_1 = 0;
    ctr_2 = 0;
    ctr_3 = 0;
    ctr_4 = 0;
    ctr_5 = 0;
    ctr_6 = 0;
    ctr_7 = 0;
    
    
    
    for (int i=0; i<= 100; i++)
    {
        probability = PDF();
        cout << probability << " ";
        if (probability == 1)
        {
            ctr_1++;
        }
        if (probability == 2)
        {
            ctr_2++;
        }
        if (probability == 3)
        {
            ctr_3++;
        }
        if (probability == 4)
        {
            ctr_4++;
        }
        if (probability == 5)
        {
            ctr_5++;
        }
        if (probability == 6)
        {
            ctr_6++;
        }
        if (probability == 7)
        {
            ctr_7++;
        }
    }
    
    cout << endl;
    
    cout << "There are " << ctr_1 << " 1(s) in 100 executions of PDF " << endl;
    cout << "There are " << ctr_2 << " 2(s) in 100 executions of PDF " << endl;
    cout << "There are " << ctr_3 << " 3(s) in 100 executions of PDF " << endl;
    cout << "There are " << ctr_4 << " 4(s) in 100 executions of PDF " << endl;
    cout << "There are " << ctr_5 << " 5(s) in 100 executions of PDF " << endl;
    cout << "There are " << ctr_6 << " 6(s) in 100 executions of PDF " << endl;
    cout << "There are " << ctr_7 << " 7(s) in 100 executions of PDF " << endl;
    
    return 0;
}

