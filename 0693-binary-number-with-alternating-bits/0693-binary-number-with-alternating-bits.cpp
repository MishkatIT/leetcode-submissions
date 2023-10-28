class Solution {
public:
    bool hasAlternatingBits(int n) {
        int current = -1;
        while(n)
        {
            if(n & 1)
            {
                if(current == 1)
                    return false;
                current = 1;    

            }
            else
            {
                if(current == 0)
                    return false;
                current = 0; 
            }
            n >>= 1;
        }
        return true;
    }
};