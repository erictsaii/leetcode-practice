class Solution {
public:
    int countCollisions(string directions) {
        char prev = directions[0];
        int ans = 0;
        int consecutive_R = 0;
        if (prev == 'R') consecutive_R++;

        for (int i = 1; i < directions.size(); i++) {
            if (directions[i] == 'L') {
                if (prev == 'R') {
                    ans += 2;
                    ans += consecutive_R - 1;
                    prev = 'S';
                }
                else if (prev == 'S') {
                    ans += 1;
                    prev = 'S';
                }
                consecutive_R = 0;
            }
            else if (directions[i] == 'R') {
                consecutive_R++;
                prev = 'R';
            }
            else {
                if (prev == 'R') {
                    ans += consecutive_R;
                }
                prev = 'S';
                consecutive_R = 0;
            }
        }
        return ans;
    }
};


// memorize the previous "state"

// previous='R'

// if current == 'L' and prev == 'R': 
//      ans += 2, prev = 'S'
