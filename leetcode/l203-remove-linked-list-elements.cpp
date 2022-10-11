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

// first attempt, O(N)-O(1), 23ms-14.9MB
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        bool headFound = false;
        while (current != nullptr)
        {
            if (current->val != val && !headFound)
            {
                // update head
                headFound = true;
                head = current;
            }
            if (current->val == val && headFound)
            {
                // skip current node
                prev->next = current->next;
                current = current->next;
                continue;
            }
            prev = current;
            current = current->next;
        }
        return headFound ? head : nullptr;
    }
};