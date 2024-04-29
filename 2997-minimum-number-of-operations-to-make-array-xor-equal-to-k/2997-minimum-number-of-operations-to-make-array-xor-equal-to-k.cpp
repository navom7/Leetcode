class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> freq(33, 0);
        int n = nums.size();
        
        for(auto x: nums) {
            int temp = x;
            int idx = 0;
            
            while(temp) {
                freq[idx++] += (temp&1);
                temp = temp>>1;
            }
    
        }
        
        for(auto x: freq) {
            cout << x << " ";
        }
        cout << endl;
        
        int temp = k;
        int ans = 0;
        int idx = 0;
        while(idx < 33) {
            int a = temp&1;
            if(freq[idx++] % 2 != a) {
                ans++;
            }
            temp = temp>>1 >= 0 ? temp>>1 : 0;;
        }
        return ans;
    }
};