class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;
        for (int i = 0; i <= 31; i++) {
            carry += (a & (1 << i)) != 0 ;
            carry += (b & (1 << i)) != 0;
            if (carry % 2) {
                ans |= (1 << i);
            }
            carry = (carry > 1);
        }
        return ans;
    }
};