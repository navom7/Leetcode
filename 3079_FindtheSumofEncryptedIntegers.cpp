/*

3079. Find the Sum of Encrypted Integers
You are given an integer array nums containing positive integers. We define a function encrypt such that encrypt(x) replaces every digit in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.

Return the sum of encrypted elements.



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
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) {
            int temp = x;
            int ld = INT_MIN;
            while(temp) {
                int ntemp = temp%10;
                if(ntemp > ld) {
                    ld = ntemp;
                }
                temp = temp/10;
            }
            cout << ld << endl;
            temp = x;
            int digitc = 0;
            while(temp) {
                temp = temp/10;
                digitc++;
            }
            int num = 0;
            while(digitc--) {
                num = num*10 + ld;
            }
            sum += num;
        }
        return sum;
    }
};

int main() {
    
    return 0;
}