class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int p = 1, s = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i] > arr[i + 1]) break;
            p++;
        }
        vector<int> suf = {arr.back()};
        for (int i = n - 2; i > 0; i--) {
            if (arr[i] > arr[i + 1]) break;
            s++;
            suf.push_back(arr[i]);
        }
        reverse(suf.begin(), suf.end());
        for (auto& i : suf) cout << i << ' ';
        int mx = 1;
        int prv = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= prv) {
                prv = arr[i];
                int x = lower_bound(suf.begin(), suf.end(), arr[i]) - suf.begin();
                cout << x << endl;
                mx = max(mx, i + 1 + (int)suf.size() - x);
            } else break;
        }
        if (p == n) return 0;
        return n - max({p, s, mx});
    }
};