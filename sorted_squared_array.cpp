/**
 * Given an array of sorted integers, write a function that 
 * returns a sorted array continaing the squares of those integers.
 * 
 * Example 1:
 * input: [-7, -3, -1, 4, 8, 12]
 * output: [1, 9, 16, 49, 64, 144]
 * 
 * Example 2:
 * input: [1, 2, 3]
 * output: [1, 4, 9]
 * 
 * Example 3:
 * input: [-3, -2, -1]
 * output: [1, 4, 9]
 * 
 * constraints:
 * input length 1 <= N <= 10000
 * element: -10000 <= array[i] <= 10000
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct test {
    vector<int> arr;
    vector<int> res;
} test;

void printVector(vector<int> vec) {
    int len = vec.size();
    printf("[");
    for(int i = 0; i < len; i++) {
        printf("%i, ", vec[i]);
    }
    printf("]\n");
}

vector<int> squareSorted(vector<int> arr) {
    int len = arr.size();
    vector<int> res = arr;
    int left = 0, right = len - 1;
    for (int index = len - 1; index >= 0; index--) {
        // Check if abs(arr[left]) is greater
        // than arr[right]
        if (abs(arr[left]) > arr[right]) {
            res[index] = arr[left] * arr[left];
            left++;
        }
        else {
            res[index] = arr[right] * arr[right];
            right--;
        }
    }
    return res;
}

int main() {
    printf("\033c");
    system("@cls||clear");

    test t1 = {
        {-7, -3, -1, 4, 8, 12},
        {1, 9, 16, 49, 64, 144}
    },
    t2 = {
        {1, 2, 3},
        {1, 4, 9}
    },
    t3 = {
        {-3, -2, -1},
        {1, 4, 9}
    };

    vector<test> tests = {t1, t2, t3};

    for(int i = 0; i < tests.size(); i++) {
        vector<int> res = squareSorted(tests[i].arr);
        if(res != tests[i].res) {
            printf("Provided: ");
            printVector(tests[i].arr);
            printf("Expected: ");
            printVector(tests[i].res);
            printf("Received: ");
            printVector(res);
            break;
        } else {
            printf("Correct\n");
        }
    }

    return 0;
}