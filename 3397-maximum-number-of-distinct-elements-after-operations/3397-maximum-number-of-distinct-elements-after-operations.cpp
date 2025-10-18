class Solution {
public:
    int maxDistinctElements(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int last = -1e9;
        int ans = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int temp = v[i] - k;
            if (temp >= last) {
                last = temp + 1;
                ans++;
            } else {
                if (last <= v[i] + k) {
                    ans++;
                    last++;
                }
            }
        }
        return ans;
    }
};