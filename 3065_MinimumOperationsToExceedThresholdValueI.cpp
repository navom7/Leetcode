/*

3065. Minimum Operations to Exceed Threshold Value I

You are given a 0-indexed integer array nums, and an integer k.

In one operation, you can remove one occurrence of the smallest element of nums.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.



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
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < k) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}