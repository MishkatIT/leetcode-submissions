class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> rem;
        int n = arr.size();
        rem[0] = 1e9;
        for (int i = 0; i < n; i++) {
            arr[i] %= k;
            arr[i] = (arr[i] + k) % k;
            if (rem[k - arr[i]]) {
                rem[k - arr[i]]--;
            } else {
                rem[arr[i]]++;
            }
        }
        for (auto& i : rem) {
            if (i.first == 0) continue;
            if (i.second > 0) return false;
        }
        return true;
    }
};