class Solution {
public:
    static bool cmp(const vector<string>& a, const vector<string>& b) {
        if (a[1] != b[1]) return stoi(a[1]) < stoi(b[1]);
        return a[0] == "OFFLINE";
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), cmp);

        vector<int> ans(numberOfUsers, 0);
        int all_mention = 0;

        unordered_set<int> online;
        for (int i = 0; i < numberOfUsers; i++) online.insert(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> offline; // online_timestamp, id

        for (auto& event : events) {
            int curr_time = stoi(event[1]);
            while (offline.size() && offline.top().first <= curr_time) {
                online.insert(offline.top().second);
                offline.pop();
            }

            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    all_mention++;
                }
                else if (event[2] == "HERE") {
                    for (auto& id : online) {
                        ans[id]++;
                    }
                }
                else {
                    int pos = 0;
                    string tmp;
                    while (pos < event[2].size()) {
                        if (isdigit(event[2][pos])) tmp.push_back(event[2][pos]);
                        else if (event[2][pos] == ' ') {
                            ans[stoi(tmp)]++;
                            tmp = "";
                        }
                        pos++;
                    }
                    ans[stoi(tmp)]++;
                }
            }
            else { // offline
                int id = stoi(event[2]);
                online.erase(id);
                offline.push({curr_time+60, id});
            }
        }

        for (int i = 0; i < numberOfUsers; i++) {
            ans[i] += all_mention;
        }
        return ans;
    }
};


// sort first
