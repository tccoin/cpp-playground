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
