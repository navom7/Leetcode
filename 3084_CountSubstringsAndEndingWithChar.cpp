/*

3084. Count Substrings Starting and Ending with Given Character

You are given a string s and a character c. Return the total number of substrings of s that start and end with c.
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
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        int n = s.size();
        for(char ch: s) {
            if(ch == c) {
                cnt++;
            }
        }
        
        cnt++;
        long long ans = cnt*(cnt-1)/2;
        return ans;
    }
};

int main() {
    
    return 0;
}