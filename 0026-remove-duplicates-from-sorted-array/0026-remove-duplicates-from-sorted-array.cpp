class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 1;
        int n = nums.size();
        while(r < n) {
            if(nums[l] == nums[r]) r++;
            else {
                l++;
                nums[l] = nums[r];
            }
        }
        return l + 1;
    }
};