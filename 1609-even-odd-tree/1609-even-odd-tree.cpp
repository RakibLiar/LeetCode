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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()) {
            int prev;
            if(level % 2 == 1) prev = INT_MIN;
            else prev = INT_MAX;
            int size = q.size();
            while(size--) {
                TreeNode *par = q.front();
                q.pop();
                if((level % 2 == 1 && par->val <= prev) || 
                   (level % 2 == 0 && par->val >= prev) || ((level % 2) != (par->val % 2))) return false;
                prev = par->val;
                if(par->left != nullptr) q.push(par->left);
                if(par->right != nullptr) q.push(par->right);
            }
            level++;
        }
        return true;
    }
};