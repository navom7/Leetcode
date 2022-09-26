//Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        int res = 0;
        int tp = 1;
        while(left > 0 && right > 0){
            int a = left&1;
            int b = right&1;
            if(a != b){
                res = 0;
            } else {
                res = (tp)*a + res;
            }
            tp = tp<<1;
            left = left >> 1;
            right = right >> 1;
        }
        if(left != right){
            return 0;
        }
        return res;
    }
};
