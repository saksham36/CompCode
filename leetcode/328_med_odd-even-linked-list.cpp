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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* odd_curr = head, *next = NULL, *even_head = head->next, *even_curr = even_head;
        if(even_head->next == NULL) // only 2 nodes
            return head;
        while(odd_curr->next != NULL && even_curr->next!= NULL){
            next = odd_curr->next;
            odd_curr->next = even_curr->next;
            even_curr->next = odd_curr->next->next;
            odd_curr = odd_curr->next;
            even_curr = even_curr->next;
        }
        odd_curr->next = even_head;
        return head;
    }
};