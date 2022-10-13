// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.







class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
      int n = nums.size();
      if(n < 1) {
        res.push_back(-1);
        res.push_back(-1);
        return res;
      }
      int a = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
      int b = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
      cout << a << " " << b << endl;
      // return res;
      if(a >= n || nums[a] != target){
        res.push_back(-1);
        res.push_back(-1);
        return res;
      }
      res.push_back(a);
      res.push_back(b);
      return res;
    }
};
