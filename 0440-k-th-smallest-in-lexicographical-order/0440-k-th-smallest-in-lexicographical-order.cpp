class Solution {
public:
    int countSteps(int n, long long prefix) {
        long long nextPrefix = prefix + 1;
        int steps = 0;
        while (prefix <= n) {
            steps += min((long long)n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;  // Decrease k to make it zero-indexed
        while (k > 0) {
            int steps = countSteps(n, curr);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};
