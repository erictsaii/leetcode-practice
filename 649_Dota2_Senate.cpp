class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radient;
        queue<int> dire;
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radient.push(i);
            else dire.push(i);
        }

        while (radient.size() && dire.size()) {
            if (radient.front() < dire.front())  radient.push(n++);
            else dire.push(n++);
            radient.pop();
            dire.pop();
        }
        
        return (radient.size() > 0) ? "Radiant" : "Dire";
    }
};