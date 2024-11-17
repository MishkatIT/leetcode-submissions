class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
          int n = nums.size();
        deque<int> dq;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int minLength = n + 1;
        for (int i = 0; i <= n; i++) {
            // Remove elements from deque if they satisfy the condition
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }
            // Remove elements from the back if the current prefix is smaller
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
    }
    return minLength == n + 1 ? -1 : minLength;

    }
};