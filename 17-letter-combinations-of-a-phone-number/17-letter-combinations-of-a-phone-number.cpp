class Solution {
public:
    vector<string> result;
    vector<string> numbers{"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void letterResult(int pos, int sz, string digits, string res="") {
        if(pos == sz) {
            result.push_back(res);
            return;
        }
        int digit = digits[pos]-'0';
        for(int i=0; i<numbers[digit].size(); i++) {
            letterResult(pos+1, sz, digits, res+numbers[digit][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        letterResult(0,digits.size(),digits);
        return result;
    }
};