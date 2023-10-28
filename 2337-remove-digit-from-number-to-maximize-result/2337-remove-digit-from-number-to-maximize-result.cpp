class Solution {
public:
    string removeDigit(string number, char digit) {
        int len = number.length();
        bool ok = false;
        for (int i = 0; i < len - 1; i++)
        {
            if(number[i] == digit && number[i + 1] > digit)
            {
                ok = true;
                number.erase(number.begin() + i);
                break;
            }
        }
        if(!ok)
        {
            for (int i = len - 1; i >= 0; i--)
            {
                if(number[i] == digit)
                {
                    number.erase(number.begin() + i);
                    break;
                }
            }
        }
        return number;
        
    }
};