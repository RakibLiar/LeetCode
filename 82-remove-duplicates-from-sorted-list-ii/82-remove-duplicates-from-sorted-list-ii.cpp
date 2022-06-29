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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        auto answer = new ListNode();
        auto temp = answer, prev = head;
        if(head->val != head->next->val) {
            temp->next = new ListNode(head->val);
            temp = temp->next;
        }
        head = head->next;
        while(head) {
            if((prev->val == head->val) ||(head->next && head->val == head->next->val)) {
                prev = head;
            } else {
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            head = head->next;
        }
        return answer->next;
    }
};