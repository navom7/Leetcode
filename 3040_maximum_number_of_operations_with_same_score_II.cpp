/*

3040. Maximum Number of Operations With the Same Score II
Solved
Medium
Companies
Hint
Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:

Choose the first two elements of nums and delete them.
Choose the last two elements of nums and delete them.
Choose the first and the last elements of nums and delete them.
The score of the operation is the sum of the deleted elements.

Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.

Return the maximum number of operations possible that satisfy the condition mentioned above.

 

Example 1:

Input: nums = [3,2,1,2,3,4]
Output: 3
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
- Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
- Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
We are unable to perform any more operations as nums is empty.
Example 2:

Input: nums = [3,2,6,1,4]
Output: 2
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
- Delete the last two elements, with score 1 + 4 = 5, nums = [6].
It can be proven that we can perform at most 2 operations.
 

Constraints:

2 <= nums.length <= 2000
1 <= nums[i] <= 1000

*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int> &nums, int i, int j, int n, int sum, vector<vector<int>>& dp) {
        if(i >= j) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if(i+1 < n && (nums[i] + nums[i+1]) == sum) {
            ans = max(ans, 1 + func(nums, i+2, j, n, sum, dp));
        }
        
        if(j-1 >= 0 && (nums[j] + nums[j-1]) == sum) {
            ans = max(ans, 1 + func(nums, i, j-2, n, sum, dp));
        }
        
        if(i < n && j >= 0 && (nums[i] + nums[j]) == sum) {
           ans = max(ans, 1 + func(nums, i+1, j-1, n, sum, dp));
        }
        
        return dp[i][j] = ans;
    }
    
    int maxOperations(vector<int>& nums) {
        
        dp.resize(2001, vector<int>(2001, -1));
        int n = nums.size();

        int ans = 0;
        ans = max(ans, 1 + func(nums, 2, n-1, n, nums[0] + nums[1], dp));
        ans = max(ans, 1 + func(nums, 0, n-3, n, nums[n-1] + nums[n-2], dp));
        ans = max(ans, 1 + func(nums, 1, n-2, n, nums[0] + nums[n-1], dp));
      
        
        return ans;
    }
};



int main() {

}


