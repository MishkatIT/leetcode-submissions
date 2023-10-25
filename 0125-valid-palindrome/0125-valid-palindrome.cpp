class Solution {
public:
    bool isPalindrome(string str) {
         transform(str.begin(), str.end(), str.begin(), ::tolower);
        for(int i = 0; i < (int)str.length();)
        {
            if(!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= '0' && str[i] <= '9'))
                str.erase(str.begin() + i);  
            else i++;    
        }
       
          for (int i = 0; i < (int)str.length() / 2; i++)
            {
                if(str[i] != str[str.length() - 1 - i])
                    return false;
            }  
            return true;

    }
};