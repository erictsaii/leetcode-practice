class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        int cnt=1;
        char prev='A';
        for(auto &c:word){
            if(prev!=c){
                if(cnt>1) ans+=cnt-1;
                prev=c; 
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        if(cnt>1) ans+=cnt-1;
        return ans;
        
    }
};
