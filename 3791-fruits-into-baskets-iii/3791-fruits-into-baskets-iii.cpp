class Solution {
public:
    vector<int> segTree;

    void build(int currentIndex, int left, int right, vector<int> &baskets) {
        if(left == right) {
            segTree[currentIndex] = baskets[left];
            return;
        }
        int mid = (left+right)/2;
        build(2*currentIndex+1, left, mid, baskets);
        build(2*currentIndex+2, mid+1, right, baskets);

        segTree[currentIndex] = max(segTree[2*currentIndex+1], segTree[2*currentIndex+2]);
    }

    bool query(int currentIndex, int left, int right, int value) {
        if(segTree[currentIndex] < value) return false;

        if(left == right) {
            segTree[currentIndex] = -1;
            return true;
        }

        int mid = (left+right)/2;
        bool placed = false;

        if(segTree[2*currentIndex + 1] >= value) {
            placed = query(2*currentIndex + 1, left, mid, value);
        } else {
            placed = query(2*currentIndex + 2, mid+1, right, value);
        }

        segTree[currentIndex] = max(segTree[2*currentIndex+1], segTree[2*currentIndex+2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree.resize(4*n, -1);
        build(0, 0, n-1, baskets);

        int ans = 0;
        for(int a: fruits) {
            if(query(0, 0, n-1, a) == false) {
                ans++;
            }
        }

        return ans;
    }
};