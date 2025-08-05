class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = fruits.size();
        for(int a: fruits) {
            for(int &b: baskets) {
                if(b >= a) {
                    b = 0;
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};