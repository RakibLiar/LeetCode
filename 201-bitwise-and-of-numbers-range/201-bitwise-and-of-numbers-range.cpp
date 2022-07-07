class Solution {
public:
    int countBit(int n) {
        int cnt = 0;
        while(n) {
            cnt++;
            n >>= 1;
        }
        return cnt;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(countBit(left) != countBit(right))
            return 0;
        vector<vector<int>> vec;
        for(int i=0; left != 0 && right != 0; i++) {
            int a = left&1;
            int b = right&1;
            left /= 2;
            right /= 2;
            vec.push_back({i, a|b, a&b});
        }
        reverse(vec.begin(), vec.end());
        int ans = 0;
        for(auto v: vec) {
            if(v[1] != v[2])
                break;
            if(v[2])
                ans += (1 << v[0]);
        }
        return ans;
    }
};