class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long len = arr.size(), buff = 0, res = 0, MOD = 1000000007;
        for(int i=0; i<=len; i++) {
            if(i == len) buff = 0;
            else buff = arr[i];
            
            if(st.empty() || buff >= arr[st.top()]) {
                st.push(i);
            } else {
                while(!st.empty() && buff < arr[st.top()]) {
                    long long ind = st.top();
                    st.pop();
                    long long left = ind - (st.empty() ? -1 : st.top());
                    long long right = i - ind;
                    res = (res + arr[ind] * left * right)% MOD;
                }
                st.push(i);
            }
        }
        return res;
    }
};