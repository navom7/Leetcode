class Solution {
public:
    long long maximumHappinessSum(vector<int>& hp, int k) {
        long long ans = 0;
        int n = hp.size();
        sort(hp.begin(), hp.end());
        int temp = k;
        for(int i = n-1; i >= 0 && temp > 0; i--) {
            int happ = hp[i] - k + temp;
            if(happ > 0) {
                ans += happ;
            }
            temp--;
        }
        
        return ans;
    }
};