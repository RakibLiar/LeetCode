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
    void travarse(TreeNode *&ans, TreeNode *root) {
        if(!root) return;
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        travarse(ans, root->left);
        travarse(ans, root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *ans = new TreeNode(), *temp;
        temp = ans;
        travarse(ans, root);
        *root = *temp->right;
    }
};