class Solution {
public:
    int R;
    int C;
    void flipRow(int r, vector<vector<int>>& grid) {
        for(int i = 0; i < C; i++) {
            grid[r][i] = (1-grid[r][i]);
        }
    }
    
    void flipCol(int c, vector<vector<int>>& grid) {
        for(int i = 0; i < R; i++) {
            grid[i][c] = (1-grid[i][c]);
        }
    }
    
    int countSet(int c, vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 0; i < R; i++) {
            cnt += grid[i][c];
        }
        return cnt;
    }
    
    int addAll(vector<vector<int>>& grid) {
        int finalSum = 0;
        for(int i = 0; i < R; i++) {
            int tempSum = 0;
            int t = 1;
            for(int j = C-1; j >= 0; j--) {
                tempSum += t*grid[i][j];
                t = t << 1;
            }
            finalSum += tempSum;
        }
        return finalSum;
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        
        for(int i = 0; i < R; i++) {
            if(grid[i][0] == 0) {
                flipRow(i, grid);
            }
        }
        
        for(int j = 0; j < C; j++) {
            int setBits = countSet(j, grid);
            if(setBits <= (R/2)) {
                flipCol(j, grid);
            }
        }
        // for(auto x: grid) {
        //     for(auto y: x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        return addAll(grid);
        
    }
    
    
};