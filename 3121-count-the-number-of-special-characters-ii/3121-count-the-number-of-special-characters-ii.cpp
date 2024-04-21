class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mp;
        unordered_map<char,int> visited;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int asci = int(ch);
            // cout << ch << " " << mp[ch] << " " << asci << endl;
            if(asci < 91 && visited[ch] == true) {
                continue;
            }
            mp[word[i]] = i;
            visited[ch] = true;
        }
        // for(auto x: mp) {
        //     cout << x.first << " " << x.second << endl;
        // }
        int ans = 0;
        
        unordered_map<char,int> ansmp;
        
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int asci = int(ch);
            
            char up = ch-32;
            
            if(mp[up] > mp[ch]) {
                ansmp[ch] = 1;
            } else {
                ansmp[ch] = 0;
            }
        }
        
        for(auto x: ansmp) {
            ans += x.second;
        }
        // cout << endl;
        // for(auto x: ansmp) {
        //     cout << x.first << " " << x.second << endl;
        // }
        return ans;
        
        
    }
};


