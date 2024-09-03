class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; i++) {
            ans += (digSum(i) % 2 == 0);
        }
        return ans;
    }
    int digSum(int n) {
        int sum = 0;
       while (n) {
            sum += (n % 10);
            n /= 10;
       }
       return sum;
    }
};