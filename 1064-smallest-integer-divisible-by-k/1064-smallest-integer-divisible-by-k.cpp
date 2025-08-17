class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 0, i;
        unordered_set<int> st;
        for(i = 1; i<=k; i++) {
            num = (10 * num + 1) % k;
            if(num == 0) return i;
            if(st.find(num) != st.end()) return -1;
            st.insert(num);
        }
        return -1;
    }
};