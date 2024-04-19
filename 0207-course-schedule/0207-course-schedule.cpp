
class Graph{
    int V;
    list<int>* l;
public:
    Graph(int n){
        V = n;
        l = new list<int>[V];
    }
    
    void addEdge(int a, int b) {
        l[a].push_back(b);
    }
    
    bool findCycle(int source, vector<bool>& visited, vector<bool>& instack) {
        visited[source] = true;
        instack[source] = true;
        
        for(auto x: l[source]) {
            cout << source << " " << x << " " << visited[x] << " " << instack[x] << " " << endl;
            if(!visited[x]){
                bool found = findCycle(x, visited, instack);
                if(found){
                    return true;
                }
            } else {
                if(instack[x] == true) {
                    return true;
                }
            }
        }
        instack[source] = false;
        return false;
    }
    
    
};


class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prer) {
        Graph g(numCourses);
        for(auto x: prer) {
            g.addEdge(x[0],x[1]);
        }
        
        
        vector<bool> visited(numCourses, false);
        vector<bool> instack(numCourses, false);
        
        for(int i = 0; i < numCourses; i++) {
            // vector<bool> visited(numCourses, false);
            bool found = g.findCycle(i, visited, instack);
            if(found) {
                return false;
            }
        }
        return true;
    }
};