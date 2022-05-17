/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    void setResult(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return;
        if(cloned->val == target->val) {
            ans = cloned;
            return;
        }
        setResult(original->left, cloned->left, target);
        setResult(original->right, cloned->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        setResult(original, cloned, target);
        return ans;
    }
};