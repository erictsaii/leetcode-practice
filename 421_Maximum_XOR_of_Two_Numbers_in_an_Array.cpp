class Solution {
public:
    class Node {
    public:
        vector<Node*> next;
        Node(){
            next.assign(2, nullptr);
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        Node* dummy = new Node();
        Node* curr;
        
        for (auto& num : nums) {
            curr = dummy;
            for (int i = 31; i >= 0; i--) {
                int bit = (num & (1 << i)) ? 1 : 0;
                if (curr->next[bit] == nullptr) {
                    curr->next[bit] = new Node();
                }
                curr = curr->next[bit];
            }
        }

        int ans = 0;
        for (auto& num : nums) {
            curr = dummy;
            int best_result = 0;
            for (int i = 31; i >= 0; i--) {
                int best_to_go = (num & (1 << i)) ? 0 : 1;
                if (curr->next[best_to_go] != nullptr) {
                    curr = curr->next[best_to_go];
                    best_result |= (best_to_go << i);
                }
                else {
                    curr = curr->next[1-best_to_go];
                    best_result |= ((1-best_to_go) << i);
                }
            }
            ans = max(ans, best_result ^ num);
        }
        return ans;
    }
};

// first, we push all nums(in binary) to trie 
// for every nums[i], we can get its best answer (e.g. 1100 -> 0011)
// we traverse nums, and find its best answer in trie as possible

