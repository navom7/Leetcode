class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edgeList(n, vector<int>());
        vector<int> degree(n, 0);
        if(n == 1) {
            return {0};
        }
        
        for(auto x: edges) {
            edgeList[x[0]].push_back(x[1]);
            edgeList[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
            
        }
        int remainingNodes = n;
        while(remainingNodes > 2) {
            
            int qsize = q.size();
            remainingNodes -= qsize;
            // cout << q.size() << endl;
            for(int k = 0; k < qsize; k++) {
                
                int f = q.front();
                q.pop();

                degree[f]--;
                cout << f << " " << degree[f] << endl;
                for(auto x: edgeList[f]) {
                    degree[x]--;
                    if(degree[x] == 1) {
                        q.push(x);
                    }
                }
            }
        }
        
        vector<int> res;
        
        while(!q.empty()) {
            int a = q.front();
            res.push_back(a);
            q.pop();
        }
        
        return res;
    }
};