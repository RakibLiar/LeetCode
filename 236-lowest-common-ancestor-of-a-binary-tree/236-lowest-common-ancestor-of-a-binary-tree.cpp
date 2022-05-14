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
    vector<TreeNode*> st1, st2, s;
    void traverse(TreeNode* root, TreeNode *target1, TreeNode *target2) {
        if(!root) return;
        s.push_back(root);
        if(root == target1) {
            st1 = s;
        }
        if(root == target2) {
            st2 = s;
        }
        traverse(root->left, target1, target2);
        traverse(root->right, target1, target2);
        s.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        TreeNode *result;
        cout<<st1.size()<<" "<<st2.size();
        for(int i=0; i<min(st1.size(), st2.size()); i++) {
            if(st1[i] != st2[i])
                break;
            result = st1[i];
        }
        return result;
    }
};