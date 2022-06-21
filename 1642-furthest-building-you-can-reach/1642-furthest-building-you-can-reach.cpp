class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        priority_queue<int> pq;
        int i;
        for(i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                int a = nums[i] - nums[i-1];
                if(bricks>=a) {
                    pq.push(a);
                    bricks -= a;
                } else if(ladders != 0) {
                    ladders--;
                    if(!pq.empty() && pq.top()>a) {
                        int t = pq.top();
                        pq.pop();
                        bricks+=t;
                        i--;
                    }
                } else {
                    break;
                }
            }
        }
        return i-1;
    }
};