class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * k * m > n) return -1;
        int low = 1, high = 1e9;
        int ans = 1;
        while (low <= high) {
            int cnt = 0;
            int mid = low + (high - low) / 2;
            deque<int> dq;
            int last = 0;
            for (int i = 0; i < n; i++) {
                while (!dq.empty() && bloomDay[dq.back()] < bloomDay[i]) dq.pop_back();
                dq.push_back(i);
                if (dq.front() <= i - k) dq.pop_front();
                if (dq.back() - last + 1 >= k) {
                    if (bloomDay[dq.front()] <= mid) {
                        cnt++;
                        dq.clear();
                        last = i + 1;
                    } 
                }
            }
            if (cnt >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};