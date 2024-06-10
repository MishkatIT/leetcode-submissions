class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = {heights[i], i};
        }
        sort(temp.begin(), temp.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (temp[i].second != i);
        }
        return ans;
    }
};