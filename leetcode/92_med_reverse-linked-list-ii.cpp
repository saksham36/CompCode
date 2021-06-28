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
        ListNode* curr = head;
        int idx = 1;
        ListNode*prev = NULL;
        ListNode*next;
        ListNode*rev_begin = NULL;
        ListNode*rev_end = NULL;
        ListNode* rev_start = NULL;
        ListNode*rev_term = NULL;
        while(curr !=NULL){
            if(idx == left-1){
                rev_begin = curr;
                // cout<<"Rev_begin: "<<rev_begin->val<<endl;
            }
            else if(idx == left){
                rev_start = curr;
                // cout<<"Rev_start: "<< rev_start->val<<endl;
            }
                
            if(idx == right){
                rev_term = curr;
                // cout<<"Rev_term: "<<rev_term->val<<endl;
            }
            else if(idx == right+1){
                rev_end = curr;
                // cout<<"Rev_end: "<<rev_end->val<<endl;
            }
            curr = curr ->next;
            idx++;
        }
        curr = head;
        idx = 1;
        while(curr != NULL){
            if(idx == left-1){
                // cout<<"Left-1: "<<idx<<endl;
                next = curr->next;
                curr->next = rev_term;
                prev = curr;
                curr = next;
            }
            else if(idx == left){
                // cout<<"Left: "<<idx<<endl;
                next = curr->next;
                curr->next = rev_end;
                prev = curr;
                curr = next;
            }
            else if(idx> left && idx <= right){
                // cout<<"In b/w: "<<idx<<endl;
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            else{
                // cout<<"Else: "<<idx<<endl;
                prev = curr;
                curr = curr->next;    
            }
            idx ++;
        }
    if(left == 1 && right != 1)
        return rev_term;
    return head;   
    }
};