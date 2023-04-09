// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res = merge(nums1, nums2);
        for(auto x: res) {
            cout << x << " ";
        }
        cout << endl;
        int total = n+m;
        if(total < 2) {
            cout << "here\n";
            return res[0];
        }
        int mid = (total)/2;
        if((n+m)&1) {
            cout << total << " " << mid << endl;
            cout << "mi\n";
            return res[mid];
        } else {
            cout << "there\n";
            int a = res[mid];
            int b = res[mid-1];
            cout << total << " " << mid << endl;
            cout << a << " " << b << endl;
            double res = (double)a + (double)b;
            return (double)res/2.0;
        }
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n) {
            res.push_back(nums1[i]);
            i++;
        }

        while(j < m) {
            res.push_back(nums2[j]);
                j++;
        }
        return res;
    }
};
