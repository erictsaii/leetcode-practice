class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        int l = 0, r = products.size()-1;
        int n = searchWord.size();
        vector<vector<string>> ans(n);

        for (int i = 0; i < n; i++) {
            while (l<=r && products[l][i] != searchWord[i]) {
                l++;
            }
            while (l<=r && products[r][i] != searchWord[i]) {
                r--;
            }

            for (int j = l; j <= min(l+2, r); j++) {
                ans[i].push_back(products[j]);
            }

        }

        return ans;
    }
};

// solution 2
// 先sort 
// 遍歷searchword的每個char
// 對於每個searchword的prefix 找products，找到後最多加三個進ans

// solution 3
// trie
// 先把search word丟進去
// 對於每種prefix 找到他停在哪個node
// 對那個node做dfs 找3個答案
