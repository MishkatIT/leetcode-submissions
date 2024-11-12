class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        auto cmp = [&](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        sort(items.begin(), items.end(), cmp);
        int n = items.size();
        vector<int> mx(n);
        mx[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            mx[i] = max(mx[i - 1], items[i][1]);
        }
        vector<int> ans(queries.size()); 
        for (int i = 0; i < queries.size(); i++) {
            vector<int> temp = {queries[i], 1000000000};
            int it = upper_bound(items.begin(), items.end(), temp) - items.begin() - 1;
            if (it < 0) {
                ans[i] = 0;
            } else {
                ans[i] = mx[it];
            }
        }
        return ans;
    }
};