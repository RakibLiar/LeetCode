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
    unordered_map<int, int> inorderMap;
    bool isLeftChild(int par, int child) {
        auto parNode = inorderMap.find(par);
        auto childNode = inorderMap.find(child);
        return parNode->second > childNode->second;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=0; i<inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        for(int i=1; i<preorder.size(); i++) {
            TreeNode* node = root;
            while(true) {
                if(isLeftChild(node->val, preorder[i]) == true) {
                    if(node->left == NULL) {
                        node->left = new TreeNode(preorder[i]);
                        break;
                    }
                    node = node->left;
                } else {
                    if(node->right == NULL) {
                        node->right = new TreeNode(preorder[i]);
                        break;
                    }
                    node = node->right;
                }
            }
        }
        return root;
    }
};