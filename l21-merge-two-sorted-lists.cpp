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

// iterative solution
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head1 = list1;
    ListNode *head2 = list2;
    ListNode *result = nullptr;
    ListNode *current = nullptr;
    ListNode *last = nullptr;
    bool done = false;
    while (!done && (head1 || head2)) {
      if (head1 && head2) {
        if (head1->val <= head2->val) {
          current = head1;
          head1 = head1->next;
        } else {
          current = head2;
          head2 = head2->next;
        }
      } else {
        current = head1 ? head1 : head2;
        done = true;
      }
      if (!result) {
        result = current;
      } else {
        last->next = current;
      }
      last = current;
    }
    return result;
  }
};

// recursive solution
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1) {
      return list2;
    } else if (!list2) {
      return list1;
    }
    bool list1_smaller = list1->val <= list2->val;
    ListNode *small = list1_smaller ? list1 : list2;
    ListNode *large = list1_smaller ? list2 : list1;
    small->next = mergeTwoLists(small->next, large);
    return small;
  }
};