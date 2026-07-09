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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) return head;

        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* prev_part=dummy;

        for(int i=1;i<left;i++){
            prev_part=prev_part->next;
        }

        ListNode* curr= prev_part->next;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;

        for(int i=0;i<right-left+1;i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        prev_part->next->next=curr;
        prev_part->next=prev;

        return dummy->next;
        
    }
};