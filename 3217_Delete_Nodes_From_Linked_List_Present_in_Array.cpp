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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        for (auto& num : nums) s.insert(num);

        while (curr->next) {
            if (s.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

// using a set to store num in nums
// create a dummy node for simplicity
