class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0;
        int n = skill.size();
        for (auto& i : skill) sum += i;
        if (sum % (n / 2) != 0) return -1;
        int avg = sum / (n / 2);
        long long ans = 0;
        map<int, int> have;
        for (auto& i : skill) {
            if (i >= avg) return -1;
            if (have[avg - i]) {
                ans += i * (avg - i);
                have[avg - i]--;
            } else {
                have[i]++;
            }
        }
        for (auto& i : have) {
            if (i.second > 0) return -1;
        }
        return ans;
    }
};