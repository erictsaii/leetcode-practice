class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, left, right;
        for (int i = 0; i < flowerbed.size(); i++) {
            left = max(i-1, 0);
            right = min(i+1, (int)flowerbed.size()-1);
            if (flowerbed[left]==0 && flowerbed[right]==0 && flowerbed[i]==0) {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        return cnt >= n;
    }
};