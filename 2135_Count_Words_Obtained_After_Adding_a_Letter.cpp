class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        for (auto& w : startWords) {
            sort(w.begin(), w.end());
            s.insert(w);
        }

        int ans = 0;
        for (auto& targetWord : targetWords) {
            sort(targetWord.begin(), targetWord.end());

            string tmp;
            for (int i = 0; i < targetWord.size(); i++) {
                tmp = targetWord.substr(0, i) + targetWord.substr(i+1, targetWord.size()-i-1);
                if (s.count(tmp)) {
                    ans++;
                    break;
                }
            }
            
        }

        return ans;
    }
};


// the order in a string doesn't matter

// for a operation, we must append one char and then rearrange
// we can only do one operation for a string 

// naive: for each targetWord, check for all startWords if it's valid
// O(n^2)

// sort all the string
// push all startWords into set
// for each targetWord, mask one char and find it in the set
// O(nlogn)
