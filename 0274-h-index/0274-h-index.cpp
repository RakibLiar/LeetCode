class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size(), res = 0;
        while(low <= high) {
            int mid = (low + high)/2;
            int cnt = 0;
            for(int a: citations) {
                if(a >= mid) cnt++;
            }
            if(cnt >= mid) {
                res = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return res;
    }
};