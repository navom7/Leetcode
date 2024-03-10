/*

3074. Apple Redistribution into Boxes

You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

 

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
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int appleSum = 0;
        int capSum = 0;
        for(auto x: apple) {
            appleSum += x;
        }
        sort(capacity.begin(), capacity.end());
        int n = capacity.size();
        int cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            capSum += capacity[i];
            cnt++;
            if(capSum >= appleSum) {
                return cnt;
            }
        }
        return cnt;
    }
};

int main() {
    
    return 0;
}