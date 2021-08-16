/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5
 * Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell
 * 
 * Example 2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct test {
    vector<int> prices;
    int profit;
} test;

int max_profit(vector<int> prices) {
    int len = prices.size();
    int profit = 0;

    for(int i = 0; i < len; i++) {
        //we buy on this day
        for(int j = len - 1; j > i; j--) {
            //we sell on this day
            int sale = prices[j] - prices[i];
            if(sale > profit) {
                profit = sale;
            }
        }
    }
    return profit;
}

int main() {
    printf("\033c");
    system("@cls||clear");

    test t1 = {
        {7,1,5,3,6,4},
        5
    };

    test t2 = {
        {7,6,4,3,1},
        0
    };

    test tests[] = {t1, t2};

    for(int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        int profit = max_profit(tests[i].prices);
        if(profit != tests[i].profit) {
            printf("Incorrect. Expected %i - received %i\n", tests[i].profit, profit);
            break;
        } else {
            printf("Correct. Expected %i - received %i\n\n", tests[i].profit, profit);
        }
    }

    return 0;
}