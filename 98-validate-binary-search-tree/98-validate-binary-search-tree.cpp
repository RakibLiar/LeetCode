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
    bool isValidBST(TreeNode* root, long long mn = -1000000000000, long long mx = 1000000000000) {
        if(root == NULL)
            return true;
        long long x = (long long) root->val;
        if(x <= mn || x >= mx) return false;
        return isValidBST(root->left, mn, x) & isValidBST(root->right, x, mx);
    }
};