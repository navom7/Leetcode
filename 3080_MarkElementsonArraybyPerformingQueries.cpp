/*

3080. Mark Elements on Array by Performing Queries

You are given a 0-indexed array nums of size n consisting of positive integers.

You are also given a 2D array queries of size m where queries[i] = [indexi, ki].

Initially all elements of the array are unmarked.

You need to apply m queries on the array in order, where on the ith query you do the following:

Mark the element at index indexi if it is not already marked.
Then mark ki unmarked elements in the array with the smallest values. If multiple such elements exist, mark the ones with the smallest indices. And if less than ki unmarked elements exist, then mark all of them.
Return an array answer of size m where answer[i] is the sum of unmarked elements in the array after the ith query.

*/

#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>

using namespace std;

#define ll long long
#define um unordered_map
int R;
int C;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        vector<pair<int,int>> pvec;
        int n = nums.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < nums.size(); i++) {
            pvec.push_back({nums[i], i});
            sum += nums[i];
        }
        sort(pvec.begin(), pvec.end());
        vector<long long> res;
        int k = 0;
        cout << sum << endl;
        for(auto hk: queries) {
            int idx = hk[0];
            int cnt = hk[1];
            cout << idx << " " << cnt << " " << k << " ";
            if(!visited[idx]) {
                sum -= nums[idx];
                visited[idx] = true;
            }
            cout << sum << " ";
            while(cnt > 0 && k < nums.size()) {
                auto pr = pvec[k++];
                int value = pr.first;
                int idxn = pr.second;
                if(idxn < nums.size() && !visited[idxn]) {
                    sum -= value;
                    visited[idxn] = true;
                    cnt--;
                }
            }
            cout << sum << endl;
            res.push_back(sum);
        }
        return res;
    }
};

int main() {
    
    return 0;
}