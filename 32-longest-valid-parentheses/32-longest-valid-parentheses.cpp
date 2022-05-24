class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        vector<int> v(s.size(), 0);
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push({s[i], i});
            } else {
                if(!st.empty()) {
                    auto top = st.top();
                    st.pop();
                    v[top.second] = 1;
                    v[i] = 1;
                }
            }
        }
        int cnt = 0, result = 0;
        for(int a: v) {
            cnt = a*(cnt + 1);
            result = max(result, cnt);
        }
        return result;
    }
};