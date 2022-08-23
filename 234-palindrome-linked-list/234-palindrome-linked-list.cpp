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
    bool isValid(ListNode *tail, ListNode *&head) {
        if(tail == NULL || head == NULL) return true;
        bool equal = isValid(tail->next, head) && (tail->val == head->val);
        head = head->next;
        return equal;
    }
    
    bool isPalindrome(ListNode* head) {
        return isValid(head, head);
    }
};