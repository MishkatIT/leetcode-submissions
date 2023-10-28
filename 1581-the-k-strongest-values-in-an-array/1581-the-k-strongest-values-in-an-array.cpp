class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) / 2];
        sort(arr.begin(), arr.end(), [&](int a, int b){
            if (abs(a - m) == abs(b - m)) return a > b;
            return abs(a - m) > abs(b - m);
        });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};