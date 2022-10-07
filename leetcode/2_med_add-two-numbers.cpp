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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode *prev = NULL;
        bool carry = false;
        int temp;

        while (ptr1 && ptr2)
        {
            temp = ptr1->val + ptr2->val;
            temp += carry ? 1 : 0;
            if (temp / 10)
            { //value more than 10
                carry = true;
            }
            else
                carry = false;
            ptr1->val = temp % 10;
            prev = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (ptr2 && ptr1 == NULL)
        {
            prev->next = ptr2;
            ptr1 = prev->next;
        }
        while (ptr1 && carry)
        {
            temp = ptr1->val;
            temp += carry ? 1 : 0;
            if (temp / 10)
            { //value more than 10
                carry = true;
            }
            else
                carry = false;
            ptr1->val = temp % 10;
            prev = ptr1;
            ptr1 = ptr1->next;
        }
        if (carry)
            prev->next = new ListNode(1);
        return l1;
    }
};