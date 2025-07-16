class WordDictionary {
public:
struct Node {
    bool is_word;
    unordered_map<char, Node*> next;
};
    Node *head;
    WordDictionary() {
        head = new Node();
        head->is_word = false;
    }
    
    void addWord(string word) {
        Node* curr = head;
        for (auto& c : word) {
            if (curr->next.find(c) == curr->next.end()) {
                curr->next[c] = new Node();
            }
            curr = curr->next[c];
        }
        curr->is_word = true;
    }

    bool dfs(Node* root, string& word, int idx) {
        Node *curr = root;
        
        for (int i = idx; i < word.size(); i++) {
            if (word[i] == '.') {
                for (auto& nxt : curr->next) {
                    if (dfs(nxt.second, word, i+1)) return true;
                }
                return false;
            }
            else {
                if (curr->next.find(word[i]) == curr->next.end()) return false;
                curr = curr->next[word[i]];
            }
        }
        
        return curr->is_word;
    }
    
    bool search(string word) {
        return dfs(head, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
