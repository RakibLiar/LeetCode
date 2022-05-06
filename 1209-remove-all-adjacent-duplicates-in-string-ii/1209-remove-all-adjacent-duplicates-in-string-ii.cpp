class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i=0; i<s.size(); i++) {
            int cnt = 1;
            while(i+1<s.size() && s[i] == s[i+1]) {
                cnt++;
                i++;
            }
            int a = cnt;
            while(!st.empty() && st.top().first == s[i]) {
                a += st.top().second;
                st.pop();
            }
            int rem = a%k;
            if(rem) {
                st.push({s[i], rem});
            }
        }
        string res;
        while(!st.empty()) {
            pair<char, int> top = st.top();
            for(int i=0; i<top.second; i++) {
                res += top.first;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};