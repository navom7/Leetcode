class Solution {
    int R;
    int C;
public:
    
    pair<int,int> bfs(vector<vector<int>>& land, int i, int j){
        int dx[] = {0,1};
        int dy[] = {1,0};
        
        queue<pair<int,int>> q;
        q.push({i,j});
        // int a = INT_MIN, b = INT_MIN;
        
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(int k = 0; k < 2; k++) {
                int nx = f.first+dx[k];
                int ny = f.second+dy[k];
                
                if(nx < R && ny < C && land[nx][ny] == 1) {
                    land[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(q.empty()) {
                return {f.first, f.second};
            }
        }
        return {-1,-1};
    }
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        R = land.size();
        C = land[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(land[i][j] == 1) {
                    pair<int,int> end = bfs(land, i, j);
                    if(end.first == -1) {
                        continue;
                    }
                    res.push_back({i,j,end.first, end.second});
                }
            }
        }
        // if(res.size() == 0 || res[0].size() == 0)
        //     res.push_back({0});
        return res;
        
    }
};