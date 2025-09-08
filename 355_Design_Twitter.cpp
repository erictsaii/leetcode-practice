class Twitter {
public:
    class User {
    public:
        vector<pair<int, int>> tweets; // tweetId, time
        unordered_set<int> following;
    };

    unordered_map<int, User> user_map;
    unordered_map<int, int> tweetId_to_userId;

    int time = 0;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        user_map[userId].tweets.push_back({tweetId, time++});
        tweetId_to_userId[tweetId] = userId;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // time, tweetId
        unordered_map<int, int> last_idx; // userId, index in their tweets

        last_idx[userId] = user_map[userId].tweets.size() - 1;
        for (auto& f : user_map[userId].following) {
            last_idx[f] = user_map[f].tweets.size() - 1;
        }

        for (auto& x : last_idx) {
            if (x.second >= 0) {
                int tweetId = user_map[x.first].tweets[x.second].first;
                int time = user_map[x.first].tweets[x.second].second;
                pq.push({time, tweetId});
                x.second--;
            }
        }

        vector<int> result;

        while (!pq.empty() && result.size() < 10) {
            int tweetId = pq.top().second;
            pq.pop();
            result.push_back(tweetId);

            int tweet_owner = tweetId_to_userId[tweetId];
            int idx = last_idx[tweet_owner];
            if (idx >= 0) {
                int next_tweetId = user_map[tweet_owner].tweets[idx].first;
                int time = user_map[tweet_owner].tweets[idx].second;
                pq.push({time, next_tweetId});
                last_idx[tweet_owner]--;
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        user_map[followerId].following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_map[followerId].following.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
