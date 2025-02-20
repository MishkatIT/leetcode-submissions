class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> mp(nums.begin(), nums.end());
        
        for (int i = 0; i < (1 << n); i++) {
            string temp = bitset<16>(i).to_string().substr(16 - n);  
            if (mp.find(temp) == mp.end()) return temp;
        }
        return "";
    }
};
