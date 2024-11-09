class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        --n;
        for (int i = 0, j = 0; i < 64; i++) {
            if ((1LL << i) & x) continue;
            if ((1LL << j) & n) ans |= (1LL << i);
            j++;
        } 
        return ans;
    }
};