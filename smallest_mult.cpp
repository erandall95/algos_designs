
/**
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>

using namespace std;

#define MIN 1
#define MAX 20

bool evenDiv(int num, int divisor) {
    bool isDiv = ( ( num % divisor ) % 2 == 0 );
    cout << num << " " << divisor << " " << isDiv << "\n";
    return isDiv;
}

bool evenDivRange(int num) {
    bool div = true;
    for(int i = MIN ; i <= MAX; i++) {
        div &= evenDiv(num, i);
    }
    return div;
}

int main() {
    system("@cls||clear");
    int count = 2520;
    while(true) {
        if(evenDivRange(count)) {
            break;
        }
        count++;
    }

    cout << count;

    return 0;
}