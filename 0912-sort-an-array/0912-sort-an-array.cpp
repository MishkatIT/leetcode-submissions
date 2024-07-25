class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        srt(nums, temp, 0, nums.size() - 1);
        return nums;
    }

private:
    void srt(vector<int>& v, vector<int>& temp, int s, int e) {
        if (s >= e) return;
        int mid = s + (e - s) / 2;
        srt(v, temp, s, mid);
        srt(v, temp, mid + 1, e);
        merge(v, temp, s, mid, e);
    }

    void merge(vector<int>& v, vector<int>& temp, int s, int mid, int e) {
        int i = s, j = mid + 1, k = s;
        while (i <= mid && j <= e) {
            if (v[i] <= v[j]) {
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = v[i++];
        }
        while (j <= e) {
            temp[k++] = v[j++];
        }
        for (int l = s; l <= e; ++l) {
            v[l] = temp[l];
        }
    }
};
