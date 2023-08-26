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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> data;

        ListNode* curr = head;
        while(curr){
            data.push_back(curr->val);
            curr = curr->next;
        }

        int n = data.size();
        vector<int> temp(n);

        for(int i = n-1; i>=0; i--){
            temp[(i + k)%n] = data[i];
        }

        curr = head;

        for(auto it : temp){
            curr->val = it;
            curr = curr->next;
        }

        return head;
        
    }
};