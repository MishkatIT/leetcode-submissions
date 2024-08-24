/* Approach : Binary Search
We need to find nearest palindrome.
It can be on right side or left side.
1. Binary search for nearest right side palindrome
2. Binary search for nearest left side palindrome
3. Whichever has smaller difference, return that.
We can convert mid to palindrome by mirroring first half.
Time : O(len(n) * log(10^18))
Space : O(len(n))
*/

class Solution {
public:
    #define LL long long
    // Convert to palindrome keeping first half constant.
    LL convertToPalindrome(LL& num) {
        string s = to_string(num);   // convert to string
        int n = s.length();
        int halfn = (n - 1) / 2;
        for(int i=0; i<=halfn; i++) // mirror 1st half to create palindrome
            s[n-1-i] = s[i];
        return stoll(s);            // convert to long long
    }

    // Find the previous palindrome, just smaller than n.
    LL previousPalindrome(LL num) {
        LL l = 0, r = num - 1;
        LL ans = 0;
        while (l <= r) {
            LL mid = l + (r - l) / 2;
            LL palin = convertToPalindrome(mid);
            if (palin < num) {
                ans = palin;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    // Find the next palindrome, just greater than n.
    LL nextPalindrome(LL num) {
        LL l = num + 1, r = 1e18;
        LL ans = 0;
        while (l <= r) {
            LL mid = l + (r - l) / 2;
            LL palin = convertToPalindrome(mid);
            if (palin > num) {
                ans = palin;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    string nearestPalindromic(string n) {
        LL num = stoll(n);
        LL nextP = nextPalindrome(num);
        LL prevP = previousPalindrome(num);
        if (abs(prevP - num) <= abs(nextP - num))
            return to_string(prevP);
        return to_string(nextP);
    }
};