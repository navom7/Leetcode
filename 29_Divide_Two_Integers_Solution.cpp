// Problem statement: Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

class Solution {
public:
    int divide(int dvd, int dvs) {
        if(dvd == 0)
            return 0;
        if(dvd <= INT_MIN && dvs == -1) return INT_MAX;
        if(dvd <= INT_MIN && dvs == 1) return INT_MIN;
        int sign1 = dvd < 0 ? -1 : 1;
        int sign2 = dvs < 0 ? -1 : 1;
        cout << sign1 << " " << sign2 << endl;
        long int a = abs(dvd);
        long int b = abs(dvs);
        long int ans = 0;
        for(int i = 31; i >= 0; i--){
            if((b<<i) <= a){
                a = a - (b<<i);
                ans += (1<<i);
                if(ans > INT_MAX){
                    cout << "nanhe ";
                    ans = (1<<31)-1;
                    break;
                }
            }
        }
        return (sign1*sign2)*ans;
        
    }
};
