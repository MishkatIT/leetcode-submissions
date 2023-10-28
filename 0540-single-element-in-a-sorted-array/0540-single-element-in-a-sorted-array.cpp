class Solution {
public:
    int singleNonDuplicate(vector<int>& num) {
        int low = 0;
        int high = num.size() - 1;
        while(low <= high)
        {
            if(low == high)
                return num[low];
            if(high - low == 2)
            {
                if(num[low] == num[low + 1])
                    return num[low + 2];
                else
                    return num[low];    
            }
            if(high - low == 1)
            {
                if(low == 0)
                    return num[low];
                else if(high == num.size() - 1)
                    return num[high];  
                else if(num[low - 1] == num[low])
                    return num[high];
                else
                    return num[low];              
            }
            int mid = low + (high - low) / 2;
            if(mid & 1)
            {
                if(num[mid - 1] == num[mid])
                    low = mid + 1;
                else if(num[mid] == num[mid + 1])
                    high = mid - 1;
            else
                return num[mid]; 
            }
            else
            {
                if(num[mid] == num[mid + 1])
                    low = mid + 1;
                else if(num[mid - 1] == num[mid])
                    high = mid - 1;
                else
                    return num[mid]; 
            }     
        }
        return num[0];
    }
};