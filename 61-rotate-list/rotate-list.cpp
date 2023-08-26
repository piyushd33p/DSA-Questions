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
        ListNode* temp = head;

        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* getTail(ListNode* head){
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        return tail;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next)    return head;
        // Get Size
        int size = getSize(head);

        
        // check k conditions
        if( k == size || k == 0)  return head;
        while( k >= size){
            if(k == size)   return head;
            k = k - size;
        }

        // GET TAil
        ListNode* tail = getTail(head);

        // calculations necessary
        ListNode* prev = NULL, *curr = head;
        int count = 0;

        while(count < size - k ){
            count++;
            prev = curr;
            curr = curr->next;
        }

        // Disconnect the rotatory part and add to head
        prev->next = NULL;
        tail->next = head;

        return curr;

    }
};


        // vector<int> data;

        // ListNode* curr = head;
        // while(curr){
        //     data.push_back(curr->val);
        //     curr = curr->next;
        // }

        // int n = data.size();
        // vector<int> temp(n);

        // for(int i = n-1; i>=0; i--){
        //     temp[(i + k)%n] = data[i];
        // }

        // curr = head;

        // for(auto it : temp){
        //     curr->val = it;
        //     curr = curr->next;
        // }

        // return head;