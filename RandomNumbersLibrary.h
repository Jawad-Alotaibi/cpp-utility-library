#include <iostream>
using namespace std;

namespace RandomNumbersLibrary
{
     int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }
}
   