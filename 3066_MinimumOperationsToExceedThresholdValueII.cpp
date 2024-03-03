/*
3066. Minimum Operations to Exceed Threshold Value II
You are given a 0-indexed integer array nums, and an integer k.

In one operation, you will:

Take the two smallest integers x and y in nums.
Remove x and y from nums.
Add min(x, y) * 2 + max(x, y) anywhere in the array.
Note that you can only apply the described operation if nums contains at least two elements.

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
        priority_queue<long long, vector<long long>, greater<long long>> q;
        
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            q.push(nums[i]);
        }
        while(!q.empty()) {
            long long a = q.top();
            q.pop();
            if(a >= k || q.empty()) {
                return ans;
            }
            
            long long b = q.top();
            q.pop();
            ans++;
            q.push(min(a, b) * 2 + max(a, b));
        }
        return ans;
    }
};

int main() {
    
    return 0;
}