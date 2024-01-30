class Solution {
public:
    int evaluate(int a, int b, string sign) {
        if(sign == "+") return a+b;
        if(sign == "-") return a-b;
        if(sign == "*") return a*b;
        return a/b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s: tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = evaluate(b, a, s);
                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};