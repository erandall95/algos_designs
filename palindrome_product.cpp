/**
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int num) {
    int rev = 0;                    // the reversed number
    int x = num;                     // store the default value (it will be changed)
    while (x > 0) {
        rev = 10 * rev + x % 10;
        x /= 10;
    }
    return num == rev;               // returns true if the number is palindrome
}

int main() {
    system("@cls||clear");
    int max = -1;

    for ( int i = 999 ; i >= 100 ; i--) {
        for (int j = 999 ; j >= 100 ; j-- ) {
            int p = i * j;
            if ( max < p && isPalindrome(p) ) {
                max = p;
            }
        }
    }

    cout << max;

    return 0;
}