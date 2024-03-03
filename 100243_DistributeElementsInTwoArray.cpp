
/*

100243. Distribute Elements Into Two Arrays I
User Accepted:13367
User Tried:14531
Total Accepted:13712
Total Submissions:19181
Difficulty:Easy
You are given a 1-indexed array of distinct integers nums of length n.

You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

Return the array result.

*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> resa;
        vector<int> resb;
        resa.push_back(nums[0]);
        resb.push_back(nums[1]);
        
        int n = nums.size();
        for(int i = 2; i < n; i++) {
            if(resa.back() > resb.back()) {
                resa.push_back(nums[i]);
            } else {
                resb.push_back(nums[i]);
            }
        }
        
        vector<int> res;
        for(auto x: resa) {
            res.push_back(x);
        }
        for(auto x: resb) {
            res.push_back(x);
        }
        return res;
    }
};