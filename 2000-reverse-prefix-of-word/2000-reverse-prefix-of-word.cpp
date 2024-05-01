class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t idx = word.find(ch);
        
        cout << idx << endl;
        
        reverse(word.begin(), word.begin()+idx+1);
        
        return word;
    }
};