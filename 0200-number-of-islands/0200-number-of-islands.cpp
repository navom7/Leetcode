class Solution {
public:
    int R;
    int C;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        grid[i][j] = '0';
        
        for(int k = 0; k < 4; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];
            
            if(nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == '1') {
                dfs(grid, nx, ny);
            }
        }
}
    int numIslands(vector<vector<char>>& grid) {
        R = grid.size();
        C = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};