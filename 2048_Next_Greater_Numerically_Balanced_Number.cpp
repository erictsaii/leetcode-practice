class Solution {
public:
    bool is_balanced(int n) {
        vector<int> v(10, 0);
        while (n) {
            v[n%10]++;
            n /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (v[i] && v[i] != i) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        while (1) {
            n++;
            if (is_balanced(n)) return n;
        }
        return 0; // not reach
    }
};

// 1000000

// 1 22 122 212 221 
