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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            res.push_back(vector<int>());
            int index = res.size() - 1;
            for(int i=0; i<sz; i++) {
                TreeNode *t = q.front();
                q.pop();
                if(t != nullptr) {
                    res[index].push_back(t->val);
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        res.pop_back();
        return res;
    }
};