class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans;
        for (int i = 0; i < (int)v[0].size(); i++)
        {
            for (int j = 0; j < (int)v.size(); j++)
            {
                if(v[j].size() > 0)
                {
                    if (v[j][i] != v[0][i])
                        return ans;
                        
                }
                else return ans;
            }
            ans.push_back(v[0][i]);
        }
        return ans;
    }
};