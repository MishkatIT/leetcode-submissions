class Solution {
public:
    int findComplement(int num) {
        for (int i = 31 - __builtin_clz(num); i >= 0; i--) {
            num ^= (1 << i);
        }
        return num;
    }
};