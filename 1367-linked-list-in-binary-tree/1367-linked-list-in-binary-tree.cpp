/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool result(ListNode* head, TreeNode *root) {
        if(!head) return true;
        if(!root) return false;
        if(root->val != head->val) return false;
        return result(head->next, root->left) | result(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        bool answer = false;
        if(root->val == head->val)
            answer = result(head, root);
        if(answer) return true;
        bool res = isSubPath(head, root->left);
        res |= isSubPath(head, root->right);
        return res;
    }
};