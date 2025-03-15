class Solution {
public:
    int minCapability(vector<int>& v, int k) {
        int l = *min_element(v.begin(), v.end()), r = *max_element(v.begin(), v.end()), ans = r;
        while (l <= r) {
            int mid = (l + r) / 2, cnt = 0;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] <= mid) cnt++, i++;
            }
            if (cnt >= k) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};