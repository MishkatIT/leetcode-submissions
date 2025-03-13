class Solution {
public:
    long countOfSubstrings(string w, int k) {
        int n = w.size(), l = 0, r = 0, cnt = 0, nxt = n;
        long ans = 0;
        map<char, int> f;
        vector<int> nxtC(n);
        
        auto isV = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
        
        for (int i = n - 1; i >= 0; i--) {
            nxtC[i] = nxt;
            if (!isV(w[i])) nxt = i;
        }
        while (r < n) {
            if (isV(w[r])) f[w[r]]++;
            else cnt++;
            while (cnt > k) {
                if (isV(w[l])) {
                    if (--f[w[l]] == 0) f.erase(w[l]);
                } else cnt--;
                l++;
            }
            while (f.size() == 5 && cnt == k) {
                ans += (nxtC[r] - r);
                if (isV(w[l])) {
                    if (--f[w[l]] == 0) f.erase(w[l]);
                } else cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
