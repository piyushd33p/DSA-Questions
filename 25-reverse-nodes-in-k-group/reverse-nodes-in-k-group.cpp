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
private:
    int getSize(ListNode* head){
        int count = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* helper(ListNode* head, int k, int size){
        if(size < k)    return head;
        if(!head)   return NULL;


        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;

        int count = 0;

        while(curr && count < k){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            count++;
        }

        if(fwd)     head->next = reverseKGroup(fwd, k);

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = getSize(head);

        return helper(head, k, size);
    }
};