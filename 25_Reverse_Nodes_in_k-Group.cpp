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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        ListNode* prev = dummy;

        while (1) {
            ListNode* next_prev = curr;

            // traverse to the end node of this iteration
            ListNode* end = curr;
            int step = k-1;
            while (step && end) {
                end = end->next;
                step--;
            }
            if (!end) break; 

            // reverse
            ListNode* p1 = curr, *p2 = curr->next; 
            curr->next = end->next;
            while (1) {
                ListNode* p2_next = p2->next; 
                p2->next = p1; 

                if (p2 == end) break;
                p1 = p2;
                p2 = p2_next;
            }

            // update 
            prev->next = end;
            prev = next_prev;
            curr = prev->next; 
        }
        return dummy->next;
    }
};
