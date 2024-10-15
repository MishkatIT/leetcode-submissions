class Solution {
public:
    long long minimumSteps(string s) {
        int one = 0;
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                one++;
            } else {
                ans += one;
            }
        }
        return ans;
    }
};