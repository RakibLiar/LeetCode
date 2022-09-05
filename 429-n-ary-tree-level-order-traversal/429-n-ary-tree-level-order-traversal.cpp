/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorder(Node *root, vector<vector<int>> &res, int level) {
        if(root == NULL) return;
        if(res.size() == level)
            res.push_back({root->val});
        else
            res[level].push_back(root->val);
        for(auto a: root->children) {
            preorder(a, res, level+1);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        preorder(root, result, 0);
        return result;
    }
};