class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < (int)nums2.size(); i++)
            nums1.push_back(nums2[i]);
        sort(nums1.begin(), nums1.end());
        int sz = nums1.size();
        if(sz & 1)
            return nums1[sz / 2];
        else
            return ((nums1[sz / 2 - 1]+ nums1[sz / 2]) / (double)2);            
    }
};