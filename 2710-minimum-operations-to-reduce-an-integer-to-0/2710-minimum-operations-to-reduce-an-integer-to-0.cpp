class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n) {
            int pw = round(log(n) / log(2));
            n = abs(n - pow(2, pw));
            ans++;
        }
        return ans;
    }
};