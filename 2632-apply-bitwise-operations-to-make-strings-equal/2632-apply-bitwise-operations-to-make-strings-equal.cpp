class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s == target)
            return true;
        int cntzero = 0;
        cntzero = count(target.begin(), target.end(), '0');
        if(cntzero == (int)target.length())
            return false;
        cntzero = 0;
        cntzero = count(s.begin(), s.end(), '0');
        if(cntzero == (int)s.length())
            return false;
        return true;
        
    }
};