class Solution {
public:
    int bitwiseComplement(int n) {
        int temp = n;
        int mask = 1;
        while(temp > 1) {
            mask <<= 1;
            mask |= 1;
            temp >>= 1;
        }
        return(~(n) & mask);
    }
};