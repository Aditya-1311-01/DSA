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
    ListNode* reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr){
            ListNode *fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       if(head==NULL || head->next==NULL) return 1;

       ListNode *slow=head,*fast=head;
       while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
       }

       ListNode *newhead=reverse(slow->next);
       ListNode *first=head,*second=newhead;
       while(second){
        if(first->val!=second->val){
            reverse(newhead);
            return 0;
        }
        first=first->next;
        second=second->next;
       }
       reverse(newhead);
       return 1;
    }
};