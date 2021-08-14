/**
 * Given an array of characters chars, compress it using the following algorithm:
 * 
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 * 
 * The compressed string s should not be returned separately, but instead be stored in the input 
 * character array chars. Note that group lengths that are 10 or longer will be split into multiple 
 * characters in chars.
 * 
 * After you are done modifying the input array, return the new length of the array.
 * You must write an algorithm that uses only constant extra space.
 * 
 * Example 1:
 * Input: chars = ['a','a','b','b','c','c','c']
 * Output: Return 6, and the first 6 characters of the input array should be: ['a','2','b','2','c','3']
 * Explanation: The groups are 'aa', 'bb', and 'ccc'. This compresses to 'a2b2c3'.
 * 
 * Example 2:
 * Input: chars = ['a']
 * Output: Return 1, and the first character of the input array should be: ['a']
 * Explanation: The only group is 'a', which remains uncompressed since it's a single character.
 * 
 * Example 3:
 * Input: chars = ['a','b','b','b','b','b','b','b','b','b','b','b','b']
 * Output: Return 4, and the first 4 characters of the input array should be: ['a','b','1','2'].
 * Explanation: The groups are 'a' and 'bbbbbbbbbbbb'. This compresses to 'ab12'.
 * 
 * Example 4:
 * Input: chars = ['a','a','a','b','b','a','a']
 * Output: Return 6, and the first 6 characters of the input array should be: ['a','3','b','2','a','2'].
 * Explanation: The groups are 'aaa', 'bb', and 'aa'. This compresses to 'a3b2a2'. 
 * Note that each group is independent even if two groups have the same character.
 * 
 * Constraints:
 * 1 <= chars.length <= 2000
 * chars[i] is a lower-case English letter, upper-case English letter, digit, or symbol.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

typedef struct test {
    vector<char> chars;
    int ret;
    vector<char> res;
} test;

int compress(vector<char>& s) {
    int len = s.size();
    vector<char> res;
    char lastChar = (char) s[0];
    int numChars = 0;

    //increment through the array
    for(int i = 0; i <= len; i++) {
        //if the char at this position is the same as the last, increment
        if((char) s[i] == lastChar) {
            numChars++;
        } else {
            //put in resulting vector
            res.push_back(lastChar);
            //turn count into string if there are more than 1
            if(numChars > 1) {
                string its = to_string(numChars);
                for(int j = 0; j < its.length(); j++) {
                    res.push_back(its[j]);
                }
            }
            //put current chatacter into lastChar
            lastChar = (char) s[i];
            //reset numChars
            numChars = 1;
        }
    }
    s.clear();
    s=res;
    return s.size();
}

int main() {
    system("@cls||clear");

    test t1 = {
        {'a','a','b','b','c','c','c'},
        6,
        {'a','2','b','2','c','3'},
    };
    test t2 = {
        {'a'},
        1,
        {'a'},
    };
    test t3 = {
        {'a','b','b','b','b','b','b','b','b','b','b','b','b'},
        4,
        {'a','b','1','2'},
    };
    test t4 = {
        {'a','a','a','b','b','a','a'},
        6,
        {'a','3','b','2','a','2'},
    };

    test tests[] = {t1, t2, t3, t4};

    for(int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        int ret = compress(tests[i].chars);
        //chech function output
        if(tests[i].chars != tests[i].res) {
            if(ret != tests[i].ret) {
                printf("Array lengths do not match expected result %i != %i.\n", tests[i].ret, ret);
            }
            for(int j = 0; j < ret; j++) {
                printf("%c ", tests[i].chars[j]);
            }
            printf("\nFail. Did not get the expected result.\n");
            for(int j = 0; j < tests[i].res.size(); j++) {
                printf("%c ", tests[i].res[j]);
            }
            printf("\n");
            break;
        }
    }
    printf("Success!\n");

    return 0;
}