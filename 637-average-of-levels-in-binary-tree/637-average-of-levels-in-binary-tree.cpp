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
    void dfs(TreeNode *root, int level, vector<long long> &sums, vector<long long> &cnt) {
        if(root == nullptr) return;
        if(level == sums.size()) {
            sums.push_back(root->val);
            cnt.push_back(1);
        } else {
            sums[level] += root->val;
            cnt[level]++;
        }
        dfs(root->left, level+1, sums, cnt);
        dfs(root->right, level+1, sums, cnt);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<long long> sums, cnt;
        dfs(root, 0, sums, cnt);
        for(int i=0; i<sums.size(); i++) {
            res.push_back((double) sums[i]/cnt[i]);
        }
        return res;
    }
};