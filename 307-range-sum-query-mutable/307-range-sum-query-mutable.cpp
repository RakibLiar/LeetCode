class NumArray {
public:
    vector<int> v, tree;
    int sz;
    void init(int node, int b, int e)
    {
        if (b == e) {
            tree[node] = v[b];
            return;
        }
        int Left = node * 2;
        int Right = node * 2 + 1;
        int mid = (b + e) / 2;
        init(Left, b, mid);
        init(Right, mid + 1, e);
        tree[node] = tree[Left] + tree[Right];
    }
    
    NumArray(vector<int>& nums) {
        v = nums;
        v.insert(v.begin(), 1, 0);
        tree = vector<int>(5*nums.size());
        sz = nums.size();
        init(1, 1, sz);
    }
    void update(int node, int b, int e, int i, int newvalue)
    {
        if (i > e || i < b)
            return;
        if (b >= i && e <= i) {
            tree[node] = newvalue;
            return;
        }
        int Left = node * 2;
        int Right = node * 2 + 1;
        int mid = (b + e) / 2;
        update(Left, b, mid, i, newvalue);
        update(Right, mid + 1, e, i, newvalue);
        tree[node] = tree[Left] + tree[Right];
    }
    
    void update(int index, int val) {
        update(1, 1, sz, index+1, val);
    }
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
    int sumRange(int left, int right) {
        return query(1,1,sz,left+1,right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */