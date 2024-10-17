class Solution {
public:
    int maximumSwap(int num) {
        string x;
        x = to_string(num);
        int n = x.size();
        for (int i = 0; i < n; i++) {
            int mx = i;
            for (int j = i + 1; j < n; j++) {
                if (x[j] >= x[mx]) {
                    mx = j;
                }
            }
            if (x[mx] != x[i]) {
                swap(x[i], x[mx]);
                break;
            }
        }
        return stoi(x);
    }
};