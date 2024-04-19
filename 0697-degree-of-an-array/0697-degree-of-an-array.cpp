class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > mx) {
                mx = mp[nums[i]];
            }
        }
        vector<int> vec;
        for(auto x: mp) {
            if(x.second == mx) {
                vec.push_back(x.first);
            }
        }
        int ans = INT_MAX;
        for(auto x: vec) {
            auto findFirst = find(nums.begin(), nums.end(), x);
            auto findLast = find_end(nums.begin(), nums.end(), &x, &x+1);
            int diff = distance(findFirst, findLast)+1;
            
            ans = min(diff, ans);
        }
        return ans;
    }
};