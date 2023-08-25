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
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(!head)    return 0;
        if(!head->next) return 1;

        stack<ListNode*> st;
        int size = getSize(head);
        int count = 0;
        ListNode* mid = head;

        while(mid && count < size/2){
            count++;
            st.push(mid);
            mid = mid->next;
        }

        if(size & 1)    mid = mid->next;

        while(mid){
            if(st.top()->val != mid->val)   return 0;
            st.pop();
            mid = mid->next;
        }
        return 1;
    }
};