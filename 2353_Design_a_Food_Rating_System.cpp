class FoodRatings {
public:
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>>> cuisine_to_pq;
    unordered_map<string, int> rating; // food_name, rating
    unordered_map<string, string> food_to_cuisine;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            rating[foods[i]] = -ratings[i];
            cuisine_to_pq[cuisines[i]].push({-ratings[i], foods[i]});
            food_to_cuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        rating[food] = -newRating;
        cuisine_to_pq[food_to_cuisine[food]].push({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        while (rating[cuisine_to_pq[cuisine].top().second] != cuisine_to_pq[cuisine].top().first) {
            cuisine_to_pq[cuisine].pop();
        }
        return cuisine_to_pq[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
