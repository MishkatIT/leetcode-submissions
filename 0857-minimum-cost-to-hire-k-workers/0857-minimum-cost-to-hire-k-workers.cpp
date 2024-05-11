class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratio(n);
        for (int i = 0; i < n; i++) {
            ratio[i] = {wage[i] * 1.0 / quality[i], quality[i]};
        }
        sort(ratio.begin(), ratio.end());
        double ans = 1e9;
        double sum = 0;
        double mx = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(ratio[i].second);
            sum += ratio[i].second;
            mx = max(mx, ratio[i].first);
            if (pq.size() == k) {
                ans = min(ans, sum * mx);
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};