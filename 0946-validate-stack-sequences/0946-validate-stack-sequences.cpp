class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int first = 0, second = 0;
        while(first < pushed.size() && second < popped.size()) {
            if(!st.empty() && st.top() == popped[second]) {
                second++;
                st.pop();
            } else {
                st.push(pushed[first]);
                first++;
            }
        }
        while(!st.empty() && second < popped.size() && st.top() == popped[second]) {
            second++;
            st.pop();
        }
        return st.empty() && first == pushed.size() && second == popped.size();
    }
};