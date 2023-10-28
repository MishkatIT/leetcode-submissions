class Solution {
public:
    int alternateDigitSum(int n) {
         string str = to_string(n);
    int sum = 0;
    int toogle = -1;
    for (auto& i: str) {
        sum += (i - '0') * -1 * toogle;
        toogle *= -1;
    }
    return sum;
        
    }
};