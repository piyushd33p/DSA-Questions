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
    ListNode* findMid(ListNode* head){
        ListNode* slow  = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode *prev  = NULL, *curr = head, *fwd = NULL;

        while(curr){
            fwd = curr->next;
            curr->next = prev;
            prev  = curr;
            curr = fwd;
        }

        return prev;
    }
public:
    int pairSum(ListNode* head) {
        if(head->next->next == NULL)    return head->val + head->next->val;

        ListNode* mid = findMid(head);

        ListNode* temp = reverse(mid);

        ListNode* firstPtr = head;
        ListNode* secondPtr = temp;

        int twinSum = INT_MIN;
        while(secondPtr){
            twinSum = max(twinSum, firstPtr->val + secondPtr->val);
            firstPtr = firstPtr->next;
            secondPtr = secondPtr->next;
        }
        return twinSum;

        
    }
};