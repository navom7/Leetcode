/*
100237. Count Submatrices with Top-Left Element and Sum Less Than k

You are given a 0-indexed integer matrix grid and an integer k.

Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int R = grid.size();
        int C = grid[0].size();
        int ans = 0;
        
        vector<vector<long long>> arr(R, vector<long long> (C, INT_MAX));
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                int sumUp = 0, sumLeft = 0, sumDiagonal = 0;
                if(i > 0) {
                    sumUp = arr[i-1][j];
                }
                if(j > 0) {
                    sumLeft = arr[i][j-1];
                }
                if(i > 0 && j > 0) {
                    sumDiagonal = arr[i-1][j-1];
                }
                arr[i][j] = sumUp + sumLeft + grid[i][j] - sumDiagonal;
                if(arr[i][j] <= k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}