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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *newll = new ListNode(0);
        ListNode *ans = newll;

        while (list1 != NULL || list2 != NULL)
        {

            while (list1 != NULL && list2 != NULL)
            {
                if (list1->val < list2->val)
                {
                    newll->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else
                {
                    newll->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                newll = newll->next;
            }
            if (list1 == NULL || list2 == NULL)
            {
                while (list1 != NULL)
                {
                    newll->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
                while (list2 != NULL)
                {
                    newll->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                newll = newll->next;
            }
        }
        return ans->next;
    }
};

// APPROACH 2

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{

    if (l1 == NULL)
        return l2;

    if (l2 == NULL)]
			return l1;

    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}