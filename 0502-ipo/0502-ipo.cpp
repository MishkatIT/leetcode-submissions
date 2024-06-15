class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<pair<int, int>> v(n); // capital, profit
        for (int i = 0; i < n; i++) {
            v[i] = {capital[i], profits[i]};
        }
        sort(v.begin(), v.end());
        int j = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            while (j < n && v[j].first <= w) {
                pq.push(v[j].second);
                j++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};