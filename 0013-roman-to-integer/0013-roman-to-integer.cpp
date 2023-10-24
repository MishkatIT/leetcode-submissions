class Solution {
public:
    int romanToInt(string s) {
        map<char, int> v {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = v[s.back()];
        for (int i = (int)s.length() - 1; i > 0; i--)
        {
            if(v[s[i]] > v[s[i - 1]])
                ans -= v[s[i - 1]];
            else
                ans += v[s[i - 1]];                
        }
        return ans;
    }
};