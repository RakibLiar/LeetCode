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
    void deepestSum(TreeNode *root, int depth, int &sum, int d) {
        if(!root) return;
        deepestSum(root->left, depth, sum, d+1);
        if(depth == d)
            sum += root->val;
        deepestSum(root->right, depth, sum, d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth = getDepth(root);
        int sum = 0;
        deepestSum(root, depth, sum, 1);
        return sum;
    }
};