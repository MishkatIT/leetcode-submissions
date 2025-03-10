class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> st;
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && st.top().first >= prices[i]) {
                prices[st.top().second] -= prices[i];
                st.pop();
            }
            st.push({prices[i], i});
        }
        return prices;
    }
};