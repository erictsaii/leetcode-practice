class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq; // char, idx
        string ans;
        int n = s.size();
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], -i});
            }
            else {
                removed[i] = true;
                auto now = pq.top();
                pq.pop();
                removed[-now.second] = true;
            }            
        }

        for (int i = 0; i < n; i++) {
            if (!removed[i]) ans.push_back(s[i]);
        }

        return ans;
    }
};
