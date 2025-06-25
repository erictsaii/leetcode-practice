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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode();
        ListNode* p1 = head, *p2 = head->next, *prev = dummy;

        while (p1 && p2) {
            ListNode* p2_next = p2->next;
            p2->next = p1;
            p1->next = p2_next;
            prev->next = p2;

            prev = p1;
            p1 = p2_next;

            if (p1) {
                p2 = p2_next->next; 
            }
        }

        return dummy->next;
    }
};
