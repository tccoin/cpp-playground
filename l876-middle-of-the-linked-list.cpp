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

// first submission 我起了 一刀秒了 有什么好说的
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (true)
        {
            if (fast->next)
            {
                if (fast->next->next)
                {
                    fast = fast->next->next;
                }
                else
                {
                    fast = fast->next;
                }
                slow = slow->next;
            }
            else
            {
                break;
            }
        }
        return slow;
    }
};