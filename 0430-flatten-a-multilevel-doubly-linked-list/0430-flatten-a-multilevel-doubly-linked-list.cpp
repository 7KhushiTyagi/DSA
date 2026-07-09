/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;

        Node* curr=head;
        stack<Node*> st;
        while(curr){
           
           if(curr->child){
            if(curr->next){
                st.push(curr->next);
            }
            curr->next=curr->child;
            curr->next->prev=curr;
            curr->child=nullptr;
           }
           if(!curr->next && !st.empty()){
              Node* node=st.top();
              st.pop();

              curr->next=node;
              node->prev=curr;
           }

           curr=curr->next;
        }
        return head;
    }
};