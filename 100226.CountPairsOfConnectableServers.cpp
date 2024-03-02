/*

100226. Count Pairs of Connectable Servers in a Weighted Tree Network
User Accepted:1649
User Tried:2329
Total Accepted:1695
Total Submissions:3355
Difficulty:Medium
You are given an unrooted weighted tree with n vertices representing servers numbered from 0 to n - 1, an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional edge between vertices ai and bi of weight weighti. You are also given an integer signalSpeed.

Two servers a and b are connectable through a server c if:

a < b, a != c and b != c.
The distance from c to a is divisible by signalSpeed.
The distance from c to b is divisible by signalSpeed.
The path from c to b and the path from c to a do not share any edges.
Return an integer array count of length n where count[i] is the number of server pairs that are connectable through the server i.

 

*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph
{
    int V;
    list<pair<int,int>> *l;
public:
    Graph(int n) {
        V = n;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int i, int j, int wt) {
        l[i].push_back({wt, j});
        l[j].push_back({wt, i});
    }

    void dfs(int k, int node, int sum, int& ans, int parent) {
        if(sum%k == 0) {
            ans++;
        }
        for(auto nbrs: l[node]) {
            int nbr = nbrs.second;
            int wt = nbrs.first;
            if(nbr != parent) {
                dfs(k, nbr, sum+wt, ans, node);
            }
        }
    }

    vector<int> countPairs(int k) {
        vector<int> res;
        for(int i = 0; i < V; i++) {
            vector<int> nodeCount;
            
            for(auto x: l[i]) {
                int ans = 0;
                dfs(k, x.second, x.first, ans, i);
                if(ans != 0) {
                    nodeCount.push_back(ans);
                }
                
            }
            int nodeCSize = nodeCount.size();
            if(nodeCSize>1) {
                int ans = 0;
                for(int g = 0; g < nodeCSize; g++) {
                    for(int h = g+1; h < nodeCSize; h++) {
                        ans += (nodeCount[g]*nodeCount[h]);
                    }
                }
                res.push_back(ans);
            } else {
                res.push_back(0);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int k) {
        int n = edges.size();
        Graph g(n+1);
        for(auto x: edges) {
            g.addEdge(x[0], x[1], x[2]);
        }
        
        return g.countPairs(k);
    }
};

int main() {


    return 0;
}