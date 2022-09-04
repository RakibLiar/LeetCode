/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorderTraverse(TreeNode* root, vector<vector<int>> &v, int row, int col) {
        if(root == NULL) return;
        v.push_back({col, row, root->val});
        preorderTraverse(root->left, v, row+1, col-1);
        preorderTraverse(root->right, v, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> store, result;
        preorderTraverse(root, store, 0, 0);
        sort(store.begin(), store.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] != b[0]) return a[0]<b[0];
            if(a[1] != b[1]) return a[1]<b[1];
            return a[2] < b[2];
        });
        vector<int> v;
        v.push_back(store[0][2]);
        for(int i=1; i<store.size(); i++) {
            if(store[i][0] == store[i-1][0]) {
                v.push_back(store[i][2]);
            }
            else {
                result.push_back(v);
                v = vector<int>();
                v.push_back(store[i][2]);
            }
        }
        if(v.size() > 0)
            result.push_back(v);
        return result;
    }
};