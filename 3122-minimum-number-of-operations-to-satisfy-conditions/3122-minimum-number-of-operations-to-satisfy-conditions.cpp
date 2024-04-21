class Solution {
    int R;
    int C;
public:
    int sum(vector<int> freq, int k) {
        int sum = 0;
        for(int i = 0; i < 10; i++) {
            if(i != k) {
                sum += freq[i];
            }
        }
        return sum;
    }
    
    int func(vector<vector<int>>& freq, int i, int num, vector<vector<int>>& dp) {
        if(i < 0 || num < 0 || num > 9 || i >= C) {
            return 0;
        }
        if(dp[i][num] != -1) {
            return dp[i][num];
        }
        int ans = INT_MAX;
        for(int k = 0; k < 10; k++) {
            if(k == num) {
                continue;
            }
            
            int tempSum = sum(freq[i], k);
            
            ans = min(ans, tempSum + func(freq, i+1, k, dp));
        }
        
        return dp[i][num] = ans;
        
    }
    
    int minimumOperations(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> freq(C, vector<int>(10, 0));
        for(int i = 0; i < C; i++){
            for(int j = 0; j < R; j++) {
                freq[i][grid[j][i]]++;
            }
        }
        // for(auto x: freq) {
        //     for(auto y: x) {
        //         cout << y << " ";
        //     } 
        //     cout << endl;
        // }
        
        vector<vector<int>> dp(C, vector<int>(10, -1));
        for(int k = 0; k < 10; k++) {
            int tempSum = sum(freq[0], k);
            int furtherSum = func(freq, 1, k, dp);
            ans = min(furtherSum+tempSum, ans);   
        }
        return ans;
    }
};