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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        int count = 0;
        while(curr != NULL && count < k){
            curr = curr -> next;
            count ++;
        }
        if(count < k)
            return head;
        count = 0;
        curr = head;
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count ++;
        }
        if(next != NULL){
            ListNode *rec_head = reverseKGroup(next, k);
            head -> next = rec_head;
        }
        return prev;
            
        
    }
};