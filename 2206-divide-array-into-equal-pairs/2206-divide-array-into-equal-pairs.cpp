class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> f(505);
        for (auto& i : nums) f[i]++;
        bool ok = true;
        for (auto& i : f) ok &= (i % 2 == 0);
        return ok;
    }
};