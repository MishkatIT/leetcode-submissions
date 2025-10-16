class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> have;
        for (auto& i : nums) {
            i %= value;
            if (i < 0) {
                i += value;
            }
            i %= value;
            have[i]++;
        }
        int mex = 0;
        while (true) {
            int cur = mex % value;
            if (have.count(cur)) {
                have[cur]--;
                if (have[cur] == 0) {
                    have.erase(cur);
                }
                mex++;
            } else break;
        }
        return mex;
    }
};