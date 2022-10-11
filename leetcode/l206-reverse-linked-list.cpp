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

// [1,2,3,4,5]
// [1,2]
// [1]
// []

// first try (iterative)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){ return head; }
        ListNode* last = head;
        ListNode* current = last->next;
        ListNode* next;
        head->next = nullptr;
        while(current){
            next = current->next;
            current->next = last;
            last = current;
            current = next;
        }
        return last;
    }
};

// second try (iterative)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = nullptr;
        ListNode* current = head;
        ListNode* next;
        while(current){
            next = current->next;
            current->next = last;
            last = current;
            current = next;
        }
        return last;
    }
};

// third try (recursive)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* end = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return end;
    }
};
