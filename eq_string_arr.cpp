/** https://projecteuler.net/problem=5
 * Given two string arrays word1 and word2, return true if the two arrays represent the same string, 
 * and false otherwise.
 * A string is represented by an array if the array elements concatenated in order forms the string.
 * 
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation:
 * word1 represents string "ab" + "c" -> "abc"
 * word2 represents string "a" + "bc" -> "abc"
 * The strings are the same, so return true.
 * 
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 * 
 * Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * Output: true
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct test {
    vector<string> w1;
    vector<string> w2;
} test;

bool same(vector<string> w1, vector<string> w2) {
    string nw1, nw2;
    for(int i = 0; i < w1.size(); i++) {
        nw1 += w1[i];
    }
    for(int i = 0; i < w2.size(); i++) {
        nw2 += w2[i];
    }
    return nw1 == nw2;
}

int main() {
    system("@cls||clear");
    
    test t1 = {
        {"ab", "c"},
        {"a", "bc"}
    };

    test t2 = {
        {"a", "cb"},
        {"ab", "c"}
    };

    test t3 = {
        {"abc", "d", "defg"},
        {"abcddefg"}
    };

    test tests[] = {t1, t2, t3};
    bool res = false;
    for(int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        res = same(tests[i].w1, tests[i].w2);
        cout << res << "\n";
    }

    return 0;
}