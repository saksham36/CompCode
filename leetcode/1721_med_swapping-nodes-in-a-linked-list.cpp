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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*fast = head;
        ListNode*slow = head;
        ListNode*first;
        while(--k)
            fast = fast->next;
        first = fast;
        fast = fast->next;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        swap(slow->val, first->val);
        
        return head;
    }
};