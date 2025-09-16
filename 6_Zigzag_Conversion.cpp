class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> row(numRows);
        int pos = 0;
        int dir = 1;

        for (int i = 0; i < s.size(); i++) {
            row[pos].push_back(s[i]);
            if (dir == 1 && pos == numRows-1) dir = -1;
            if (dir == -1 && pos == 0) dir = 1;
            pos += dir;
        } 

        string ans;
        for (int i = 0; i < numRows; i++) {
            ans.append(row[i]);
        }
        return ans;
    }
};
