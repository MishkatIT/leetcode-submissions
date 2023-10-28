class Solution {
public:
    bool isPerfectSquare(int n) {
        //using binary search
        int low = 1;
        int high = n;
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long temp = mid * mid;
            if(temp > n)
                high = mid - 1;
            else if(temp < n)
                low = mid + 1;    
            else
                return true;    
        }
        return false;
    }
};