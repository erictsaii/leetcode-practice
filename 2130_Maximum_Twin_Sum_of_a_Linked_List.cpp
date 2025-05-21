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
    int pairSum(ListNode* head) {
        if (head == nullptr) return 0;
        if (head->next->next == nullptr) return head->val + head->next->val;

        // calculate the size of linked list
        int n = 0;
        ListNode *curr = head;
        while (curr->next != nullptr) {
            n++;
            curr = curr->next;
        }

        // traverse to the middle of the linked list
        curr = head;
        for (int i = 0; i < n/2; i++) curr = curr->next;

        // split into two linked list, and reverse the second one
        ListNode *second_head = curr->next;
        curr->next = nullptr;
        ListNode* first = second_head, *second = second_head->next;
        first->next = nullptr;
        while (second->next != nullptr) {
            ListNode* tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }
        second->next = first;

        // calculate the answer
        int ans = 0;
        while (head != nullptr) {
            ans = max(head->val+second->val, ans);
            head = head->next;
            second = second->next;
        }
        return ans;
    }
};