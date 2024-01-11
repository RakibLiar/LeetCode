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
    int maxAncestorDiff(TreeNode* root, int mx = INT_MIN, int mn = INT_MAX) {
        if(root == nullptr) return mx - mn;
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        return max(maxAncestorDiff(root->left, mx, mn), maxAncestorDiff(root->right, mx, mn));
    }
};