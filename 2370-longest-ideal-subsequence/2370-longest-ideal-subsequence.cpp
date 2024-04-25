class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        if(n == 1) {
            return 1;
        }
        vector<int> abt(26, 0); // 
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            // cout << i << endl;
            char ch = s[i];
            int chNum = ch-'a';
            // cout << ch << " " << chNum << endl;
            
            int tempAns = abt[chNum];
            
            for(int j = chNum-k; j < 26 && j <= chNum+k; j++) {
                if(j < 0) {
                    continue;
                }
                // cout << "before: " << tempAns << " ,";
                tempAns = max(tempAns, abt[j]+1);
                // cout << "after: " << tempAns << " and " << abt[j] << " " << j << endl;
                
            }
            abt[chNum] = tempAns;
            if(abt[chNum] > ans) {
                ans = abt[chNum];
            }
            // cout << endl;
        }
        
        return ans;
        
    }
};