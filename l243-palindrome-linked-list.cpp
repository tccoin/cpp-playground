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

// first attempt, O(N)+O(N), 515ms+156.4 MB
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        int listSize = 0;
        ListNode *current = head;
        ListNode *reverseList = new ListNode(current->val, nullptr);
        // construct reverseList and count size
        while (current != nullptr)
        {
            if (current->next != nullptr)
            {
                reverseList = new ListNode(current->next->val, reverseList);
            }
            listSize += 1;
            current = current->next;
        }
        // check if palindrome
        ListNode *left = head;
        ListNode *right = reverseList;
        bool flag = true;
        for (int i = 0; i < listSize / 2; i++)
        {
            if (left->val == right->val)
            {
                left = left->next;
                right = right->next;
            }
            else
            {
                flag = false;
            }
        }
        // delete reverseList
        ListNode *tmp = reverseList;
        for (int i = 0; i < listSize; i++)
        {
            tmp = reverseList->next;
            delete reverseList;
            reverseList = tmp;
        }
        return flag;
    }
};

// second attempt, change original list, O(N)+O(1), 226ms+110MB
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        int listSize = 0;
        ListNode *left = head;
        ListNode *right = head;
        // count size
        while (right != nullptr)
        {
            listSize += 1;
            right = right->next;
        }
        // reverse left-half list
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;
        for (int i = 0; i < listSize / 2; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        left = prev;
        right = listSize % 2 == 0 ? curr : curr->next;
        // check if palindrome
        bool flag = true;
        for (int i = 0; i < listSize / 2; i++)
        {
            if (left->val == right->val)
            {
                left = left->next;
                right = right->next;
            }
            else
            {
                flag = false;
            }
        }
        return flag;
    }
};