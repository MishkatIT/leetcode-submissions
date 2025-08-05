class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = fruits.size();
        for (auto& i : fruits) {
            for (auto& j : baskets) {
                if (j >= i) {
                    ans--;
                    j = -1;
                    break;
                }
            }
        }
        return ans;
    }
};