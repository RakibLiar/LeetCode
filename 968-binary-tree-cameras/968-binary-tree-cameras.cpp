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
    int cnt = 0;
    int calculate(TreeNode *root) {
        if(!root) return 1;
        int left = calculate(root->left);
        int right = calculate(root->right);
        
        if(left == 0 || right == 0) {
            cnt++;
            return 2;
        }
        
        if(left == 1 && right == 1) return 0;
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        int a = calculate(root);
        if(a == 0) cnt++;
        return cnt;
    }
};