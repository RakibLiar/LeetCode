class Solution {
public:
    int minimumLength(string s) {
        int low = 0, high = s.size()-1;
        while(low < high) {
            if(s[low] == s[high]) {
                char ch = s[low];
                while(low <= high) {
                    if(s[low] == ch) low++;
                    if(s[high] == ch) high--;
                    if(s[high] != ch && s[low] != ch) break;
                }
            } else {
                break;
            }
        }
        //cout<<low<<" "<<high<<endl;
        return (low > high) ? 0 : high - low + 1;
    }
};