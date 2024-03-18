/*

3085. Minimum Deletions to Make String K-Special

You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.

Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.

Return the minimum number of characters you need to delete to make word k-special.
*/

#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>

using namespace std;

#define ll long long
#define um unordered_map
int R;
int C;

class Solution {
public:
    
    int func(vector<int> vec, vector<vector<int>>& dp, int s, int e, int k) {
        if(s >= e) {
            return 0;
        }
        if(dp[s][e] != -1) {
            return dp[s][e];
        }
        
        if(abs(vec[s] - vec[e]) <= k) {
            return dp[s][e] = 0;
        }
        
        int ans = INT_MAX;
        ans = min(ans, vec[s]+func(vec, dp, s+1, e, k));
        ans = min(ans, vec[e]-(k+vec[s]) + func(vec, dp, s, e-1, k));
        return dp[s][e] = ans;
    }
    
    int minimumDeletions(string word, int k) {
        int arr[26] = {0};
        for(auto x: word) {
            arr[x-'a']++;
        }
        vector<int> vec;
        vector<vector<int>> dp(26, vector<int>(26, -1));
        for(int i = 0; i < 26; i++) {
            if(arr[i] > 0) {
                vec.push_back(arr[i]);
            }
        }
        sort(vec.begin(), vec.end());
        // for(auto x: vec) {
        //     cout << x << " ";
        // }
        cout << endl;
        func(vec, dp, 0, vec.size()-1, k);
        return dp[0][vec.size()-1] == -1 ? 0 : dp[0][vec.size()-1];
    }
};

int main() {
    // cout << 5&2;
    // cout << 5  2 ;
    return 0;
}