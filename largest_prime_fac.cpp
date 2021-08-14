/**
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    system("@cls||clear");
    long long int num = 0;
    long long int greatest = 2;

    cout << "Enter a number to find it's largest prime ... ";
    cin >> num;

    while(num % 2 == 0) {
        cout << 2 << " ";
        num /= 2;
    }

    for(int i = 3; i < sqrt(num); i = i + 2) {
        while(num % i == 0) {
            num /= i;
            cout << i << " ";
            if(i > greatest) {
                greatest = i;
            }
        }
    }
    
    if(num > 2) {
        cout << num << " ";
        if(num > greatest) {
            greatest = num;
        }
    }
    cout << "\nGreatest prime: " << greatest;

    return 0;
}