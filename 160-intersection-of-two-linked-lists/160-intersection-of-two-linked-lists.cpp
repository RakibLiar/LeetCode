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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0, countB = 0;
        ListNode *tempA = headA, *tempB = headB;
        while(tempA != NULL) {
            countA++;
            tempA = tempA->next;
        }
        while(tempB != NULL) {
            countB++;
            tempB = tempB->next;
        }
        tempA = headA, tempB = headB;
        if(countA > countB) {
            for(int i=1; i<=countA-countB; i++) {
                tempA = tempA->next;
            }
        } else {
            for(int i=1; i<=countB-countA; i++) {
                tempB = tempB->next;
            }
        }
        while(tempA != NULL && tempB != NULL) {
            if(tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};