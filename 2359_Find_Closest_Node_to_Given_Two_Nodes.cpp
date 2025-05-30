class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> dis_from_node1(n, -1);

        int dis = 0;
        for (int i = node1; i != -1; i = edges[i]) {
            if (visited[i]) break;
            visited[i] = true;
            dis_from_node1[i] = dis++;
        }

        int ans = INT_MAX, maximum = INT_MAX;
        dis = 0;
        visited.assign(n, false);
        for (int i = node2; i != -1; i = edges[i]) {
            if (visited[i]) break;
            visited[i] = true;
            if (dis_from_node1[i] != -1) {
                int curr_maximum = max(dis_from_node1[i], dis);
                if (maximum > curr_maximum || (maximum == curr_maximum && ans > i)) {
                    ans = i;
                    maximum = curr_maximum;
                }
            }

            dis++;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
