bool customComparator(vector<int>& a, vector<int>& b) {
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

class Solution {
public:
    int R;
    int C;
    int findMax(int a, int b, int c) {
        return max(a, max(b,c));
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        R = cuboids.size();
        C = cuboids[0].size();

        for(int i = 0; i < R; i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        
        sort(cuboids.begin(), cuboids.end(), customComparator);
        
        cout << endl;
        
        int n = cuboids.size();
        
        vector<int> dp(n, INT_MIN);
        
        dp[0] = max(cuboids[0][0], max(cuboids[0][1], cuboids[0][2]));
        int ans = dp[0];
        for(int i = 1; i < n; i++) {
            int x = cuboids[i][0];
            int y = cuboids[i][1];
            int z = cuboids[i][2];
            
            int mx = findMax(x, y, z);
            dp[i] = mx;
            
            for(int j = 0; j < i; j++) {
                int a = cuboids[j][0];
                int b = cuboids[j][1];
                int c = cuboids[j][2];
                if(a <= x && b <= y && c <= z) {
                    int newMax = mx + dp[j];
                    if(newMax > dp[i]) {
                        dp[i] = newMax;
                    }
                }
            }
            
        }
        for(auto x: dp) {
            ans = max(x, ans);
        }
        
        
        return ans;
    }
};