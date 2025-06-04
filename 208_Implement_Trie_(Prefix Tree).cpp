struct Node {
    bool is_word = false;
    unordered_map<char, Node*> next;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* curr = root;

        for (auto& c : word) {
            if (curr->next.find(c) == curr->next.end()) curr->next[c] = new Node;
            curr = curr->next[c];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for (auto& c : word) {
            if (curr->next.find(c) == curr->next.end()) return false;
            curr = curr->next[c];
        }
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for (auto& c : prefix) {
            if (curr->next.find(c) == curr->next.end()) return false;
            curr = curr->next[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
