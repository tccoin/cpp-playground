/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// first try (input is modified)
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

// second try (if loop exists, distance between two heads will decreace by 1 after each step so finally meet)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * head_fast = head;
        ListNode * head_slow = head;
        while(head_fast && head_fast->next){
            head_fast = head_fast->next->next;
            head_slow = head_slow->next;
            if(head_fast==head_slow) return true;
        }
        return false;
    }
};
