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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        // val, from kth list
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, i});
            }
        }

        ListNode* curr = dummy;
        while (!pq.empty()) {
            auto now = pq.top();
            pq.pop();

            curr->next = lists[now.second];
            curr = curr->next;

            lists[now.second] = lists[now.second]->next;
            if (lists[now.second]) {
                pq.push({lists[now.second]->val, now.second});
            }
        }

        return dummy->next;
    }
};
