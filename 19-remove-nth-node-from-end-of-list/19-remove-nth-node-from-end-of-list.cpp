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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        auto temp = head, tail = head, prev = head;
        for(int i=1; i<=n; i++)
            tail = tail->next;
        if(!tail)
            return head->next;
        while(tail->next) {
            prev = temp;
            temp = temp->next;
            tail = tail->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};