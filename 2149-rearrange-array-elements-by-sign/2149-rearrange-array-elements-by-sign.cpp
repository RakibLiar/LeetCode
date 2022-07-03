class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, ans;
        for(int n: nums) {
            if(n>0)
                pos.push_back(n);
            else
                neg.push_back(n);
        }
        for(int i=0; i<pos.size(); i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};