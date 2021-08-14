/** 
 * You are given the logs for users' actions on LeetCode, and an integer k. 
 * The logs are represented by a 2D integer array logs where each logs[i] = [ID_i, time_i] 
 * indicates that the user with ID_i performed an action at the minute time_i.
 * 
 * Multiple users can perform actions simultaneously, 
 * and a single user can perform multiple actions in the same minute.
 * 
 * The user active minutes (UAM) for a given user is defined as the number of unique minutes 
 * in which the user performed an action on LeetCode. 
 * A minute can only be counted once, even if multiple actions occur during it.
 * 
 * You are to calculate a 1-indexed array answer of size k such that, 
 * for each j (1 <= j <= k), answer[j] is the number of users whose UAM equals j.
 * 
 * Input: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
 * Output: [0,2,0,0,0]
 * Explanation:
 * The user with ID=0 performed actions at minutes 5, 2, and 5 again. Hence, they have a UAM of 2 (minute 5 is only counted once).
 * The user with ID=1 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
 * Since both users have a UAM of 2, answer[2] is 2, and the remaining answer[j] values are 0.
 * 
 * Input: logs = [[1,1],[2,2],[2,3]], k = 4
 * Output: [1,1,0,0]
 * Explanation:
 * The user with ID=1 performed a single action at minute 1. Hence, they have a UAM of 1.
 * The user with ID=2 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
 * There is one user with a UAM of 1 and one with a UAM of 2.
 * Hence, answer[1] = 1, answer[2] = 1, and the remaining values are 0.
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

#include <cstring>

using namespace std;

#define USER_ID_INDEX 0
#define USER_ACTION_INDEX 1

typedef struct test {
    vector<vector<int>> log;
    int k;
} test;

class userInfo {
    int uam = 0;
    unordered_map<int, bool> actions;

    public:
    int userID = -1;
    void setID(int id) {
        userID = id;
    }
    /**
     * Adds the action minute to the user and increments their UAM if they haven't had the same action minute
     * @param {int} acMin the action minute to add to the user
     * @returns none
     */ 
    void addActionMinute(int acMin) {
        if(actions.find(acMin) == actions.end() && actions[acMin] == false) {
            actions[acMin] = true;
            uam++;
            // printf("Adding user action for minute: %i - user has %i UAM\n",acMin, uam);
        }
    }

    /**
     * @return the number of user actions per minute
     */
    int getUserActionMinutes() {
        return uam;
    }
};

void uam(vector<vector<int>> log, int res[]) {
    unordered_map<int, userInfo> users;
    vector<int> userIDs;
    int logLength = log.size();
    // printf("\nGot %i log actions\n\n", logLength);
    //get all user UAM
    for(int i = 0; i < logLength; i++) {
        int userID = log[i][USER_ID_INDEX];
        int minute = log[i][USER_ACTION_INDEX];
        // printf("Log (%i): User ID: %i - Minute: %i\n", i, userID, minute);
        //check if user exists, if yes - add the action minute, else add a user and add their action minute
        if(users.find(userID) == users.end()) {
            // printf("No previous user found for userID %i - adding user\n", userID, i);
            userIDs.push_back(userID);
            users[userID] = userInfo();
            users[userID].setID(userID);
            users[userID].addActionMinute(minute);
        } else {
            // printf("User: %i... ", userID);
            users[userID].addActionMinute(minute);
        }
        // cout << endl;
    }
    //sum up the UAM in and put the results in the res array
    int numUsers = userIDs.size();
    for(int i = 0; i < numUsers; i++) {
        // printf("User %i has a UAM of: %i\n", users[userIDs[i]].userID, users[userIDs[i]].getUserActionMinutes());
        //minus 1 becuase of 0 index
        res[users[userIDs[i]].getUserActionMinutes()-1]++;
    }
}

int main() {
    system("@cls||clear");
    
    test t1 = {
        {{0,5},{1,2},{0,2},{0,5},{1,3}},
        5
    };

    test t2 = {
        {{1,1},{2,2},{2,3}},
        4
    };

    test tests[] = {t1, t2};

    for(int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        int* res = (int*) malloc(tests[i].k);
        memset(res, 0, sizeof(int) * tests[i].k);
        uam(tests[i].log, res);
        for(int j = 0; j < tests[i].k; j++) {
            cout << res[j] << " ";
        }
        cout << endl;
        free((void*)res);
    }

    return 0;
}