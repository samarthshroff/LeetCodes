#include "Reverse32SignedInt.h"
#include <climits>

using namespace std;

Reverse32SignedInt::Reverse32SignedInt()
{

}

int Reverse32SignedInt::reverse(int x)
{
    signed int num = x;
    int divisor = 10;

    if (num < 0)
    {
        //negative numbers are stored in 2's complement so in order to get the number without the '-' sign
        //we need to get the 2's complement of it
        num = ~num + 1;
    }

    int reverseInt = INT_MAX;

    do
    {
        if (reverseInt != INT_MAX)
        {
            //multiply the result with 10 and add the remainder of the input%10 to the result
            //using modulo because that gives the remainder (which is what we want here)
            reverseInt *= divisor;
            reverseInt += num % divisor;
        }
        else
        {
            reverseInt = num % divisor;
        }

        num = num / divisor;

    } while (num > 0);

    if (x < 0) reverseInt *= -1;

    return reverseInt;
}