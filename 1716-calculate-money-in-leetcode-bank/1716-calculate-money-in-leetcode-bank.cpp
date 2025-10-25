class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int divi = n / 7;
        int rem = n % 7;
        ans = divi * (7 * 8) / 2;
        ans += divi * (divi - 1) / 2 * 7;
        for (int i = divi + 1; rem > 0; i++) {
            ans += i;
            rem--;
        }
        return ans;
    }
};

