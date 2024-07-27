class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<pair<char, char>, long long> p;
        for (char i = 'a'; i <= 'z'; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                p[{i, j}] = 1e18;
                p[{j, i}] = 1e18;
            }
        }
        int n = original.size();
        for (int i = 0; i < n; i++) {
            p[{original[i], changed[i]}] = min(p[{original[i], changed[i]}], (long long)cost[i]);
        }
        for (int k = 'a'; k <= 'z'; k++) {
            for (char i = 'a'; i <= 'z'; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    p[{i, j}] = min(p[{i, j}], p[{i, k}] + p[{k, j}]);
                }
            }
        }
        long long ans = 0;
        n = source.size();
        for (int i = 0; i < n; i++) {
            if (source[i] != target[i]) {
                if (p[{source[i], target[i]}] == 1e18) return -1;
                ans += p[{source[i], target[i]}];
            }
        }
        return ans;
    }
};