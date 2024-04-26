class Compare{
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    int R;
    int C;
    int minFallingPathSum(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        
        
        for(int i = 1; i < R; i++) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
            for(int j = 0; j < C; j++) {
                pq.push({grid[i-1][j], j});
            }
            for(int j = 0; j < C; j++) {
                auto tp = pq.top();
                if(tp.second == j) {
                    pq.pop();
                    auto tp2 = pq.top();
                    grid[i][j] += tp2.first;
                    pq.push(tp);
                } else {
                    grid[i][j] += tp.first;
                }
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j < C; j++) {
            ans = min(ans, grid[R-1][j]);
        }
        
        // for(auto x: grid) {
        //     for(auto y: x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        
        return ans;
    }
};


// [-73,  61,   43,  -48,  -36],
//  [3,   30,   27,  57,    10],
//  [96,  -76,  84,  59,   -15],
//  [5,   -49,  76,  31,   -7],
//  [97,   91,  61,  -46,  67]]
 

// -73 61 43 -48 -36 
// -45 -43 -46 -16 -63 
// 33 -149 11 -14 -88 
// -144 -137 -73 -118 -156 
// -59 -65 -95 -202 -82 

// -73   61    43   -48   -36 
// 64   -43   -21    21   -38 
// 53   -97    41    21    6 
// -92  -8    -21    37   14 
// 89   -1    53    -67   104 