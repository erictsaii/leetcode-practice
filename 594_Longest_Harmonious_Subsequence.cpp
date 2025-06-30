class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for(auto& i : nums) m[i]++;
        int prev=INT_MAX;
        int prev_cnt=0;
        int ans=0;
        for(auto& mi:m){
            if(prev==INT_MAX){
                prev=mi.first;
                prev_cnt=mi.second;
                continue;
            }
            if(mi.first-prev==1){
                ans=max(ans,prev_cnt+mi.second);
            }
            prev =mi.first;
            prev_cnt=mi.second;
        }
        return ans;
    }
};
