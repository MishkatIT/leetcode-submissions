class Solution {
public:

    bool ok (string x, int tot, int i) {
        if (tot == 0 && i == x.size()) return true;
        if (i == x.size()) return false;
        string cur;
        bool f = false;
        while (i < x.size()) {
            cur += x[i++];
            f |= ok(x, tot - stoi(cur), i);
        }
        return f;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (ok(to_string(i * i), i, 0)) {
                sum += i * i;
            }
        }
        return sum;
    }
};