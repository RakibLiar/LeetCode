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
    ListNode* removeNodes(ListNode* head) {
        deque<ListNode*> dq;
        while(head) {
            while(!dq.empty() && head->val > dq.back()->val) {
                dq.pop_back();
            }
            dq.push_back(head);
            head = head->next;
        }
        ListNode *res = new ListNode();
        ListNode *temp = res;
        while(!dq.empty()) {
            temp->next = dq.front();
            temp = temp->next;
            dq.pop_front();
        }
        temp->next = nullptr;
        return res->next;
    }
};