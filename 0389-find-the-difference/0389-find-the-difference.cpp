class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int>mp;
        for (auto& i: s){
            mp[i]++;
        }
        char ans;
        for (auto& i: t){
            if(mp[i])
                mp[i]--;
            else{
                ans = i;
                break;
            }
        }
        return ans;
    }
};