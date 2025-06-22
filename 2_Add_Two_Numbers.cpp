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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int num = carry;
            if (l1) num += l1->val;
            if (l2) num += l2->val;
            carry = num / 10;
            num %= 10;
            ListNode* node = new ListNode(num);
            prev->next = node;
            prev = node;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};
