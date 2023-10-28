class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v;
        for (int i = 0; i < values.size(); i++) {
            v.push_back({values[i], labels[i]});
        }
        sort(v.rbegin(), v.rend());
        vector<int> taken(1e5);
        long long ans = 0;
        for (int i = 0; i < v.size() && numWanted; i++) {
            if(taken[v[i].second] < useLimit) {
                taken[v[i].second]++;
                ans += v[i].first;
                numWanted--;
            }
        }
        return ans;
    }
};