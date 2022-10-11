/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// first submission, O(N)-O(1), 4ms-7.7MB
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        while (true)
        {
            node->val = node->next->val;
            if (node->next->next == nullptr)
            {
                node->next = nullptr;
                break;
            }
            node = node->next;
        }
    }
};