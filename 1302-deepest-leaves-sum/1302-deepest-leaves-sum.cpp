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
    int getDepth(TreeNode *root) {
        if(!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    int deepestSum(TreeNode *root, int depth, int d) {
        if(!root) return 0;
        if(depth == d) return root->val;
        return deepestSum(root->right, depth, d+1) + deepestSum(root->left, depth, d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = getDepth(root);
        return deepestSum(root, depth, 1);
    }
};