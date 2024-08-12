class KthLargest {
public:
    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < k && i < nums.size(); i++) {
            this->nums.push_back(nums[i]);
        }
    }
    int add(int val) {
        if (nums.size() < k) {
            nums.push_back(val);
            if (nums.size() == k) {
                sort(nums.rbegin(), nums.rend());
            }
        } else if (val > nums.back()) {
            nums.pop_back();
            nums.push_back(val);
            sort(nums.rbegin(), nums.rend());
        }
        return nums.back();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */