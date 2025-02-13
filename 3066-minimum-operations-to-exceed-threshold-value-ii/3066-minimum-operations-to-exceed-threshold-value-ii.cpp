class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto& i : nums) pq.push(i);
        int cnt = 0;
        while (pq.top() < k) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(1LL * min(a, b) * 2 + max(a, b));
            cnt++;
        }
        return cnt;
    }
};