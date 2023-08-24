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
    ListNode* findTail(ListNode* head){
        ListNode* temp = head;

        while(temp->next){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* loopStart(ListNode* head){
        ListNode* slow = head, *fast = head;

        while( fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;

            if(slow == fast)  {
                slow = head;

                while( slow != fast && fast && fast->next){
                    slow = slow -> next;
                    fast = fast->next;
                }
                return slow;
            }
            
        }


        return NULL;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;

        ListNode* tail = findTail(headA);

        tail->next = headA;

        ListNode* intersect = loopStart(headB);

        tail->next = NULL;

        
        return intersect;
    }
};