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
    void result(TreeNode *root, string &s) {
        if(root->left != NULL) {
            s += ("(" + to_string(root->left->val));
            result(root->left, s);
            s += ")";
        } else if(root->right != NULL) {
            s += "()";
        }
        if(root->right != NULL) {
            s += ("(" + to_string(root->right->val));
            result(root->right, s);
            s += ")";
        }
    }
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string res = to_string(root->val);
        if(root->right != NULL) {
            res += ("(" + tree2str(root->left) + ")");
            res += ("(" + tree2str(root->right) + ")");
        } else if(root->left != NULL) {
            res += ("(" + tree2str(root->left) + ")");
        }
        return res;
    }
};