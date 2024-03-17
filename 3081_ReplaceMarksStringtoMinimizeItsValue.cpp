/*

3081. Replace Question Marks in String to Minimize Its Value

You are given a string s. s[i] is either a lowercase English letter or '?'.

For a string t having length m containing only lowercase English letters, we define the function cost(i) for an index i as the number of characters equal to t[i] that appeared before it, i.e. in the range [0, i - 1].

The value of t is the sum of cost(i) for all indices i.

For example, for the string t = "aab":

cost(0) = 0
cost(1) = 1
cost(2) = 0
Hence, the value of "aab" is 0 + 1 + 0 = 1.
Your task is to replace all occurrences of '?' in s with any lowercase English letter so that the value of s is minimized.

Return a string denoting the modified string with replaced occurrences of '?'. If there are multiple strings resulting in the minimum value, return the lexicographically smallest one.
*/

#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>

using namespace std;

#define ll long long
#define um unordered_map
int R;
int C;

class Solution {
public:
    struct compare {
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };
    string minimizeStringValue(string s) {
        int arr[26] = {0};
        
        int qcount = 0;
        for(int k = 0; k < s.size(); k++) {
            char ch = s[k];
            if(ch == '?') {
                qcount++;
                // int cnt = INT_MAX;
                // char charReplace;
                // for(int i = 25; i >= 0; i--) {
                //     // cout << cnt << " " <<  arr[i] << endl;
                //     if(arr[i] <= cnt) {
                //         charReplace = 'a'+i;
                //         cnt = arr[i];
                //     }
                // }
                // // cout << arr[charReplace-'a'] << endl;
                // arr[charReplace-'a']++;
                // s[k] = charReplace;
            } else {
                int idx = ch-'a';
                arr[idx]++;
            }
        }
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, compare> pq;
        for(int i = 0; i < 26; i++) {
            pq.push({arr[i], 'a'+i});
        }
        
        string tempStr = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '?') {
                auto x = pq.top();
                // cout << x.first << " " << x.second << endl;
                pq.pop();

                int charCount = x.first;
                char topChar = x.second;
                tempStr += x.second;

                pq.push({x.first+1, x.second});
            }
        }
        int k = 0;
        sort(tempStr.begin(), tempStr.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '?') {
                s[i] = tempStr[k++];
            }
        }
        
        
        return s;
    }
};

int main() {
    
    return 0;
}