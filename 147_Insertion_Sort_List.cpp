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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* head_nxt = head->next;
        head->next = nullptr;
        head = head_nxt;

        while (head) {
            head_nxt = head->next;
            int now = head->val;

            ListNode* curr = dummy;
            while (curr->next && curr->next->val < now) {
                curr = curr->next;
            }
            head->next = curr->next;
            curr->next = head;

            head = head_nxt;
        }

        return dummy->next;
    }
};
