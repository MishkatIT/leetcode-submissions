class Solution {
public:
    int myAtoi(string s) {
        string ans;
        bool neg = false, pos = false;
        bool word = false;        
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '-')
                {
                    if(ans.size())
                        break;
                    if(pos || ans.size() || neg)
                        return 0;
                    else    
                        neg = true;
                }
            else if(s[i] == '+')
                {
                    if(ans.size())
                        break;
                    if(neg || ans.size() || pos)
                        return 0;
                    else
                        pos = true;    
                }  
            else if(s[i] == ' ')
                {
                    if(ans.size())
                        break;
                    if(pos || neg)
                        return 0;    
                }    
            else if(s[i] == '.')
                ans.push_back('.');    
            else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z')) 
            {
                word = true;
                if(!ans.size())
                    return 0;
                if(ans.size())
                    break;    
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                if(word)
                    return 0;
                ans.push_back(s[i]);
            }    
        }
        int k;
        for (k = 0; k < ans.length(); k++)
        {
            if(ans[k] != '0')
                break;
        }
        ans = ans.substr(k);
        long long num = 0;
        for (int i = 0; i < ans.length(); i++)
        {
            if(ans[i] == '.')
                break;
            num = num * 10 + (ans[i] - '0');
            if(num > INT_MAX)
            {
                if(neg)
                    return INT_MIN;
                else
                    return INT_MAX;    
            }
        }
        if(neg)
            num *= -1;
        return num;    
    }
};