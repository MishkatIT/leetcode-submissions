class Solution {
public:
    int maximumProduct(vector<int>& v) {
        int sz = v.size();
        sort(v.begin(), v.end());
        return (max((v[0] * v[1] * v[sz - 1]), (v[sz - 1] * v[sz - 2] * v[sz - 3])));
    }
};