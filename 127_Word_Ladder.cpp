class Solution {
public:
    bool diff_1(string& a, string& b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;
        unordered_map<string, vector<string>> adj;

        for (int i = 0; i < wordList.size(); i++) {
            if (diff_1(beginWord, wordList[i])) {
                adj[beginWord].push_back(wordList[i]);
            }
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i+1; j < wordList.size(); j++) {
                if (diff_1(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        int ans = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string now = q.front();
                q.pop();
                if (now == endWord) return ans;
                for (auto& neighbor : adj[now]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            ans++;
        }

        return 0;
    }
};
