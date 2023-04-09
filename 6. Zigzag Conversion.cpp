// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000





class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.size();
        if(numRows == 1) {
            return s;
        }
        int numCols = sz/2+1;
        vector<vector<char> > matrix(numRows, vector<char>(numCols, ' '));
        int col = 0;
        int k = 0;
        matrix[0][0] = s[k++];
        while(k < sz) {
            for(int i = 1; i < numRows; i++) {
                if(k < sz) {
                    matrix[i][col] = s[k++];
                } else {
                    break;
                }
            }
            for(int i = numRows-2; i >= 0; i--) {
                if(k < sz) {
                    matrix[i][++col] = s[k++];
                } else {
                    break;
                }
            }

        }
        string output = "";
        for(auto x : matrix) {
            for(auto y: x) {
                if(y != ' ') {
                    output += y;
                }
            }
        }
        return output;
    }
};
