class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, int> indegree;
            unordered_map<string, vector<string>> adj;
    
            for (int i = 0; i < recipes.size(); i++) {
                for (int j = 0; j < ingredients[i].size(); j++) {
                    adj[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
    
            queue<string> q;
            vector<string> ans;
    
            for (auto &s : supplies) {
                q.push(s);
            }
    
            while(!q.empty()) {
                string now = q.front();
                q.pop();
                for (auto neighbor : adj[now]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        ans.push_back(neighbor);
                        q.push(neighbor);
                    }
                }
            }
    
            return ans;
        }
    };
    