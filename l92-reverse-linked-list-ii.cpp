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

// easy solution
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<int> toReverse;
    ListNode* current = head;
    ListNode* leftNode = nullptr;
    for (int i = 0; i < left - 1; i++) {
      current = current->next;
    }
    leftNode = current;
    for (int i = 0; i < right - left + 1; i++) {
      toReverse.push_back(current->val);
      current = current->next;
    }
    reverse(toReverse.begin(), toReverse.end());
    current = leftNode;
    for (int val : toReverse) {
      current->val = val;
      current = current->next;
    }
    return head;
  }
};

// high-end pro solution
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) return head;
    ListNode *start, *tail = head, *curr, *prev, *tmp;
    for (int i = 0; i < left - 1; i++) {
      start = tail;
      tail = tail->next;
    }
    prev = tail;
    curr = tail->next;
    for (int i = 0; i < right - left; i++) {
      tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
    tail->next = curr;
    if (left == 1) {
      return prev;
    } else {
      start->next = prev;
      return head;
    }
  }
};