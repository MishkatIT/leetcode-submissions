class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        bool carry = false;
        while (s.size() > 1) {
            if (s.back() == '1') {
                if (!carry) {
                    ans++;
                    carry = true;
                }
                ans++;
                s.pop_back();
            } else {
                if (s.back() == '0' && carry) {
                    s.back() = '1';
                    carry = false;
                } else {
                    s.pop_back();
                    ans++;
                }
                cout << ans << ' ';
            }
        }
        ans += carry;
        return ans;
    }
};