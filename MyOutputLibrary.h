#pragma once 

#include <iostream>
#include <iomanip>
using namespace std;
namespace MyOutputLibrary 
{
    void printResults(int max)
{
    cout << "The max number is: " << max << endl;
}

void printNumber(int num, string message)
{
    cout << message << num << endl;
}

void printMatrix(int matrix[3][3], short rows, short cols)
{
    cout << left;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

}
void printMiddleRowOfMatrix(int matrix[3][3], short rows, short cols)
{
        int middleRow = rows / 2;
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix[middleRow][j] << " ";
        }
        cout << endl;
    
}

void printMiddleColumnOfMatrix(int matrix[3][3], short rows, short cols)
{
    int middleColumn = cols / 2;
    for (int i = 0; i < rows; i++)
    {
        cout << setw(3) << matrix[i][middleColumn] << " ";
        cout << endl;
    }
}
void printMultpliedMatrix(int multipliedMatrix[3][3],short rows, short cols)
{
     for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(multipliedMatrix[i][j] > 9)
            {
                cout << setw(3) << multipliedMatrix[i][j] << " ";
            }
            else
            cout << setw(2) << "0" << multipliedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrixAndAddZeros(int matrix[3][3],short rows, short cols)
{
     for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(matrix[i][j] > 9)
            {
                cout << setw(3) << matrix[i][j] << " ";
            }
            else
            cout << setw(2) << "0" << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printOneDimensionalMatrix(int matrix[], short rows)
{
    
    for (int i = 0; i < rows; i++)
    {
        cout << setw(3) << matrix[i] << " ";
    }

}

void printEachWordInString(string s1)
{
    string delimiter = " ";

    cout << "Your string Words are: " << endl << endl;

    short pos = 0; // to know the index of the delimiter
    string sWord = ""; // intilize it to avoid garbage value

    //use the find() to get the position of the delimiters

    while((pos = s1.find(delimiter)) != string::npos)
    {
        //store the word before the position 
        sWord = s1.substr(0, pos);

        if(sWord != "") //Because if there are multiple spaces, or a space at the beginning, substr() may return an empty string.
        {
            cout << sWord << endl;
        }

        //we need to delete or erase the string we print it out
        s1.erase(0, pos + delimiter.length());
    }


    if(s1 != "")
    {
        cout << s1 << endl;
    }
}

void printVecotrContent(vector<string> vWords)
{
    cout << "\nTokens = " << vWords.size() << endl;
    for (vector<string>::iterator itWords = vWords.begin(); itWords != vWords.end(); itWords++)
    {
        cout << *itWords << endl;
    }
}

}