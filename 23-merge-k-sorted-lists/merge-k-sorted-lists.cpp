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
    ListNode* merge(ListNode *list1,ListNode *list2){
        ListNode* dummy=new ListNode(-1);
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

        ListNode *ans=dummy->next;
        delete dummy;
        return ans;
    }
    void mergesort(vector<ListNode*>& lists,int start,int end){
        if(start>=end) return;
        int mid=start+(end-start)/2;
        mergesort(lists,start,mid);
        mergesort(lists,mid+1,end);
        lists[start]=merge(lists[start],lists[mid+1]);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        mergesort(lists,0,k-1);
        return lists[0];
        
    }
};