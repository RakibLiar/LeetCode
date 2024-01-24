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
    int pseudoPalindromicPaths(TreeNode *root, int n = 0) {
        if(root == nullptr) return 0;
        n ^= (1 << root->val);
        if(root->left == nullptr && root->right == nullptr) {
            int a = __builtin_popcount(n);
            n ^= (1 << root->val);
            return a <= 1;
        }
        int res = pseudoPalindromicPaths(root->left, n) + pseudoPalindromicPaths(root->right, n);
        n ^= (1 << root->val);
        return res;
    }
};