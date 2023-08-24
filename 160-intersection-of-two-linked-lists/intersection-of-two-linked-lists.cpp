/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLen(ListNode* head){
        int size = 0;

        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        return size;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;

        int lenA = getLen(headA);
        int lenB = getLen(headB);

        if(lenA > lenB){
            while(lenA > lenB){
                headA = headA->next;
                lenA--;
            }
        }
        else if(lenB > lenA){
            while(lenB  > lenA){
                headB = headB->next;
                lenB--;
            }
        }

        ListNode* tempA = headA, *tempB = headB;

        while(tempA && tempB){
            if(tempA == tempB)  return tempA;

            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};