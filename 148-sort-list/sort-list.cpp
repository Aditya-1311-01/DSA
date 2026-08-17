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
    ListNode* findmiddle(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        while(list1 && list2){
            if(list1->val<=list2->val){
                tail->next=list1;
                tail=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                tail=list2;
                list2=list2->next;
            }
        }
        if(list1) tail->next=list1;
        else tail->next=list2;

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode *middle=findmiddle(head);
        ListNode *right=middle->next;
        middle->next=NULL;
        ListNode *left=head;

        left=sortList(left);
        right=sortList(right);
        return mergeTwoLists(left,right);
        
        
        
    }
};