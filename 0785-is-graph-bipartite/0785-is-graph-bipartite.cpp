class Solution {
public:
    int N;
    
    
    bool dfs_helper(vector<vector<int>>& graph, int node, int parent, vector<int>& visited, int color) {
        visited[node] = color;
        
        for(auto x: graph[node]) {
            if(visited[x] == 0){
                bool isB = dfs_helper(graph, x, node, visited, 3-color);
                if(isB == false) {
                    return false;
                }
            } else if(visited[x] == color && x != parent) {
                return false;
            }
        }
        return true;
    }
    
    
    bool dfs(vector<vector<int>>& graph) {
        vector<int> visited(N, 0);
        
        for(int i = 0; i < N; i++) {
            int color = 1;
            if(visited[i] == 0) {
                bool res = dfs_helper(graph, i, -1, visited, color);
                if(res == false) {
                    return false;
                }
            }
            
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        N = graph.size();
        return dfs(graph);
    }
};