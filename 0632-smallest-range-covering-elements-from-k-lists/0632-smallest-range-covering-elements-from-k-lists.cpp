struct node {
    int val, listNo, idx;
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        auto cmp = [&](auto a, auto b) {
            return a.val < b.val;
        };

        multiset<node, decltype(cmp)> s(cmp); // val, list number, index of value in that list
        for (int i = 0; i < nums.size(); i++) {
            s.insert({nums[i][0], i, 0});
        }
        int l = s.begin()->val, r = s.rbegin()->val;
        while (true) {
            if (s.rbegin()->val - s.begin()->val < r - l) {
                l = s.begin()->val;
                r = s.rbegin()->val;
            }
            int a = s.begin()-> listNo, b = s.begin()->idx;
            s.erase(s.begin());
            b++;
            if (b < nums[a].size()) {
                s.insert({nums[a][b], a, b});
            } else {
                break;
            }
        }
        return {l, r};
    }
};