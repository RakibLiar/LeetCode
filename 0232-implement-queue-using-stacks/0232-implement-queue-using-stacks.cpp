class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> q;
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!q.empty()) {
            st.push(q.top());
            q.pop();
        }
    }
    
    int pop() {
        int top = peek();
        st.pop();
        return top;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */