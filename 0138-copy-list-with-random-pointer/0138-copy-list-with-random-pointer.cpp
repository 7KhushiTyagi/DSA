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
        Node* temp=head;

        while(temp){
            Node* clone= new Node(temp->val);
            clone->next=temp->next;
            temp->next=clone;
            temp=temp->next->next;
        }

        temp=head;
        while(temp){
            Node* clone=temp->next;
            if(temp->random){
                clone->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        Node* dummy= new Node(0);
        Node* curr= dummy;
        temp=head;

        while(temp){
            Node* clone=temp->next;
            curr->next= clone;

            curr=curr->next;
            temp->next=clone->next;
            temp=temp->next;
        }
        return dummy->next;

        
    }
};