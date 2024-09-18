class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for (auto& i : nums) {
            temp.push_back(to_string(i));
        }

        sort(temp.begin(), temp.end(), [&](auto a, auto b) {
            return a + b > b + a;
        });
        string ans;
        for (auto& i : temp) {
            ans += i;
        }
        while (ans.size() > 1 && ans.front() == '0') ans.erase(ans.begin());
        return ans;
    }
};