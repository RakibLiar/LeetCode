class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = -1, cnt = 0, pos = 0;
        for(int i=1; i<=3000; i++) {
            if(pos < arr.size() && arr[pos] == i) {
                pos++;
            } else {
                cnt++;
            }
            if(cnt == k) return i;
        }
        return 1001;
    }
};