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
    int sumNumbers(TreeNode* root, int ans=0) {
        if(root->left == NULL && root->right == NULL) {
            return ans*10 + root->val;
        }
        int sum1 = 0, sum2 = 0;
        if(root->left != NULL) sum1 = sumNumbers(root->left, ans*10 + root->val);
        if(root->right != NULL) sum2 = sumNumbers(root->right, ans*10 + root->val);
        return sum1+sum2;
    }
};