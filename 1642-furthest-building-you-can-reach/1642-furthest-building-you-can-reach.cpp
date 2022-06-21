class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i;
        for(i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                int a = nums[i] - nums[i-1];
                pq.push(a);
                if(pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();
                }
                if(bricks < 0) break;
            }
        }
        return i-1;
    }
};