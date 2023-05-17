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
    int pairSum(ListNode* head) {

        if(head->next->next == NULL)    return head->val + head->next->val;

        ListNode* curr = head;
        vector<int> helper;

        int count  = 0;

        while(curr){
            helper.push_back(curr->val);
            curr = curr->next;
            count++;
        }
        int twinSum = INT_MIN;

        for(int i = 0; i<= count/2; i++){
            twinSum = max(twinSum, helper[i]+helper[count-i-1]);
        }
        return twinSum;
        
    }
};