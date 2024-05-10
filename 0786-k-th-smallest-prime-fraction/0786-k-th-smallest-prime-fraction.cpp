class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            pq.push({double(-arr[i]) / arr[n - 1], {i, n - 1}});
        }
        while (k > 1) {
            k--;
            auto top = pq.top();
            pq.pop();
            
            int i = top.second.first;
            int j = top.second.second;
            
            if (j - 1 > i) {
                pq.push({double(-arr[i]) / arr[j - 1], {i, j - 1}});
            }
        }
        
        auto top = pq.top();
        return {arr[top.second.first], arr[top.second.second]};
    }
};
