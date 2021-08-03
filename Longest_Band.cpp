//128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        if(n == 0) return longest;
        unordered_set<int> st;
        for(auto x : nums) {
            st.insert(x);
        }
        for(auto x : nums) {
            int cnt = 0;
            if(st.find(x-1) != st.end()) {
                continue;
            } else {
                while(st.find(x) != st.end()) {
                    x++;
                    cnt++;
                }
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};