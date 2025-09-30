class Solution {
public:
    class Node {
    public:
        unordered_map<char, Node*> next;
        int index = -1;
        vector<int> palindromeIndexes;
    };

    bool is_palindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Node* dummy = new Node();
        Node* curr;

        for (int i = 0; i < words.size(); i++) {
            curr = dummy;
            for (int j = words[i].size()-1; j >=0; j--) {
                if (is_palindrome(words[i], 0, j)) curr->palindromeIndexes.push_back(i); // ?
                if (!curr->next.count(words[i][j])) curr->next[words[i][j]] = new Node();
                curr = curr->next[words[i][j]];
            }

            curr->index = i;
            curr->palindromeIndexes.push_back(i);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            curr = dummy;
        
            for (int j = 0; j < words[i].size(); j++) {
                if (curr->index != -1 && curr->index != i && is_palindrome(words[i], j, words[i].size()-1)) {
                    ans.push_back({i, curr->index});
                }
                if (curr->next.count(words[i][j])) curr = curr->next[words[i][j]];
                else {
                    curr = nullptr;
                    break;
                }
            }
            if (!curr) continue;
            for (int idx : curr->palindromeIndexes) {
                if (i != idx) ans.push_back({i, idx});
            }
        }
        return ans;
    }
};

// push all reversed words in trie
