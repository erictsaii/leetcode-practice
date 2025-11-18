class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n == 1) return true;
        if (bits[n-2] != 1 || bits[n-1] != 0) return true;

        for (int i = 0; i < n-2; i++) {
            if (bits[i]) {
                if (i+1 >= n-2) return true;
                i++;
            }
        }    
        return false;
    }
};

// a = 0
// b = 10 or 11


// equals to: if we remove the last "10", would it still be a valid string?

// how to verify a string?
