class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return srt(nums, 0, (int)nums.size() - 1);
    }

    vector<int> srt(vector<int>& v, int s, int e) {
        if (s == e) return {v[s]};
        int mid = (s + e) / 2;
        vector<int> left = srt(v, s, mid);
        vector<int> right = srt(v, mid + 1, e);
        vector<int> temp;
        int i = 0, j = 0;
        while (i < (int)left.size() && j < (int)right.size()) {
            if (left[i] <= right[j]) {
                temp.push_back(left[i++]);
            } else {
                temp.push_back(right[j++]);
            }
        }
        while (i < (int)left.size()) {
            temp.push_back(left[i++]);
        }
        while (j < (int)right.size()) {
            temp.push_back(right[j++]);
        }
        return temp;
    }
};