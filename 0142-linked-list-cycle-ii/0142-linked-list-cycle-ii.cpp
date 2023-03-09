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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        auto slow = head;
        auto fast = head;
        ListNode* temp;
        int pos = 0;
        do {
            if(fast == NULL || fast->next == NULL) {
                temp = NULL;
                break;
            }
            pos++;
            fast = (fast->next)->next;
            slow = slow->next;
            if(fast == slow) {
                temp = slow;
                break;
            }
        } while(true);
        if(temp == NULL) return NULL;
        while(temp != head) {
            head = head->next;
            temp = temp->next;
        }
        return temp;
    }
};