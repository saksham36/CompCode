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
        ListNode *curr = headA, *currA = headA, *currB = headB;
        int c1 = 0, c2 = 0;
        while(curr != NULL){
            c1++;
            curr = curr->next;
        }
        curr = headB;
        while(curr != NULL){
            c2++;
            curr = curr->next;
        }
        int d = abs(c1-c2);
        if(c1>c2)
            for(int i=0; i<d;i++)
                currA = currA->next;
        else
            for(int i=0;i<d;i++)
                currB = currB->next;
        while(currA && currB){
            if(currA == currB)
                return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};