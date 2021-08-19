/*
 1. Understanding how -ve numbers are stored in computer
  * Negative numbers are stored in the form of 2's complement by the computer
  * and this program shows a proof by examples

 2. through 1's complement we can get INT_MAX and INT_MIN
  * set all bits of a number or unset all the set bits
  * i.e. complementing
 */

#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
int main(){
    bitset<32> bin; // bitset displays a number in binary form

    // -------------------------------------------------------------------------
    // 1. Understanding how -ve numbers are stored in computer

    // number n and its binary
    int n = 50;          bin = n;
    cout << n << '\n';
    cout << bin << '\n';

    cout << "1's complement of " << n << " : ";
    // this reverses all the bits; i.e. does one's complement
    cout << ~n << '\n';
    bin = ~n;
    cout << bin << "\n";

    int n2 = -51;       bin = n2;
    cout << n2 << '\n';
    cout << bin << "\n\n";

    // this does two's complement
    cout << "2's complement of " << n << ": " << (~(n-1)) << '\n';
    bin = (~(n-1));
    cout << bin << '\n';
    bin = -n;
    cout << bin << '\n';

    // -------------------------------------------------------------------------
    // 2. through 1's complement we can get INT_MAX and INT_MIN
    cout << "\n\n";
    {
        // int num = pow(2,31) -1;
        // int num = (1<<31) -1;
        // note: 1<<31 will shift 1 to 32th bit (yes 32th) but it will lead to int overflow 
        // and the answer would be then INT_MIN offcourse (it's a cycle)
        // but we do (1<<31) -1 and make it INT_MAX, by not letting it exceed the limit
        // but we achieve it by first doing overflow then taking a step back to get INT_MAX 
        // not a good practise
        unsigned int num = 0;
        num = ~num;     // 1's complement (will change all bits to 1)
        num = num >> 1;  // now the first bit is 0 and number is INT_MAX

        // int numN = pow(-2,31);
        int numN = -1<<31;
        bitset<32> numbit(num);
        bitset<32> numNbit(numN);
        cout << num << "\n" << numbit << "\n" << numN << "\n" << numNbit << "\n\n";
    }

    unsigned int max = 0; // important to keep as unsigned int otherwise below steps don't work fine
    max = ~max;     // all 32bits filled with 1 (i.e. set)
    max = max>>1;   // to produce INT_MAX (1st bit is made 0)
    bin = max;
    cout << "INT_MAX: " << max << '\n' << bin << '\n';
    
    int min = max;        // min is signed number
    min = ~min;     // will give INT_MIN (1st bit 1(sign bit) rest all 0's; here zeroes are significant)
    cout << "1's complement of " << max << ":" << min << " (INT_MIN)\n";
    bin = min;
    cout << bin << '\n';

    int number = max;
    cout << "2's complement of " << max << ":" << -number << '\n';
    bin = -number;
    cout << bin << '\n';

    int nm = -4;
    bitset<32> nmi(nm);
    cout << endl <<  nmi << endl;
    // TRICK: 
    // see in output last two digits are 0 = so looks like -3 (as in -ve num, 0 is like significant)
    // so add -1 to it 
    // -3-1 = -4; and this is your answer
    // i.e. what you think ans is -1 = actual ans (in negative numbers)

    return 0;
}
