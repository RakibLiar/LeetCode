class Solution {
public:
    int minPartitions(string n) {
        char c = 0;
        for(auto a: n) {
            c = max(a, c);
        }
        return c-'0';
    }
};