/*
1202. Smallest String With Swaps

You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/


#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &res, int i) {

        cout << i << endl;
        visited[i] = true;
        res.push_back(i);

        for(auto x: graph[i]) {
            if(visited[x] == false) {
                dfs(graph, visited, res, x);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> graph(n);
        for(auto x: pairs) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        // for(int i = 0; i < n; i++) {
        //     cout << i << ": ";
        //     for(auto x: graph[i]) {
        //         cout << x <<" ";
        //     }
        //     cout << endl;
        // }
        // cout << n << " is the size." << endl;

        // return "abc";
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            // cout << endl << "Visited: " << i << " " << visited[i] << endl;
            if(!visited[i]) {
                vector<int> indexes;
                dfs(graph, visited, indexes, i);
                cout << endl << "indexes for " << i << ": ";
                for(auto x: indexes) {
                    cout << x << " ";
                }
                cout << endl;
                string str = "";
                for(auto x: indexes) {
                    str += s[x];
                }
                cout << str << " : is str" << endl;
                sort(str.begin(), str.end());
                cout << str << " after sorting" << endl;
                int k = 0;
                sort(indexes.begin(), indexes.end());
                for(auto x: indexes) {
                    s[x] = str[k++];
                }
            }
        }
        return s;
    }
};