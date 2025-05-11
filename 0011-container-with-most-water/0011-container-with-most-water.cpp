class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0, end = height.size()-1, res = 0;
        while(st < end) {
            res = max(res, (end - st) * min(height[st], height[end]));
            if(height[st] < height[end]) st++;
            else end--;
        }
        return res;
    }
};