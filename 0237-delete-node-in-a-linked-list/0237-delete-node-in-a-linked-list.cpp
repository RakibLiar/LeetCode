/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *head;
        while(node->next) {
            node->val = node->next->val;
            head = node;
            node = node->next;
        }
        head->next = nullptr;
    }
};