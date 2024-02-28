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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *res;
        while(!q.empty()) {
            int sz = q.size();
            res = q.front();
            while(sz--) {
                TreeNode *parent = q.front();
                q.pop();
                if(parent->left != nullptr) q.push(parent->left);
                if(parent->right != nullptr) q.push(parent->right);
            }
        }
        return res->val;
    }
};