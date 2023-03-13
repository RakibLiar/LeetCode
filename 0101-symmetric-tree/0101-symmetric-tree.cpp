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
    bool symmentric(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2 == nullptr;
        if(root2 == nullptr) return root1 == nullptr;
        if(root1->val != root2->val) return false;
        return symmentric(root1->left, root2->right) && symmentric(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return symmentric(root, root);
    }
};