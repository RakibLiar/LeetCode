class Solution {
public:
    int hIndex(vector<int>& cit) {
        int low = 0, high = cit.size()-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(cit[mid] + mid < cit.size()) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return cit.size() - low;
    }
};