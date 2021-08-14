/**
 * Given an array of integers nums and an integer target, return indices of the two numbers 
 * such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct test {
    vector<int> nums;
    int target;
} test;

void twoSum(vector<int> nums, int target, int res[2]) {
    int len = nums.size();
    for(int i = 0; i < len; i++) {
        for(int j = len; j > 0; j--) {
            if(nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return;
            }
        }
    }
}

int main() {
    system("@cls||clear");
    int res[] = {0, 0};

    test tests[] = {
        { {2,7,11,15}, 9 },
        { {3,2,4}, 6 },
        { {3,3}, 6},
    };

    for(int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        twoSum(tests[i].nums, tests[i].target, res);
        cout << res[0] << " " << res[1] << "\n";
    }

    return 0;
}