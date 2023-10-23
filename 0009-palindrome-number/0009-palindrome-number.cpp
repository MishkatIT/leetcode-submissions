class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        bool ok = true;
        int n = str.size();
        for (int i = 0; i < n / 2; i++) {
            ok &= (str[i] == str[n - i - 1]);
        }
        return ok;
    }
};

/*
    Approach:
    just iterate from the beginning to n / 2 
    and check if the first character is the same as the last character, 
    the second character is the same as the second last character, and so on.

    Don't bother with the odd length of the string :)
    Look at this example: 
    abcba
    length n = 5, so n / 2 = 2 (rounding down from 2.5)
    the loop goes like this,
     (considering 0-based indexing)
    is str[0] == str[4] , yes
    is str[1] == str[3], yes
    loop breaks. 

    you don't need to check the middle one, that is str[2];
    if it is checked then no problem by the way, then it'd be str[2] == str[2] it's comparing with itself :)
    
*/
