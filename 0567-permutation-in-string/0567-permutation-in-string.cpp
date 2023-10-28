class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        vector<int> v(26, 0), temp (26, 0);
        for (int i = 0; i < s1.size(); i++) {
                v[s1[i] - 'a']++;
                temp[s2[i] - 'a']++;
        }   
        if(v == temp)
            return true;
        int n = s2.size() - s1.size();
        for (int i = 0; i < n; i++) {
            temp[s2[i] - 'a']--;
            temp[s2[s1.size() + i] - 'a']++;
            if(v == temp)
                return true;    
        }
        return false;    
    }
};