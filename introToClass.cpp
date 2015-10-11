#include <string>
#include <iostream>
using namespace std;

string returnedExpression(string inputString)
{
    //DATA DICTIONARY
    double length;                      				// the length of inputString
	double pos1;                        				// the starting position of the returned string
    string rest;              							// the string to be returned
    
    length = inputString.length();
    
    if (inputString.length() <= 80)						// check if the length of inputString <= 80
    {
        
        if (inputString[length - 1 ] == ';')			// check if the string ends with semicolon
        {
            pos1 = inputString.find("return") + 7;      // "return " includes 6 characters and 1 space
            
            rest = inputString.substr(pos1, length - pos1 - 1);
            
            return rest;
        }
        else
        {
            return "The command line doesn't end with semicolon!";
        }
    }
    else
    {
        return "The command line is longer than 80 chars!";
    }
}
