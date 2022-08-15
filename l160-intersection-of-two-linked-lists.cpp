/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// stupid naive solution
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode *> listA;
    ListNode *current = headA;
    while (current) {
      listA.insert(current);
      current = current->next;
    }
    current = headB;
    while (current) {
      if (listA.count(current)) return current;
      current = current->next;
    }
    return NULL;
  }
};

// superb solution
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *current1 = headA;
    ListNode *current2 = headB;
    while (current1 != current2) {
      current1 = current1 ? current1->next : headB;
      current2 = current2 ? current2->next : headA;
    }
    return current1;
  }
};