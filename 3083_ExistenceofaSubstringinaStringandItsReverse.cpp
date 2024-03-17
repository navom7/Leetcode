/*

3083. Existence of a Substring in a String and Its Reverse

Given a string s, find any substring of length 2 which is also present in the reverse of s.

Return true if such a substring exists, and false otherwise.

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
    bool isSubstringPresent(string s) {
        int n = s.size();
        string temp = s;
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < n-1; i++) {
            
            string a = "";
            a = a + s[i]+s[i+1];
            
            string b = "";
            b = b + temp[i]+temp[i+1];
            
            size_t findA = temp.find(a);
            if(findA != string::npos) {
                return true;
            }
            
            size_t findB = s.find(b);
            if(findB != string::npos) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}