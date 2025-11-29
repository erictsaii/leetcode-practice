using ll = long long;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> dis(26, vector<ll>(26, LLONG_MAX/2-1));
        int n = original.size();
        ll a, b, w;
        for (int i = 0; i < 26; i++) {
            dis[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            a = original[i]-'a', b = changed[i]-'a', w = cost[i];
            dis[a][b] = min(dis[a][b], w);
        }

        // floyd warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (dis[source[i]-'a'][target[i]-'a'] == LLONG_MAX/2-1) return -1;
            ans += dis[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
