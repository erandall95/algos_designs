/**
 * TinyURL is a URL shortening service where you enter a URL 
 * such as https://leetcode.com/problems/design-tinyurl and it returns a short URL 
 * such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.
 * 
 * There is no restriction on how your encode/decode algorithm should work.
 * You just need to ensure that a URL can be encoded to a tiny URL 
 * and the tiny URL can be decoded to the original URL.
 */

#include <iostream>

#include "my_lib/md5.h"

using namespace std;

typedef struct test {
    string url;
    string tiny;
} test;

int main() {
    system("@cls||clear");

    //shorten input url to tiny url, also get unique key
    //shorten from base 8 characters to base 64 characters from md5
    //check if shortened url is in hash table
    //if not in hash table, store it, else don't store it
    //return the shortned url
    
    cout<<md5("http://www.educative.io/distributed.php?id=design")<<endl;
    cout<<md5("http://www.educative.io/distributed.php%3Fid%3Ddesign")<<endl;

    //reverse the shortned url
    //ensure it matches the longer url

    return 0;
}