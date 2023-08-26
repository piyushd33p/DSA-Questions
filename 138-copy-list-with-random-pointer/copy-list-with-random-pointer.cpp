/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;

        unordered_map<Node*, Node*> mp;
        Node* temp = head;

        while(temp){
            Node* dCopy = new Node(temp->val);
            mp[temp] = dCopy;
            temp = temp->next;
        }

        temp = head;

        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        temp = head;
        return mp[temp];

    }
};