class Solution {
public:
    string convertToBase7(int num) {
        bool ok = false;
        if(num < 0)
            ok = true;
        num = abs(num);            
        string ans;
        if(num == 0){
                ans.push_back('0');
                return ans;
        }
        while(num){
            string temp = to_string(num % 7);
            ans += temp;
            num /= 7;
        }
        if(ok) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};