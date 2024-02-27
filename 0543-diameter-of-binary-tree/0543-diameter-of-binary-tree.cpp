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
    int R = INT_MIN;
    int calculate(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = calculate(root->left);
        int right = calculate(root->right);
        int res = max(left, right) + 1;
        R = max(R, left+right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a = calculate(root);
        return R;
    }
};