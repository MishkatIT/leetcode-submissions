class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // solving by using Boyer-Moore Majority Voting Algorithm
        int n = nums.size();
        int cnt = 0;
        int curIdx = 0;
        for (int i = 0; i < n; i++) {
            if(nums[i] != nums[curIdx]) {
                cnt--;
            } else {
                cnt++;
            }
            
            if(cnt == 0) {
                curIdx = i;
                cnt++;
            }
        }
       
        return nums[curIdx];
    }
};