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
    ListNode* ans;
    void reverse_node(ListNode* curr, ListNode* parent) {
        if (curr->next != nullptr) reverse_node(curr->next, curr);
        if (curr->next == nullptr) ans = curr;
        curr->next = parent;
    }
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        reverse_node(head, nullptr);
        return ans;

        // iterative version:
        // ListNode *first = head, *second = head->next;
        // head->next = nullptr;
        // while (second->next != nullptr) {
        //     ListNode *tmp = second->next;
        //     second->next = first;
        //     first = second;
        //     second = tmp;
        // }
        // second->next = first;
        // return second;
    }
};