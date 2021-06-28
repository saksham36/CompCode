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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>h;
        ListNode * currA = headA;
        while(currA != NULL){
            h.insert(currA);
            currA = currA->next;
        }
        ListNode *currB = headB;
        while(currB != NULL){
            if(h.find(currB) != h.end())
                return currB;
            currB = currB->next;
        }
        return NULL;
    }
};