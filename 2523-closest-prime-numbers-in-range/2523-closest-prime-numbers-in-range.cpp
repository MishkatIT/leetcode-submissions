class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> all(right + 5, true);
        all[1] = false;
        for (int i = 2; i <= right; i++) {
            if (all[i]) {
                for (int j = i + i; j <= right; j += i) {
                    all[j] = false;
                }
            }
        }
        vector<int> p;
        for (int i = left; i <= right; i++) {
            if (all[i]) p.push_back(i);
        }
        vector<int> ans{-1, -1};
        int dist = 1e9;
        for  (int i = 0; i + 1 < p.size(); i++) {
            if (p[i + 1] - p[i] < dist) {
                dist = p[i + 1] - p[i];
                ans = {p[i], p[i + 1]};
            }
        }
        return ans;
    }
};