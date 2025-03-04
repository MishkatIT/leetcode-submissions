class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<array<int, 2>> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());

        int x = 0;
        while (x < n && temp[x][0] != pivot) x++;

        auto cmp = [&](auto& a, auto& b) {
            return a[1] < b[1];
        };

        sort(temp.begin(), temp.begin() + x, cmp);
        while (x < n && temp[x][0] == pivot) x++;
        sort(temp.begin() + x, temp.end(), cmp);
        vector<int> ans;
        for (auto& i : temp) ans.push_back(i[0]);
        return ans;
    }
};