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
    int func(TreeNode *root) {
        if(root == nullptr) return 0;
        int l = func(root->left);
        int r = func(root->right);
        if(l == INT_MIN || r == INT_MIN) return INT_MIN;
        if(abs(l-r) > 1) return INT_MIN;
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        return func(root) != INT_MIN;
    }
};