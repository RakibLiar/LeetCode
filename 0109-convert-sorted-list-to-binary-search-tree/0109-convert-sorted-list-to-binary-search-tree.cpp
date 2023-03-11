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
    TreeNode* resultBST(vector<int> &v, int low, int high) {
        if(low > high) return nullptr;
        if(low == high) {
            return new TreeNode(v[low]);
        }
        int mid = (low+high)/2;
        TreeNode *node = new TreeNode(v[mid]);
        node->left = resultBST(v, low, mid-1);
        node->right = resultBST(v, mid+1, high);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == nullptr) return new TreeNode(head->val);
        vector<int> v;
        while(head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        return resultBST(v, 0, v.size()-1);
    }
};