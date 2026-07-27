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

        if (!head || left == right)
            return head;

        ListNode *before = NULL;
        ListNode *temp = head;
        int count = 1;

        while (count < left) {
            before = temp;
            temp = temp->next;
            count++;
        }

        ListNode *curr = temp;
        ListNode *prev = NULL;

        int times = right - left + 1;

        while (times--) {
            ListNode *fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        temp->next = curr;

        if (before)
            before->next = prev;
        else
            head = prev;

        return head;
    }
};