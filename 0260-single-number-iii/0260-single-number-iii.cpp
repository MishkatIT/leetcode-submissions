class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        auto Xor = [&](auto v) {
            int x = 0;
            for (auto& i : v) x ^= i;
            return x;
        };

        int x = Xor(nums);
        int pos = 0;
        for (int i = 0; i <= 31; i++) {
            if (x & (1 << i)) {
                pos = i;
                break;
            }
        }
        vector<int> a, b;
        for (auto& i : nums) {
            if (i & (1 << pos)) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        return {Xor(a), Xor(b)};
    }
};