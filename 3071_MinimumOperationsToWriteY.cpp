/*
3071. Minimum Operations to Write the Letter Y on a Grid

You are given a 0-indexed n x n grid where n is odd, and grid[r][c] is 0, 1, or 2.

We say that a cell belongs to the Letter Y if it belongs to one of the following:

The diagonal starting at the top-left cell and ending at the center cell of the grid.
The diagonal starting at the top-right cell and ending at the center cell of the grid.
The vertical line starting at the center cell and ending at the bottom border of the grid.
The Letter Y is written on the grid if and only if:

All values at cells belonging to the Y are equal.
All values at cells not belonging to the Y are equal.
The values at cells belonging to the Y are different from the values at cells not belonging to the Y.
Return the minimum number of operations needed to write the letter Y on the grid given that in one operation you can change the value at any cell to 0, 1, or 2.

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
    
    
    
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int ans = 0;
        
        int midCol = C/2;
        
        vector<int> mp(3, 0);
        
        for(int i = 0; i <= midCol; i++) {
            // cout << grid[i][i] << " " << grid[i][R-1-i] << " " << grid[R-1-i][midCol] << endl;
            mp[grid[i][i]]++;
            mp[grid[i][R-1-i]]++;
            mp[grid[R-1-i][midCol]]++;
        }
        mp[grid[midCol][midCol]] -= 2;
        cout << endl;
        
        // sort(mp.begin(), mp.end());
        // ans += (mp[0] + mp[1]);
        
        vector<int> count(3, 0);
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                count[grid[i][j]]++;
            }
        }
        count[0] -= mp[0];
        count[1] -= mp[1];
        count[2] -= mp[2];
        
        vector<pair<int,int>> mpPair;
        vector<pair<int,int>> countPair;
        
        for(int i = 0; i < 3; i++) {
            // cout << count[i] << " " << mp[i] << endl;
            mpPair.push_back({mp[i], i});
            countPair.push_back({count[i], i});
        }
        
        sort(mpPair.begin(), mpPair.end());
        sort(countPair.begin(), countPair.end());
        
        // for(int i = 0; i < 3; i++) {
        //     cout << mpPair[i].second <<" " << mpPair[i].first << "  |  " << countPair[i].second <<" " << countPair[i].first << endl;
        // }
        
        auto a = mpPair[0];
        auto b = countPair[0];
        
        auto aa = mpPair[1];
        auto bb = countPair[1];
        
        auto aaa = mpPair[2];
        auto bbb = countPair[2];
        if(aaa.second != bbb.second) {
            return a.first+b.first+aa.first+bb.first;
        }
        int suma = a.first+aaa.first + b.first + bb.first;
        int sumb = b.first+bbb.first + a.first + aa.first;
        
        return suma > sumb ? sumb : suma;
    }
};

int main() {
    
    return 0;
}