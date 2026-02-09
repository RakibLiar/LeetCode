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
    int dfs(TreeNode *root, int &res) {
        if(!root) return INT_MIN;
        int left = max(0, dfs(root->left, res));
        int right = max(0, dfs(root->right, res));
        int sum = max(left+right, max(left, right)) + root->val;
        res = max(res, sum);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int a = dfs(root, res);
        return res;
    }
};