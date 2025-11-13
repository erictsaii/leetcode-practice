class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        vector<tuple<int, string, string>> v(k);

        for (int i = 0; i < k; i++) {
            v[i] = {indices[i], sources[i], targets[i]};
        } 
        sort(v.begin(), v.end());

        int idx = 0;
        string ans;
        for (int i = 0; i < k; i++) {
            while (idx < s.size() && idx < get<0>(v[i])) {
                ans.push_back(s[idx]);
                idx++;
            }

            if (idx != get<0>(v[i])) continue;

            if (s.substr(idx, get<1>(v[i]).size()) == get<1>(v[i])) {
                ans.append(get<2>(v[i]));
                idx += get<1>(v[i]).size();
            }
        }
        while (idx < s.size()) {
            ans.push_back(s[idx]);
            idx++;
        }
        return ans;
    }
};
