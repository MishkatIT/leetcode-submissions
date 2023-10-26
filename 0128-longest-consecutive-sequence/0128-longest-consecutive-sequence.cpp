class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!(nums.size()))
            return 0;    
        priority_queue<int>pq;
        for(auto& i: nums)
            pq.push(i);
        int temp, ans = 1, tempAns = 1;  
        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            if(temp - 1 == pq.top())
                {
                    tempAns++;
                    ans = max(ans, tempAns);
                }
            else if(temp == pq.top())
                continue;    
           else
                tempAns = 1;  
        }
        return ans;

    }
};