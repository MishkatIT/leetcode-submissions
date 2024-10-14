class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto& i : nums) {
            pq.push(i);
        }
        long long ans = 0;
        while (k--) {
            int x = pq.top();
            pq.pop();
            ans += x;
            pq.push((x + 2) / 3);
        }
        return ans;
    }
};