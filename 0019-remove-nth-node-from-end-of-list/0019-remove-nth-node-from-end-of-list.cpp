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
        ListNode *cur = head, *prev = nullptr, *next = head;
        for(int i=1; i<n; i++) {
            next = next->next;
        }
        while(next->next != nullptr) {
            next = next->next;
            prev = cur;
            cur = cur->next;
        }
        if(prev == nullptr) return head->next;
        prev->next = cur->next;
        return head;
    }
};