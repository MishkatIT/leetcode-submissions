class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> seen;
        while(n != 1) {
            cout << n << ' ';
            if (seen[n]) return false;
            seen[n] = true;
            n = digsum(n);
        }
        return true;
    }

    int digsum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};