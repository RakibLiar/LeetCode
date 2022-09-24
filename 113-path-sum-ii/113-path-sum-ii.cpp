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
    TreeNode* calculate(vector<vector<int>> &res, vector<int> v, int sum, TreeNode *root, int target) {
        if(root == nullptr) return root;
        v.push_back(root->val);
        sum += root->val;
        TreeNode *left = calculate(res, v, sum, root->left, target);
        TreeNode *right = calculate(res, v, sum, root->right, target);
        if(left == nullptr && right == nullptr && sum == target && v.size() > 0) {
            res.push_back(v);
        }
        v.pop_back();
        return root;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        auto a = calculate(res, v, 0, root, targetSum);
        return res;
    }
};