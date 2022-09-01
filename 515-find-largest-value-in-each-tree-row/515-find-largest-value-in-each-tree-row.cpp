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
    void getResult(TreeNode *root, int level, vector<int> &v) {
        if(root == NULL) return;
        if(level == v.size()) v.push_back(root->val);
        else v[level] = max(v[level], root->val);
        getResult(root->left, level+1, v);
        getResult(root->right, level+1, v);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        getResult(root, 0, v);
        return v;
        // if(root == NULL) return {};
        // queue<TreeNode*> q;
        // vector<int> v;
        // q.push(root);
        // while(!q.empty()) {
        //     int sz = q.size(), mx = INT_MIN;
        //     for(int i=0; i<sz; i++) {
        //         TreeNode *node = q.front();
        //         q.pop();
        //         mx = max(mx, node->val);
        //         if(node->left != NULL) q.push(node->left);
        //         if(node->right != NULL) q.push(node->right);
        //     }
        //     v.push_back(mx);
        // }
        // return v;
    }
};