class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (auto& i : s) {
            int x = i - 'a' + 1;
            sum += x / 10 + x % 10;
        }
        cout << sum;
        k--;
        while (k-- && sum > 9) {
            int temp = 0;
            while (sum) {
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }
        return sum;
    }
};