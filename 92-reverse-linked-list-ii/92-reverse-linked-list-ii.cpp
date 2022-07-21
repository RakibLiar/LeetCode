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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode *beforeLeft, *afterRight, *prev = head, *temp = head, *leftNode, *rightNode;
        int pos = 1;
        while(temp != nullptr) {
            if(pos == left) {
                beforeLeft = prev;
                leftNode = temp;
            } else if(pos == right) {
                afterRight = temp->next;
                rightNode = temp;
            }
            prev = temp;
            temp = temp->next;
            ++pos;
        }
        //cout<<beforeLeft->val<<" "<<afterRight->val<<endl;
        prev = leftNode;
        temp = prev->next;
        while(temp != afterRight) {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        if(leftNode == head) {
            head = rightNode;
        } else {
            beforeLeft->next = rightNode;
        }
        leftNode->next = afterRight;
        return head;
    }
};