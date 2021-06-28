/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head;
        while(slowPtr && fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            // cout<<"slowPtr->val"<<" "<<fastPtr->val<<endl;
            if (slowPtr == fastPtr){
                slowPtr = head;
                while(slowPtr != fastPtr){
                    slowPtr = slowPtr->next;
                    fastPtr = fastPtr->next;
                }
                return slowPtr;
            }        
        }
        return NULL;
    }
};