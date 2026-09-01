// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL) {
            temp=temp->next;
            size++;
        }
        if(size<=3) return {-1,-1};
        vector<int> vec;
        ListNode* prev=head;
        temp=head->next;
        int pos=2;
        while(temp!=NULL && temp->next!=NULL){
            int one=prev->val;
            int two=temp->next->val;
            int curr=temp->val;
            if(curr>one && curr>two) vec.push_back(pos);
            else if(curr<one && curr<two) vec.push_back(pos);
            pos++;
            prev=prev->next;
            temp=temp->next;
        }
        if(vec.size()<2) return {-1,-1};
        int mx=vec.back()-vec.front();
        int mn=INT_MAX;
        for(int i=0;i<vec.size()-1;i++){
            mn=min(mn,vec[i+1]-vec[i]);
        }
        return {mn,mx};
    }
};