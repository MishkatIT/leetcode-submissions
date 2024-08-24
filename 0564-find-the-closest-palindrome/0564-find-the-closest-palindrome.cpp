using ll = long long;
const ll linf = 1e18;

class Solution {
public:
    string nearestPalindromic(string n) {

        auto pal = [&](ll x) {
            string s = to_string(x);
            int m = (s.size() - 1) / 2;
            for (int i = 0; i <= m; i++) {
                s[s.size() - 1 - i] = s[i];
            }
            return stoll(s);
        };

        ll nn = stoll(n);

        ll left = 0, right = linf;
        ll low = 0, high = nn - 1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll palin = pal(mid);
            if (palin < nn) {
                left = palin;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << left;
        low = nn + 1, high = linf;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll palin = pal(mid);
            if (palin > nn) {
                right = palin;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << right;
        if (abs(nn - left) <= abs(nn - right)) return to_string(left);
        return to_string(right);
    }
};