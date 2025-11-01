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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        ListNode *res = new ListNode();
        ListNode *temp = res;
        while(head != nullptr) {
            cout<<head->val<<" "<<binary_search(nums.begin(), nums.end(), head->val)<<endl;
            if(!binary_search(nums.begin(), nums.end(), head->val)){
                temp->next = head;
                temp = temp->next;
            } else if(temp != nullptr) {
                temp->next = nullptr;
            }
            head = head->next;
        }
        return res->next;
    }
};