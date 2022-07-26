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
    bool isFound = false;
    void rootToNode(TreeNode *root, TreeNode *t, vector<TreeNode*> &v) {
        if(root == NULL || isFound) return;
        v.push_back(root);
        if(root == t) {
            isFound = true;
            return;
        }
        if(!isFound) rootToNode(root->left, t, v);
        if(!isFound) rootToNode(root->right, t, v);
        if(!isFound) v.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        rootToNode(root, p, v1);
        isFound = false;
        rootToNode(root, q, v2);
        TreeNode *res;
        int a = min(v1.size(), v2.size());
        for(int i=0; i<a; i++) {
            if(v1[i] != v2[i]) break;
            res = v1[i];
        }
        return res;
    }
};