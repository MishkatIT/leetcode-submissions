class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> f(1010);
        for (auto& i : arr1) {
            f[i]++;
        }
        vector<int> ans;
        for (auto& i : arr2) {
            while(f[i]) {
                ans.push_back(i);
                f[i]--;
            }
        }
        for (int i = 0; i <= 1000; i++) {
            while(f[i]) {
                ans.push_back(i);
                f[i]--;
            }
        }
        return ans;
    }
};