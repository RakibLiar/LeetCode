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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *hair = head, *tortoise = head->next;
        while(tortoise != nullptr && tortoise->next != nullptr) {
            if(hair == tortoise) return true;
            hair = hair->next;
            tortoise = tortoise->next->next;
        }
        return false;
    }
};