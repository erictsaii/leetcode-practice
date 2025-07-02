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
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // find the middle 
        ListNode* slow = head, *fast = head, *prev;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        // reverse from the middle
        ListNode * curr = slow;
        prev = nullptr;

        while (curr) {
            ListNode *curr_nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_nxt;
        }

        // concate two list
        ListNode* l1 = head, *l2 = prev;
        curr = new ListNode();

        while (l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;

            curr->next = l2;
            l2 = l2->next;
            curr = curr->next; 
        }
        
    }
};
