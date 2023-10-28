class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int sz = 1e5 + 10;
        int temp [sz];
        memset(temp, 0, sizeof(temp));
        for(auto& i: nums) {
            temp[i]++;
        }
        vector<int> ans;    
        for (int i = 0; i < sz; i++) {
            if(temp[i] >= 2) {
                ans.push_back(i);
            }
        }
        return ans;                
    }
};