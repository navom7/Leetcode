class Solution {
public:
    
//     long long F(unordered_map<string, bool>& mp, string keys, int i, string target, int prevI, string cont) {

//         if(cont.size() > 10) {
//             return INT_MAX;
//         }
        
//         if(i >= 4 || keys == target) {
//             return 0;
//         }
        

//         char ch = keys[i];
//         int num = ch - '0';
        
//         int upper = (num+1)%10;
//         int lower = (num-1+10)%10;
        
//         char upch = '0' + upper;
//         char loch = '0' + lower;
        
//         long long ans = INT_MAX;
        
//         string ukeys = keys;
//         ukeys[i] = upch;
        
//         string lokeys = keys;
//         lokeys[i] = loch;
        


//         ans = min(ans, F(mp, keys, i+1, target, i, "0"));

//         if(!mp[ukeys] && cont.size() < 11) {
//             ans = min(ans, 1 + F(mp, ukeys, i, target, i, cont+'1'));
//             ans = min(ans, 1 + F(mp, ukeys, i+1, target, i, "0"));
//         }

//         if(!mp[lokeys] && cont.size() < 11) {
//             ans = min(ans, 1 + F(mp, lokeys, i, target, i, cont+'1'));
//             ans = min(ans, 1 + F(mp, lokeys, i+1, target, i, "0"));
//         }
        
//         return ans;
//     }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> mp;
        for(auto x: deadends) {
            mp[x] = true;
        }
        if(mp["0000"]) {
            return -1;
        }
        queue<string> q;
        q.push("0000");
        
        unordered_map<string, bool> visited;
        vector<int> dist(10001, INT_MAX);
        
        dist[0] = 0;
        
        while(!q.empty()) {
            string keys = q.front();
            int keysInt = stoi(keys);
            
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                char ch = keys[i];
                
                int num = ch - '0';

                int upper = (num+1)%10;
                int lower = (num-1+10)%10;

                char upch = '0' + upper;
                char loch = '0' + lower;

                string ukeys = keys;
                ukeys[i] = upch;
                int upkeyInt = stoi(ukeys);

                string lokeys = keys;
                lokeys[i] = loch;
                int lokeysInt = stoi(lokeys);
                
                if(!mp[ukeys] && !visited[ukeys]) {
                    visited[ukeys] = true;
                    if(dist[upkeyInt] > dist[keysInt]+1) {
                        dist[upkeyInt] = dist[keysInt]+1;
                    }
                    q.push(ukeys);
                }
                
                if(!mp[lokeys] && !visited[lokeys]) {
                    visited[lokeys] = true;
                    if(dist[lokeysInt] > dist[keysInt]+1) {
                        dist[lokeysInt] = dist[keysInt]+1;
                    }
                    q.push(lokeys);
                }
            }
        }
        
        
        int targetInt = stoi(target);
        return dist[targetInt] == INT_MAX ? -1 : dist[targetInt];
        
        
    }
};