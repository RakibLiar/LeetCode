class Solution {
public:
    vector<int>tree;
    int query(int node, int b, int e, int i, int j)
    {
        if (i > e || j < b)
            return 0;
        if (b >= i && e <= j)
            return tree[node];
        int Left = node * 2;
        int Right = node * 2 + 1;
        int mid = (b + e) / 2;
        int p1 = query(Left, b, mid, i, j);
        int p2 = query(Right, mid + 1, e, i, j);
        return p1 + p2;
    }
    void update(int node, int b, int e, int i, int newvalue)
    {
        if (i > e || i < b)
            return;
        if (b >= i && e <= i) {
            tree[node] += newvalue;
            return;
        }
        int Left = node * 2;
        int Right = node * 2 + 1;
        int mid = (b + e) / 2;
        update(Left, b, mid, i, newvalue);
        update(Right, mid + 1, e, i, newvalue);
        tree[node] = tree[Left] + tree[Right];
    }
    vector<int> countSmaller(vector<int>& nums) {
        tree = vector<int>(70100, 0);
        vector<int> res(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            int a = nums[i] + 10001;
            update(1, 1, 20002, a, 1);
            int b = query(1,1,20002,1 ,a-1);
            res[i] = b;
        }
        return res;
    }
};