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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head, *left = head, *right= head;
        int count = 1;

        while(temp){
            if(count< k)    left = left->next;
            if(count > k)   right = right->next;

            count++;
            temp = temp->next;
        }

        swap(left->val, right->val);
        return head;
    }
};