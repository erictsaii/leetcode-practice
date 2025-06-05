class Solution {
public:
    vector<int> parent;

    int find(int n) {
        if (parent[n] == -1) return n;
        return parent[n] = find(parent[n]);
    }

    void join(int n1, int n2) {
        int root1 = find(n1);
        int root2 = find(n2);
        if (root1 == root2) return;
        else if (root1 < root2) parent[root2] = root1;
        else parent[root1] = root2;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.assign(26, -1);

        for (int i = 0; i < s1.size(); i++) {
            join(s1[i]-'a', s2[i]-'a');
        }

        string ans(baseStr.size(), ' ');

        for (int i = 0; i < baseStr.size(); i++) {
            ans[i] = find(baseStr[i] - 'a') + 'a';
        }

        return ans;
    }
};

// a==c, b==d, c==e
