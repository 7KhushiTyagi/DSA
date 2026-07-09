
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;

        while(temp){
            size++;
            temp=temp->next;
        }
        if(k>size) return head;
        
        ListNode* curr=head;
        ListNode* prev=nullptr;
        int count=0;
        while(curr && count<k){
             ListNode* next=curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
             count++;
        }
        
        head->next=reverseKGroup(curr,k);

        return prev;
        
    }
};