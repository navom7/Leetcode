class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        int n = s1.size();
        if(n > s2.size()) {
            return false;
        }
        
        for(char x: s1) {
            mp[x]++;
        }
        
        for(int i = 0; i < s2.size(); i++) {
            if(mp[s2[i]] > 0) {
                int j = i;
                int temp = n;
                unordered_map<char,int> nmp = mp;
                for( ; j < i+n; j++) {
                    if(nmp[s2[j]] == 0) {
                        break;
                    }
                    nmp[s2[j]]--;
                    temp--;
                    if(temp == 0) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};