class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=n-1; i>=0; i--) {
            int j=m;
            while(j>0 && nums1[j-1]>nums2[i]) {
                nums1[j] = nums1[j-1];
                j--;
            }
            nums1[j] = nums2[i];
            m++;
        }
    }
};