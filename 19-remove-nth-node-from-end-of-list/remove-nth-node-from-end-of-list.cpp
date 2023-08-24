// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* backPtr = dummy;
        ListNode* frontPtr = dummy;

        for(int i = 1 ; i <= n; i++){
            frontPtr = frontPtr->next;
        }

        while(frontPtr -> next != NULL){
            frontPtr = frontPtr->next;
            backPtr = backPtr->next;
        }

        backPtr -> next = backPtr->next->next;

        return dummy->next;
    }
};
// class Solution {
//     public:
//      ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* start = new ListNode();
//         start->next = head;
//         ListNode* fast = start;
//         ListNode* slow = start;     

//         for(int i = 1; i <= n; ++i)
//             fast = fast->next;
    
//         while(fast->next != NULL)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }
        
//         slow->next = slow->next->next;
        
//         return start->next;
//     }
// };