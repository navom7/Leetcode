class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int> xAxis;
        for(auto x: points) {
            xAxis.push_back(x[0]);
        }
        sort(xAxis.begin(), xAxis.end());
        
        int i = 0;
        int n = xAxis.size();
        int cnt = 0;
        
        
        int j = 0;
        
        while(i < n) {
            while(j < n && xAxis[j]-xAxis[i] <= w) {
                j++;
            }
            cnt++;
            i = j;
        }
        
        // int prev = 0;
        // for(int i = 0; i < n; i++) {
        //     if(xAxis[i]-xAxis[prev] == w) {
        //         cnt++;
        //         prev = i+1;
        //     }
        // }
        
        return cnt;
    }
};