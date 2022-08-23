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
    bool equal = true;
    ListNode *hurr;
    void isValid(ListNode *&tail) {
        if(tail == NULL || hurr == NULL) return;
        isValid(tail->next);
        equal = equal && (tail->val == hurr->val);
        hurr = hurr->next;
    }
    
    bool isPalindrome(ListNode* head) {
        hurr = head;
        isValid(head);
        return equal;
    }
};