class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;

        while (p1 < version1.size() || p2 < version2.size()) {
            int val1 = 0, val2 = 0;
            while (p1 < version1.size() && version1[p1] != '.') {
                val1 *= 10;
                val1 += version1[p1] - '0';
                p1++;
            }
            p1++;

            while (p2 < version2.size() && version2[p2] != '.') {
                val2 *= 10;
                val2 += version2[p2] - '0';
                p2++;
            }
            p2++;

            if (val1 < val2) return -1;
            else if (val1 > val2) return 1;
        }

        return 0;
    }
};
