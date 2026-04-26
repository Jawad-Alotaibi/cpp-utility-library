#include <iostream>
// #include "HeaderFiles/RandomNumbersLibrary.h"
using namespace std;

namespace MatrixLibrary
{

    int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }
    void fillMatrixWitOrderedNumbers(int matrix[3][3], short rows, short cols)
    {
        int counter = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                counter++;
                matrix[i][j] = counter;
            }
        }
    }

    void fillArrayWithRandomNumbers(int arr[3][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = RandomNumber(1, 10);
            }
        }
    }

    void transposedMatrix(int matrix[3][3], int transposedMatrix[3][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                transposedMatrix[i][j] = matrix[j][i];
            }
        }
    }

    void multiplyTwoMatrix(int matrix1[3][3], int matrix2[3][3], int multipliedMatrix[3][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                multipliedMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
            }
        }
    }

    int sumAllNumbersInMatrix(int matrix[3][3], int rows, int cols)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
    bool areEqualMetrices(int matrix1[3][3], int matrix2[3][3], int rows, int cols)
    {
        return (sumAllNumbersInMatrix(matrix1, rows, cols) == sumAllNumbersInMatrix(matrix2, rows, cols));
    }

    bool areMetricesTypical(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix1[i][j] != matrix2[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isIdentity(int matrix[3][3], int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                //check the diagnol element
                if (i == j && matrix[i][j] != 1)
                {
                    return false;
                }
                //check the rest of elements
                if (i != j && matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

       bool isScalar(int matrix[3][3], int rows, int cols)
    {
        int firsrDiagnolElement = matrix[0][0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                //check the diagnol element
                if (i == j && matrix[i][j] != firsrDiagnolElement)
                {
                    return false;
                }
                //check the rest of elements
                if (i != j && matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int countNumberInMatrix(int matrix[3][3],int numberToFind ,int rows, int cols)
    {
        int counter = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == numberToFind)
                {
                    counter++;
                }
            }
            
        }
        return counter;
    }
    bool checkSparce(int arr[3][3], short rows, short cols)
    {
        int zerosCounts = 0;
        int numbersCounts = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(arr[i][j] == 0)
                {
                    zerosCounts++;
                }        
                else numbersCounts++;
            }
            
        }
        return zerosCounts > numbersCounts ? true : false;
        
    }

    bool checkNumberExsist(int arr[3][3], int numberToFind ,short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(arr[i][j] == numberToFind)
                {
                    return true;
                }
            }
            
        }

        return false;
        
    }

    void findIntersected(int matrix1[3][3], int matrix2[3][3], int intersectedMatrix[],short rows, short cols)
    {
       
        int number;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                number = matrix1[i][j];
                if (checkNumberExsist(matrix2, number,3,3))
                {
                    intersectedMatrix[i] = number;
                }
            }
            
        }
        
    }

    int findMinimumNumberInMatrix(int matrix[3][3], int rows, int cols)
    {
        int minimum = matrix[0][0];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (minimum > matrix[i][j])
                {
                    minimum = matrix[i][j];
                }
            }
            
        }
        return minimum;
        
    }

    int findMaximumNumberInMatrix(int matrix[3][3], int rows, int cols)
    {
        int maximum = matrix[0][0];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] > maximum)
                {
                    maximum = matrix[i][j];
                }
            }
            
        }
        return maximum;
        
    }

    bool isPalinrome(int matrix[3][3],int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols / 2; j++) // because we will compare the first with the last then the second with the previous of the last until we reach the middle element and stop 
            {
                if(matrix[i][j] != matrix[i][cols - 1 - j])
                {
                    return false;
                }
            }
            
        }
        return true;
    }
}
