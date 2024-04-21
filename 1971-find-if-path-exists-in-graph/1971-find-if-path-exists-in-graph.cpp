class Graph{
    int V;
    list<int>* l;
public:
    Graph(int n) {
        V = n;
        l = new list<int>[V];
    }
    
    void addEdge(int a, int b) {
        l[a].push_back(b);
        l[b].push_back(a);
    }
    
    bool dfs(int source, int dest, vector<bool>& visited) {
        visited[source] = true;
        if(source == dest) {
            return true;
        }
        
        for(auto x: l[source]) {
            if(!visited[x]) {
                bool found = dfs(x, dest, visited);
                if(found) {
                    return true;
                }
            }
        }
        return false;
    }

};


class Solution {
public:
    
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        Graph g(n);
        for(auto x: edges) {
            g.addEdge(x[0], x[1]);
        }
        vector<bool> visited(n, false);
        return g.dfs(source, dest, visited);
    }
};