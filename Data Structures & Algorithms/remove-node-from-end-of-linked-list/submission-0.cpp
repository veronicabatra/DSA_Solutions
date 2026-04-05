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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        int i=size-n+1;
        int idx=1;
        curr=head;
        if(idx==i) {
            head=head->next;
            delete curr;
            return head;
        }
        ListNode* prev=NULL;
        while(curr!=NULL && idx<=size){
            if(idx==i) {
                prev->next=curr->next;
                delete curr;
                return head;
            }
            idx++;
            prev=curr;
            curr=curr->next; 
        }
        return head;
    }
};
