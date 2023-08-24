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
    int getSize(ListNode* head){
        if(head == NULL)    return 0;
        int count = 0;
        ListNode* curr = head;

        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)    return head;
        int size = getSize(head);
        if(n > size)    return head;
        if(size ==1 && n == 1)  return NULL;
        if(size == n)   return head->next;
        ListNode* curr = head;
        ListNode* prev = NULL;

        int count = 0;

        while(count < size-n && curr){
            count++;
            prev = curr;
            curr = curr->next;
        }
        if(!curr->next)  prev->next = NULL;
        else{  
            prev->next = curr -> next;
            curr->next = NULL;
        }
        return head;

    }
};