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
    void getResult(TreeNode *root, int mx, int &cnt) {
        if(root == NULL) return;
        cnt += (root->val >= mx);
        getResult(root->left, max(root->val, mx), cnt);
        getResult(root->right, max(root->val, mx), cnt);
    }
    
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        getResult(root,INT_MIN,cnt);
        return cnt;
    }
};