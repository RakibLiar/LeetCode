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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0), *temp = head;
        ListNode *res = dummy;
        while(temp != nullptr) {
            if(temp->val < x) {
                dummy->next = new ListNode(temp->val);
                dummy = dummy->next;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr) {
            if(temp->val >= x) {
                dummy->next = new ListNode(temp->val);
                dummy = dummy->next;
            }
            temp = temp->next;
        }
        return res->next;
    }
};