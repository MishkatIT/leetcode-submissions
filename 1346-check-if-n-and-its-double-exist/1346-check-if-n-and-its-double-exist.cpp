class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> mp;
        for (auto& i : arr) {
            mp[i]++;
        }
        for (auto& i : arr) {
            if (i == 0) {
                if (mp[0] > 1) return true;
            } else if(mp.find(i * 2) != mp.end()) return true;
        }
        return false;
    }
};