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

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(!head){ return head; }
//         ListNode* last = head;
//         ListNode* current = last->next;
//         ListNode* next;
//         head->next = nullptr;
//         while(current){
//             next = current->next;
//             current->next = last;
//             last = current;
//             current = next;
//         }
//         return last;
//     }
// };

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
