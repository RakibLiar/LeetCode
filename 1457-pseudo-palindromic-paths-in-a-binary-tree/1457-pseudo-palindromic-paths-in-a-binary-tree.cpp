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
    int count(vector<int> &v) {
        int c = 0;
        for(int a: v) {
            c += (a%2);
            //cout<<a<<" ";
        }
        //cout<<endl;
        return c <= 1;
    }
    int calculate(TreeNode *root, vector<int> &v) {
        if(root == nullptr) return 0;
        v[root->val]++;
        if(root->left == nullptr && root->right == nullptr) {
            //cout<<root->val<<endl;
            int a = count(v);
            v[root->val]--;
            return a;
        }
        int res = calculate(root->left, v) + calculate(root->right, v);
        v[root->val]--;
        return res;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10, 0);
        return calculate(root, v);
    }
};