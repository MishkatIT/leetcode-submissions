class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;
        queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if ((int)q.size() && i - q.front() + 1 > k) q.pop();
            int flip = (int)q.size() % 2;
            if (nums[i] == flip) {
                q.push(i);
                ans++; 
            }
        }
        if ((int)q.size() && q.front() > nums.size() - k) return -1;
        return ans;
    }
};