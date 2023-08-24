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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!l1)   return l2;
      if(!l2)   return l1;

      ListNode* temp1  = l1;
      ListNode* temp2  = l2;

      int sum = 0, carry = 0;

      ListNode* dummy = new ListNode();
      ListNode* ans = dummy;
      while(temp1 && temp2){
        sum = temp1->val + temp2->val + carry;
        int currSum = sum%10;
        carry = sum/10;

        ListNode* d = new ListNode(currSum);
        ans->next = d;
        ans = ans->next;

        temp1 = temp1->next;
        temp2 = temp2->next;

      }

      while(temp1){
        sum = temp1->val + carry;
        int currSum = sum%10;
        carry = sum/10;

        ListNode* d = new ListNode(currSum);
        ans->next = d;
        ans = ans->next;
        temp1 = temp1->next;
      }
      while(temp2){
        sum = temp2->val + carry;
        int currSum = sum%10;
        carry = sum/10;

        ListNode* d = new ListNode(currSum);
        ans->next = d;
        ans = ans->next;
        temp2 = temp2->next;
      }

      if(carry != 0 ){
        ListNode* d = new ListNode(carry);
        ans->next = d;
        ans = ans->next;
      }

      return dummy->next;

    }
};