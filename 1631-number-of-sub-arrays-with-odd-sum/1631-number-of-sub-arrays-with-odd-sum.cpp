class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int psum = 0, mod = 1e9 + 7;
        int odd = 0, even = 1;
        for(auto& i: arr) {
            psum += i;
            if(psum & 1)
                odd++;
            else
                even++;   
        }
        return (odd % mod * (long long)even % mod) % mod;     
    }
};