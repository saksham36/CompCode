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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * l1_ptr = l1;
        ListNode * l2_ptr = l2;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* head = NULL;
        if(l1_ptr->val <= l2_ptr->val){
            head = l1_ptr;
            l1_ptr = l1_ptr->next;
        }
        else{
            head = l2_ptr;
            l2_ptr = l2_ptr->next;
        }
        ListNode * curr = head; 
        while(l1_ptr != NULL && l2_ptr !=NULL){
            if(l1_ptr->val < l2_ptr->val){
                curr->next = l1_ptr;
                l1_ptr = l1_ptr->next;
            }
            else{
                curr->next = l2_ptr;
                l2_ptr = l2_ptr->next;
            }
            curr = curr->next;
        }
        while(l1_ptr != NULL){
            curr->next = l1_ptr;
            l1_ptr = l1_ptr->next;
            curr = curr->next;
        }
        while(l2_ptr != NULL){
            curr->next = l2_ptr;
            l2_ptr = l2_ptr->next;
            curr = curr->next;
        }
        return head;
        
    }
};