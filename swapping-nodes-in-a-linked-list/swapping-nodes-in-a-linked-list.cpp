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

        int size = 0;

        ListNode* temp = head;

        while(temp){
            size++;
            temp = temp->next;
        }
        return size;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {

        if(head == NULL)    return head;

        int size = getSize(head);

        if(k>size || size == 1)  return head;

        ListNode* temp = head, *node1 = NULL, *node2 = NULL;
        int count = 1, val1, val2;

        while(temp){
            if(count == k){
                node1 = temp;
                val1 = temp->val;
            }
            if(count == (size - k +1)){
                node2 = temp;
                val2 = temp->val;
            }
            temp = temp->next;
            count++;
        }
                node1->val = val2;
                node2->val = val1;
         return head;
        
    }
};