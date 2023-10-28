class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        for (auto& i: nums2) {
            nums1.push_back(i);
        }
        sort(nums1.begin(), nums1.end());
        for (int i = 0; i < nums1.size() - 1; i++) {
            if(nums1[i][0] == nums1[i + 1][0]) {
                nums1[i][1] += nums1[i + 1][1];
                nums1.erase(nums1.begin() + i + 1);
                i--;
            }
        }
        return nums1;
    }
};