class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (auto& i : gifts) {
            pq.push(i);
        }
        while (k > 0) {
            --k;
            int top = pq.top();
            pq.pop();
            top = floor(sqrtl(top));
            pq.push(top);
        }
        long long ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};