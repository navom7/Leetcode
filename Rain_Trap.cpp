//42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int trapAmount = 0;
        if(n < 3) return 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = arr[0];
        rightMax[n-1] = arr[n-1];
        for(int i = 1; i < n-1; i++) {
            leftMax[i] = max(leftMax[i-1], arr[i]);
            rightMax[n-i-1] = max(rightMax[n-i], arr[n-i-1]);
        }
        for(int i = 1; i < n-1; i++) {
            trapAmount += min(leftMax[i], rightMax[i]) - arr[i];
        }
        return trapAmount;
    }
};