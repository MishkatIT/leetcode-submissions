    class Solution {
    public:
        int reverse(long long x) {
        string str;
        str = to_string(x);
        string s;
        s = str;
        for(int i = 0; i < s.length(); i++)
        {
            str[i] = s[str.length() - 1 - i];
        }
        if(str.back() == '-')
            {
                str.insert(str.begin(), '-');
                str.pop_back();
            }
        while(str[0] == '0')
            str.erase(str.begin());
        if(!str.size())
            return 0;    
        long long temp = stoll(str);
        if(temp > INT_MAX || temp < INT_MIN)
            return 0;    
        return stoi(str);
            
        }
    };