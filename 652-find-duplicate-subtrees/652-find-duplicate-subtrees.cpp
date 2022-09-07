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
    vector<TreeNode*> result;
    unordered_map<string, int> mp;
    string dfs(TreeNode *root) {
        if(root == NULL) return "";
        string s = to_string(root->val);
        s += ("_" + dfs(root->left));
        s += ("_" + dfs(root->right));
        if(mp[s] == 1) result.push_back(root);
        mp[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string a = dfs(root);
        return result;
    }
};