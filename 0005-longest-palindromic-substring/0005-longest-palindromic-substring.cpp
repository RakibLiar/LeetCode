class Solution {
public:
    string longestPalindrome(string s) {
        int first = 0, last = 0, res = 1;
        for(int mid = 0; mid < s.size()-1; mid++) {
            int left = mid-1, right = mid+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if(right - left - 1 > res) {
                res = right - left - 1;
                last = right - 1;
                first = left + 1;
            }
            left = mid, right = mid+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                right++;
                left--;
            }
            if(right - left - 1 > res) {
                res = right - left - 1;
                last = right - 1;
                first = left + 1;
            }
        }
        string result;
        for(int i=first; i <= last; i++) result += s[i];

        return result;
    }
};