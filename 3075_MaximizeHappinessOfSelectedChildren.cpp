/*
3075. Maximize Happiness of Selected Children
You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
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

int main() {
    
    return 0;
}