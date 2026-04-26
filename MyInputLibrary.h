#pragma once
#include <iostream>
using namespace std;
namespace MyInputLibrary 
{
    
int readNumber()
{
    int number;
    //cout << "Enter Number please\n";
    //when the cin object read from the screen anything rather than numbers it will fail
    cin >> number;
   
    while (cin.fail())
    {
        cin.clear();
        //it will ignore the input at any size until it found \n
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter a valid number please\n";
        cin >> number;
    }

    return number;
}


    double ReadPositiveNumber(string message)
    {
        double number = 0;

    
        do
        {
            cout << message << endl;
            cin >> number;
        }while(number <= 0);

        return number;
    }

    

    char readChar()
    {
        char c1;
        cout << "Enter a charachter?\n";
        cin >> c1;

        return c1;
    }

    string readString(string message)
    {
        string s1= "";
        
        cout << message;
        cin >> s1;

        return s1;

    }


}