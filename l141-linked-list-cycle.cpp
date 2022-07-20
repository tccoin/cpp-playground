/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// first try
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int count = 0;
        ListNode* visited = new ListNode(0);
        ListNode* current = head;
        ListNode* next;
        while(current){
            next = current->next;
            if(current->next==visited) return true;
            current->next = visited;
            current = next;
        }
        return false;
    }
};
