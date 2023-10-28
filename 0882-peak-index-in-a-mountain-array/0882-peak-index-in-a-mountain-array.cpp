class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(arr[mid] < arr[mid + 1])
                low = mid + 1;
            else if(arr[mid] > arr[mid + 1])
                high = mid - 1;
            else 
                {
                    ans = mid + 1;
                    break;
                }
        }
        return ans;
    }
};