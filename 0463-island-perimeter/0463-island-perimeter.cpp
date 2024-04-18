class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        int peri = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k++) {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        
                        if(nx < 0 
                           || nx >= R 
                           || ny < 0 
                           || ny >= C 
                           || grid[nx][ny] == 0) {
                            
                            peri++;
                        }
                    }
                }
            }
        }
        return peri;
    }
};